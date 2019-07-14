// http://leetcode.com/problems/validate-stack-sequences/description/
#include "xxx.h"

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    if (pushed.empty()) {
      return true;
    }
    const int n = pushed.size();
    auto first_out = popped[0];
    stack<int> stk;
    int pushed_index = 0;
    // all uniq
    while (pushed[pushed_index] != first_out) {
      stk.push(pushed[pushed_index]);
      pushed_index++;
    }
    // now pushed[i] == first_out
    int next_push = pushed_index + 1;

    // now check
    for (int i = 1; i < n; i++) {
      // only two conditions: equal to pushed[i]
      // or equal to stack.top()
      // else this is not valid
      auto cur_out = popped[i];

      if (!stk.empty() && cur_out == stk.top()) {
        stk.pop();
      } else if (next_push < n) {
        // 洗澡数，进栈就出去
        if (cur_out == pushed[next_push]) {
          next_push++;
        } else {
          // 有点递归的意思，可以想怎么用递归来做
          while (next_push < n && pushed[next_push] != cur_out) {
            stk.push(pushed[next_push]);
            next_push++;
          }
          // 都push干净了都没找着说明顺序不对了
          if (next_push == n) {
            return false;
          }
          // 抵消i++
          // 还是这个数再来一遍
          i--;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<int> pushed{2, 1, 0};
  vector<int> popped{1, 2, 0};
  so.validateStackSequences(pushed, popped);
}
