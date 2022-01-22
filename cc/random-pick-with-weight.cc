// http://leetcode.com/problems/random-pick-with-weight/description/
#include "xxx.hpp"

class Solution {
public:
  Solution(vector<int> w) {
    for (int i = 0; i < w.size(); i++) {
      sum_.push_back(sum_.empty() ? w[i] : sum_.back() + w[i]);
    }
    total_ = sum_.back();
  }

  int pickIndex() {
    int r = rand() % total_;
    auto it = upper_bound(sum_.begin(), sum_.end(), r);
    return it - sum_.begin();
  }

private:
  vector<int> sum_;
  int total_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
