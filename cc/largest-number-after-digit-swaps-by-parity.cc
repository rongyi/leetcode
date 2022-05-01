// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
#include "xxx.hpp"

class Solution {
public:
  int largestInteger(int num) {
    string s = to_string(num);
    // odd nums
    vector<int> os;
    // even nums
    vector<int> es;

    for (int i = 0; i < s.size(); ++i) {
      if ((s[i] - '0') & 1) {
        os.push_back(s[i] - '0');
      } else {
        es.push_back(s[i] - '0');
      }
    }
    // we can always make two group ordered from big to small
    sort(rbegin(os), rend(os));
    sort(rbegin(es), rend(es));
    string reorder;
    int j = 0;
    int k = 0;
    for (int i = 0; i < s.size(); ++i) {
      if ((s[i] - '0') & 1) {
        reorder.push_back(os[j++] + '0');
      } else {
        reorder.push_back(es[k++] + '0');
      }
    }

    return stoi(reorder);
  }
};
