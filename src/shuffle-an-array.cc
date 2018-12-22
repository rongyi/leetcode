// http://leetcode.com/problems/shuffle-an-array/description/
#include "xxx.h"

class Solution {
public:
  Solution(vector<int> nums) { origin_ = nums; }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return origin_; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> cp = origin_;
    mt19937_64 g;
    g.seed(random_device()());
    std::shuffle(cp.begin(), cp.end(), g);
    return cp;
  }

private:
  vector<int> origin_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
