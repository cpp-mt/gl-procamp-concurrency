#!/bin/sh

set -ex

mkdir -p build
cd build
cmake -G "Unix Makefiles" ..
cmake --build .

rm -f test_detail.xml
./mt_task_gTest --gtest_output=xml || true

TEST_DETAILS_DIR=../test/test_details
mkdir -p $TEST_DETAILS_DIR
cp -f test_detail.xml $TEST_DETAILS_DIR
# chmod +x gtest-hudson.pl
# ./gtest-hudson.pl test_detail.xml test_details
