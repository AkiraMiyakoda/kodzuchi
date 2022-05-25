#!/usr/bin/env python3

# Copyright Akira Miyakoda 2022.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE
# or copy at http://www.boost.org/LICENSE_1_0.txt

import sys
import re
import uuid


def compute_hash1(value):
    return value & 0x7f


def compute_hash2(value, salt):
    return (value ^ (value >> salt)) & 0x7f


def print_table(table, indent1, indent2):
    print(f'{indent1}{{')
    for row in range(0, 16):
        print(f'{indent2}', end='')
        for col in range(0, 8):
            print(f'0x{table[row * 8 + col]:02x},', end='')
            if col != 7:
                print(' ', end='')
        print()
    print(f'{indent1}}},')


if __name__ == '__main__':
    # Read encoding definition from STDIN.

    encoding_name = None
    code_points = [None] * 128
    descriptions = [None] * 128

    source_lines = sys.stdin.readlines()
    for line in source_lines:
        m = re.search(r'index-([0-9a-z-]+).txt', line)
        if m:
            encoding_name = m.group(1).replace('-', '_')

        m = re.search(r'^\s*([0-9]+)\s+0x([0-9A-F]{4})\s+(.+)$', line)
        if m:
            index = int(m.group(1))
            code_points[index] = int(m.group(2), 16)
            descriptions[index] = m.group(3)

    if encoding_name is None:
        print('Encoding name not found.', file=sys.stderr)
        exit(1)

    # Build hash table.

    hash1_lists = {}

    table1 = [None] * 128
    table2 = [None] * 128

    for i in range(128):
        if code_points[i] is None:
            continue

        hash1 = compute_hash1(code_points[i])
        if hash1 not in hash1_lists:
            hash1_lists[hash1] = []
        hash1_lists[hash1].append(i)

    max_duplicates = max([len(hash1_lists[x]) for x in hash1_lists])
    for duplicates in range(max_duplicates, 1, -1):
        for hash1 in [x for x in hash1_lists if len(hash1_lists[x]) == duplicates]:
            hash1_list = hash1_lists[hash1]
            for salt in range(1, 8):
                hash2_list = [compute_hash2(x, salt) for x in hash1_list]
                if len(set(hash2_list)) != len(hash1_list):
                    continue
                if any([table2[x] is not None for x in hash2_list]):
                    continue

                table1[hash1] = 0x80 + salt
                for hash2, index in zip(hash2_list, hash1_list):
                    table2[hash2] = index
                break

            else:
                print('Couldn\'t find a good salt', file=sys.stderr)
                exit(1)

    for hash1 in [x for x in hash1_lists if len(hash1_lists[x]) == 1]:
        hash2 = table2.index(None)
        table1[hash1] = hash2
        table2[hash2] = hash1_lists[hash1][0]

    table1 = [x if x is not None else 0xff for x in table1]
    table2 = [x if x is not None else 0xff for x in table2]

    # Print hash tables in C++.

    indent = ' ' * 4
    guard_macro = 'KOD_' + str(uuid.uuid4()).upper().replace('-', '_')

    print('// Automatically generated file. Don\'t touch this.')
    print()

    print(f'#ifndef {guard_macro}')
    print(f'#define {guard_macro}')
    print()

    print(f'namespace kodzuchi::singlebyte')
    print('{')
    print(f'{indent * 1}constexpr hashtable {encoding_name}_table')
    print(f'{indent * 1}{{')

    print(f'{indent * 2}{{')
    for c, d in zip(code_points, descriptions):
        if c is not None:
            print(f'{indent * 3}0x{c:04x}, // {d}')
        else:
            print(f'{indent * 3}0x0000,')
    print(f'{indent * 2}}},')

    print_table(table1, indent * 2, indent * 3)
    print_table(table2, indent * 2, indent * 3)

    print(f'{indent * 1}}};')

    print('}')

    print()
    print(f'#endif // {guard_macro}')
