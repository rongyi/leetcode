// http://leetcode.com/problems/majority-element-ii/description/
#include "xxx.h"

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    vector<int> ret{};
    if (nums.empty()) {
      return ret;
    }
    int candi1 = 0;
    int candi2 = 0;
    int count1 = 0;
    int count2 = 0;
    for (auto i : nums) {
      if (i == candi1) {
        count1++;
        continue;
      }
      if (i == candi2) {
        count2++;
        continue;
      }
      if (count1 == 0) {
        candi1 = i;
        count1++;
        continue;
      }
      if (count2 == 0) {
        candi2 = i;
        count2++;
        continue;
      }

      count1--;
      count2--;
    }

    // check again
    count1 = 0;
    count2 = 0;
    for (auto i : nums) {
      if (i == candi1) {
        count1++;
      } else if (i == candi2) {
        count2++;
      }
    }
    if (count1 > nums.size() / 3) {
      ret.push_back(candi1);
    }
    if (count2 > nums.size() / 3) {
      ret.push_back(candi2);
    }

    return ret;
  }
};
