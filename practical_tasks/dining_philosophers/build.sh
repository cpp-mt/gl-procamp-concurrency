#!/bin/sh

if [ -z "$GTEST_DIR" ] ; then
   export GTEST_DIR=~/googletest/googletest
fi
if [ -z "$GMOCK_DIR" ] ; then
   export GMOCK_DIR=~/googletest/googlemock
fi

set +x
mkdir -p build
cd build
echo "run cmake -G \"Unix Makefiles\""
cmake -G "Unix Makefiles" ..
echo "start build"
cmake --build .

if [ $? -eq 0 ] ; then
   echo "start test"
   ./dining_philosophers_gTest
else
   echo "error during previous command, abort..."
fi

cd ..

