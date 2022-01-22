// http://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/
#include "xxx.hpp"

class FindSumPairs {
public:
  FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
    swap(nums1, nums1_);
    swap(nums2, nums2_);
    sort(nums1_.begin(), nums1_.end());

    for (auto &n : nums2_) {
      count_[n]++;
    }
  }

  void add(int index, int val) {
    --count_[nums2_[index]];
    nums2_[index] += val;
    ++count_[nums2_[index]];
  }

  int count(int tot) {
    int ret = 0;
    for (int i = 0; i < nums1_.size() && nums1_[i] < tot; ++i) {
      auto it = count_.find(tot - nums1_[i]);
      if (it != count_.end()) {
        ret += it->second;
      }
    }

    return ret;
  }

private:
  vector<int> nums1_;
  vector<int> nums2_;
  map<int, int> count_;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
