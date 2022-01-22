// https://leetcode.com/problems/largest-number-after-mutating-substring/
#include "xxx.hpp"

class Solution {
public:
  // just keep changing if the changed value is bigger than
  // the original value e.g. 0 -> 9
  string maximumNumber(string num, vector<int> &change) {
    bool mutated = false;
    for (int i = 0; i < num.size(); ++i) {
      auto cur = num[i] - '0';
      // must process the equal case
      // equal case is not mutation
      num[i] = '0' + max(cur, change[cur]);
      if (change[cur] < cur && mutated) {
        break;
      }

      mutated |= change[cur] > cur;
    }
    return num;
  }
};

int main() {
  Solution so;
  vector<int> input{9, 8, 5, 0, 3, 6, 4, 2, 6, 8};
  so.maximumNumber("132", input);
}
