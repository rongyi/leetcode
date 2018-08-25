// http://leetcode.com/problems/number-of-matching-subsequences/description/
#include "one.h"
class Solution {
public:
  int numMatchingSubseq(string S, vector<string>& words) {
    unordered_set<string> in;
    unordered_set<string> out;

    const int m = S.size();
    int ret = 0;
    for (auto w : words) {
      if (in.find(w) != in.end()) {
        ++ret;
        continue;
      }
      if (out.find(w) != out.end()) {
        continue;
      }
      // fresh new word to be checked
      const int n = w.size();
      int i = 0;
      int j = 0;
      while (i < m && j < n) {
        // 如果相等，就比较w中的下一个
        if (S[i] == w[j]) {
          j++;
        }
        // 每次都递增S序列，意思是不等就看S序列的下一个和当前值是否相等。
        i++;
      }
      if (j == n) {
        ++ret;
        in.insert(w);
      } else {
        out.insert(w);
      }
    }
    return ret;
  }

};
