#!/bin/bash

set -uxe

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

cd ${DIR}
mkdir -p build
cd build
cmake ..
make
ctest --output-on-failure

