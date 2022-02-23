#!/bin/bash

echo "file name: $1"
if [[ -f "$1.cc" ]]; then
  gvim $1.cc
else
  touch $1.cc

  echo "// https://leetcode.com/problems/$1/" >> $1.cc
  echo "#include \"xxx.hpp\"" >> $1.cc

  gvim $1.cc
fi
