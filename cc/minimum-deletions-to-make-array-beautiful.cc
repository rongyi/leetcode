// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
#include "xxx.hpp"

class Solution {
public:
  int minDeletion(vector<int> &nums) {
    int del_count = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1] && (i - del_count) % 2 == 0) {
        del_count++;
      }
    }

    return del_count + (nums.size() - del_count) % 2;
  }
};

// the margin pass
class SolutionRongYi {
public:
  int minDeletion(vector<int> &nums) {
    int sz = nums.size();
    if (sz == 1) {
      return 1;
    }
    list<int> lst(nums.begin(), nums.end());
    auto it = next(lst.begin());
    int first = *lst.begin();
    bool is_first = false;
    int del_count = 0;
    while (it != lst.end()) {
      if (is_first) {
        first = *it;
        is_first = false;
      } else {
        if (*it == first) {
          del_count++;
        } else {
          // we have a pair, make next be the first one
          is_first = true;
        }
      }
      it++;
    }
    int left = sz - del_count;
    if (left & 1) {
      del_count++;
    }

    return del_count;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{0, 6, 6, 1, 8, 7};
  so.minDeletion(input);
  return 0;
}
