// http://leetcode.com/problems/lexicographical-numbers/description/
#include "xxx.h"

class Solution {
public:
  vector<int> lexicalOrderTLE(int n) {
    vector<string> strs;
    for (int i = 1; i <= n; i++) {
      strs.push_back(to_string(i));
    }
    sort(strs.begin(), strs.end());
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
      ret[i] = stoi(strs[i]);
    }

    return ret;
  }
  // https://leetcode.com/problems/lexicographical-numbers/discuss/201218/Very-simple-recursive-Java-solution.
  vector<int> lexicalOrder(int n) {
    vector<int> ret;
    recur(1, n, ret);
    return ret;
  }
private:
  void recur(int begin, int end, vector<int> &ret) {
    if (begin > end) {
      return;
    }

    ret.push_back(begin);
    recur(begin * 10, end, ret);
    if (begin % 10 != 9) {
      recur(begin + 1, end, ret);
    }
  }
};
