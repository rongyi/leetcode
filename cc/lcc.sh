#!/bin/bash

echo "g++ -g -std=c++17 `ls -t *.cc | head -1`"
g++ -g -std=c++17 `ls -t *.cc | head -1`
# running?
./a.out
