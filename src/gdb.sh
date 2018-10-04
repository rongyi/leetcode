#!/bin/bash

scp `ls -t *.cc | head -1` devk8s:/disk1/rongyi/leetcode/src/ && echo "done"
