// http://leetcode.com/problems/continuous-subarray-sum/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/continuous-subarray-sum/discuss/99506/Concise-C%2B%2B-solution-use-set-instead-of-map
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_set<int> modk;
    int prev = 0;
    int sum = 0;
    // prev溜的飞起，覆盖了0 这种case以及长度至少为2
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      int delta = k == 0 ? sum : sum % k;
      if (modk.count(delta)) {
        return true;
      }
      modk.insert(prev);
      prev = delta;
    }

    return false;
  }
};

int main() {
  Solution so;
  vector<int> input{23, 2, 4, 6, 7};
  auto ret = so.checkSubarraySum(input, 6);
  cout << ret << endl;
}
