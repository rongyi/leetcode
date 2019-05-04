#!/bin/bash

scp `ls -t *.cc | head -1` devk8s:/root/rongyi/leetcode/ && echo "done"
