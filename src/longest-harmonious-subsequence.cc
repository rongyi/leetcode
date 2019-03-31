// http://leetcode.com/problems/longest-harmonious-subsequence/description/
#include "xxx.h"

class Solution {
public:
  int findLHS(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    const int n = nums.size();
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
      count[nums[i]]++;
    }
    // unordered_set<int> visited;

    int ret = 0;
    for (auto cur : nums) {
      // less memory consume
      // 反正后面算也不会算到更大了
      // if (visited.find(cur) != visited.end()) {
      //   continue;
      // }
      // visited.insert(cur);

      int plus = 0;
      int minus = 0;
      if (count.find(cur - 1) != count.end()) {
        minus = count[cur] + count[cur - 1];
      }
      if (count.find(cur + 1) != count.end()) {
        plus = count[cur] + count[cur + 1];
      }
      ret = max(ret, max(minus, plus));

      // we are drop this node
      count[cur]--;
      if (count[cur] == 0) {
        count.erase(count.find(cur));
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 2, 1};
  auto ret = so.findLHS(input);
  cout << ret << endl;
}
