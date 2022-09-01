// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
#include "xxx.hpp"

class Solution {
public:
  bool validPartition(vector<int> &nums) {
    sz_ = nums.size();
    // a cache to save time
    dp_ = vector<int>(sz_, -1);

    return validPartition(nums, 0);
  }

private:
  bool validPartition(vector<int> &nums, int cur) {
    if (cur == sz_) {
      return true;
    }
    if (dp_[cur] != -1) {
      return dp_[cur];
    }
    bool ret = false;
    if (cur + 1 < sz_ && nums[cur] == nums[cur + 1]) {
      ret = validPartition(nums, cur + 2);
    }
    if (ret) {
      dp_[cur] = true;
      return ret;
    }

    if (cur + 2 < sz_ && nums[cur] == nums[cur + 1] &&
        nums[cur] == nums[cur + 2]) {
      ret = validPartition(nums, cur + 3);
    }
    if (ret) {
      dp_[cur] = true;
      return true;
    }
    // then the third case
    if (cur + 2 < sz_) {
      if (nums[cur + 1] == nums[cur] + 1 && nums[cur + 2] == nums[cur] + 2) {
        ret = validPartition(nums, cur + 3);
      }
    }
    dp_[cur] = ret;

    return ret;
  }

private:
  int sz_;
  vector<int> dp_;
};

int main() {
  Solution so;
  vector<int> input{4, 4, 4, 5, 6};
  so.validPartition(input);
}
