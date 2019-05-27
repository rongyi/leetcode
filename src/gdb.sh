#!/bin/bash

scp -P 2223 `ls -t *.cc | head -1` devk8s:/root/rongyi/leetcode/ && echo "done"
