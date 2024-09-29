// http://leetcode.com/problems/validate-stack-sequences/description/
#include "xxx.hpp"
#include <vector>

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int sz = pushed.size();
    int poped_index = 0;
    vector<int> stk;

    for (auto &num : pushed) {
      // push every element first, then compare
      // this will elimnate much if else compare
      // see my rust version
      stk.push_back(num);

      while (!stk.empty() && poped_index < sz &&
             stk.back() == popped[poped_index]) {
        poped_index += 1;
        stk.pop_back();
      }
    }

    return stk.empty();
  }
};

int main() {
  Solution so;
  vector<int> pushed{2, 1, 0};
  vector<int> popped{1, 2, 0};
  so.validateStackSequences(pushed, popped);
}
