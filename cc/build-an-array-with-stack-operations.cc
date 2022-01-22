// http://leetcode.com/problems/build-an-array-with-stack-operations/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨的描述，题目的意思是要在1..=n这个范围构造target数组，
  // 判断在里面就push，不在里面就push/pop
  vector<string> buildArray(vector<int> &target, int n) {
    auto end = target.back();

    vector<string> ret;

    for (int i = 1, j = 0; i <= end; ++i) {
      if (i == target[j]) {
        j++;
        ret.push_back("Push");
      } else {
        ret.push_back("Push");
        ret.push_back("Pop");
      }
    }
    return ret;
  }
};
