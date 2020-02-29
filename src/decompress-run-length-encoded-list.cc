// http://leetcode.com/problems/decompress-run-length-encoded-list/description/
#include "xxx.h"

class Solution {
public:
  vector<int> decompressRLElist(vector<int> &nums) {
    vector<int> ret;
    for (int i = 0; i < nums.size(); i += 2) {
      int count = nums[i];
      int num = nums[i + 1];
      vector<int> repeat(count, num);
      ret.insert(ret.end(), repeat.begin(), repeat.end());
    }

    return ret;
  }
};
