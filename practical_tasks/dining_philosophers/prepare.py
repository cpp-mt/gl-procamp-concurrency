#!/usr/bin/env python3

import argparse
import os
import shutil


paths = [
    ['project/dining_philosophers.h', True],
    ['project/dining_philosophers.cpp'],
    ['project/dining_philosophers_mt.cpp', True],
    ['test/dining_philosophers_gTest.cpp', True],
    ['CMakeLists.txt', True],
    ['README.md', True],
]


def copy_paths(paths, src_dir, dst_dir, verbose=True):
    for p in paths:
        src_file = os.path.join(src_dir, p[0])
        dst_file = os.path.join(dst_dir, p[0])

        immutable = len(p) == 2 and p[1]
        if not immutable and os.path.exists(dst_file):
            continue

        dst_sub_dir = os.path.dirname(dst_file)
        if not os.path.isdir(dst_sub_dir):
            os.makedirs(dst_sub_dir)

        if verbose:
            print("copy {}".format(src_file))
            print("  to {}".format(dst_file))

        shutil.copyfile(src_file, dst_file)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument('-s', '--src', required=True, help='source directory')
    parser.add_argument('-d', '--dst', required=True, help='destination directory')
    parser.add_argument('-v', '--verbose', action='store_true', help='verbose mode')

    args = parser.parse_args()

    copy_paths(paths, args.src, args.dst, args.verbose)
