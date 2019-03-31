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

      // 取了这个节点之后，最终数组只有两种结果
      // 一种是当前节点加上比他大一的那些节点
      // 一种是当前节点加上比他小一的那些节点
      // 所以两种取最大的即可,而且还得注意，如果不存在
      // 当前大1或者小一的，结果是0
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
