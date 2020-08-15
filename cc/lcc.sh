#!/bin/bash

echo "g++ -g -std=c++11 `ls -t *.cc | head -1`"
g++ -g -std=c++11 `ls -t *.cc | head -1`
