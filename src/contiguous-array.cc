// http://leetcode.com/problems/contiguous-array/description/
#include "xxx.h"

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int sum = 0;
    // sum --> index map
    unordered_map<int, int> sum_index;
    sum_index[0] = -1;
    int ret = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] == 0 ? -1 : 1;
      if (sum_index.find(sum) != sum_index.end()) {
        ret = max(ret, i - sum_index[sum]);
      } else {
        sum_index[sum] = i;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 0, 1};
  auto ret = so.findMaxLength(input);
  cout << ret << endl;
}
