// https://leetcode.com/problems/total-appeal-of-a-string/
#include "xxx.hpp"

class Solution {
public:
  // so tricky
  // https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996390/JavaC%2B%2BPython-Easy-and-Concise-with-Explanation
  long long appealSum(string s) {
    vector<int> last(26, 0);
    long long ret = 0;

    for (int i = 0; i < s.size(); ++i) {
      last[s[i] - 'a'] = i + 1;
      for (auto cur: last) {
        ret += cur;
      }
    }

    return ret;
  }
};
