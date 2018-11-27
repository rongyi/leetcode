// http://leetcode.com/problems/create-maximum-number/description/
#include "simpleone.h"

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
  // 在nums数组中取k个数，并且保证有序
  vector<int> selectK(vector<int> nums, int k) {
    int drop = nums.size() - k;
    vector<int> ret;
    for (auto num : nums) {
      while (drop && ret.size() && ret.back() < num) {
        ret.pop_back();
        drop--;
      }
      ret.push_back(num);
    }
    // 如果nums本身就是降序则这里会把整个数组都插入进来，所以这里取前k个值
    ret.resize(k);

    return ret;
  }

  vector<int> merge(vector<int> nums1, vector<int> nums2) {
    vector<int> ret;
    while (nums1.size() + nums2.size()) {
      vector<int> &now = nums1 > nums2 ? nums1 : nums2;
      ret.push_back(now[0]);
      now.erase(now.begin());
    }

    return ret;
  }
};
int main() {
  Solution so;
  vector<int> input{4, 3, 2, 1};

  auto ret = so.maxNumber(input, 2);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
