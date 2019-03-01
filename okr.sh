#!/bin/bash

git log --since=4.days --stat |grep '\.cc' |grep -v 'scratch' |awk -F'|' '{print $1}' |sort |uniq  |wc -l
