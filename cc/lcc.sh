#!/bin/bash

echo "g++ -g -std=c++17 `ls -t *.cc | head -1`"
g++ -g -std=c++17 `ls -t *.cc | head -1`
# running?
if [[ $OSTYPE == 'darwin'* ]]; then
  lldb a.out
else 
  gdb a.out
fi
