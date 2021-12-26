#!/bin/bash

echo "file name: $1"

touch $1.cc

echo "// https://leetcode.com/problems/$1/" >> $1.cc
echo "#include \"xxx.h\"" >> $1.cc

gvim $1.cc
