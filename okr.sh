#!/bin/bash

# deduplicate
# some times also print the cc files
git log --since=4.days --stat |grep '\.cc' |grep -v 'scratch' |awk -F'|' '{print $1}'  |sed -e 's/^  *//' -e 's/  *$//' |sort |uniq

git log --since=4.days --stat |grep '\.cc' |grep -v 'scratch' |awk -F'|' '{print $1}'  |sed -e 's/^  *//' -e 's/  *$//' |sort |uniq  |wc -l
