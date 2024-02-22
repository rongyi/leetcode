// http://leetcode.com/problems/create-maximum-number/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    vector<int> ret;
    for (int k1 = max(k - n2, 0); k1 <= min(k, n1); ++k1) {
      ret = max(ret, merge(selectK(nums1, k1), selectK(nums2, k - k1)));
    }

    return ret;
  }

  // select k number from nums and preserve the relative order
  vector<int> selectK(vector<int> nums, int k) {
    int drop = nums.size() - k;
    vector<int> ret;
    for (auto num : nums) {
      // if we meet a bigger one and have chance to have this bigger number
      // we take this bigger one, and our drop change decrese as well
      while (!ret.empty() && drop > 0 && ret.back() < num) {
        ret.pop_back();
        drop--;
      }

      ret.push_back(num);
    }
    // if the nums is already decrease order
    // we chop the end out
    ret.resize(k);

    return ret;
  }

  vector<int> merge(vector<int> nums1, vector<int> nums2) {
    vector<int> ret;

    while (nums1.size() + nums2.size()) {
      vector<int> &cur = nums1 > nums2 ? nums1 : nums2;
      ret.push_back(cur[0]);
      cur.erase(cur.begin());
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input1{6, 7};
  vector<int> input2{6, 0, 4};

  auto m = so.merge(input1, input2);
  for (auto i:m) {
	  cout << i << endl;
  }
		 
}
