// http://leetcode.com/problems/split-array-into-fibonacci-sequence/description/
#include "xxx.h"

class Solution {
public:
  vector<int> splitIntoFibonacci(string S) {
    vector<int> ret;
    backtracking(S, 0, ret);
    return ret;
  }

private:
  bool backtracking(string &S, int start, vector<int> &ret) {
    if (start >= S.size() && ret.size() >= 3) {
      return true;
    }
    // INT_MAX is 10 digits
    int max_split = (S[start] == '0' ? 1 : 10);

    for (int i = 1; i <= max_split && start + i <= S.size(); i++) {
      long long num = stoll(S.substr(start, i));
      if (num > INT_MAX) {
        continue;
      }
      const int cur_len = ret.size();
      if (cur_len >= 2 &&
          ret[cur_len - 1] + (long long)(ret[cur_len - 2]) != num) {
        continue;
      }

      ret.push_back(num);
      if (backtracking(S, start + i, ret)) {
        return true;
      }
      ret.pop_back();
    }
    return false;
  }
};
