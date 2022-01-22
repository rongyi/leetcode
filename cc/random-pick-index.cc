// http://leetcode.com/problems/random-pick-index/description/
#include "xxx.hpp"

class Solution {
public:
  Solution(vector<int> nums) {
    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      cache_[nums[i]].push_back(i);
    }

    gen_.seed(std::random_device()());
  }

  int pick(int target) {
    if (cache_.find(target) == cache_.end()) {
      return -1;
    }
    auto curvec = cache_[target];
    if (curvec.size() == 1) {
      return curvec[0];
    }

    uniform_int_distribution<int> distri =
        uniform_int_distribution<int>(0, curvec.size() - 1);
    auto indx = distri(gen_);
    return curvec[indx];
  }

private:
  unordered_map<int, vector<int>> cache_;
  std::mt19937 gen_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
