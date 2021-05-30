// http://leetcode.com/problems/maximum-erasure-value/description/
#include "xxx.h"

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    const int n = nums.size();
    unordered_set<int> cur_uniq;
    // unordered_map<int, int> count;
    int i = 0;
    int cur_sum = 0;
    int ret = 0;
    for (int j = 0; j < n; ++j) {
      // cur_sum += nums[j];
      // cur_uniq.insert(nums[j]);
      // count[nums[j]]++;
      // while (i < j && (j - i + 1) != cur_uniq.size()) {
      //   cur_sum -= nums[i];
      //   count[nums[i]]--;
      //   if (count[nums[i]] == 0) {
      //     cur_uniq.erase(nums[i]);
      //   }
      //   i++;
      // }
      // ret = max(ret, cur_sum);

      // 或者换一个思路为了能让nums[j]够资格进来，要把前面的对应都剔除掉
      // 这样少用一个map
      while (cur_uniq.find(nums[j]) != cur_uniq.end()) {
        cur_uniq.erase(nums[i]);
        cur_sum -= nums[i];
        i++;
      }
      cur_uniq.insert(nums[j]);
      cur_sum += nums[j];
      ret = max(ret, cur_sum);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{4, 2, 4, 5, 6};
  cout << so.maximumUniqueSubarray(input) << endl;
}
