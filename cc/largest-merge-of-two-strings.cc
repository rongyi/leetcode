// http://leetcode.com/problems/largest-merge-of-two-strings/description/
#include "xxx.hpp"

class Solution {
public:
  string largestMerge(string word1, string word2) {
    const int m = word1.size();
    const int n = word2.size();
    // for current index in word1/word2
    int i = 0;
    int j = 0;

    string ret{};
    // 这判断也太多了
    while (ret.size() < m + n) {
      if (i < m && j < n) {
        if (word1[i] > word2[j]) {
          ret.push_back(word1[i++]);
        } else if (word1[i] < word2[j]) {
          ret.push_back(word2[j++]);
        } else {
          // when equal, we let the next big char expose
          int ci = i;
          int cj = j;
          for (; ci < m && cj < n; ci++, cj++) {
            if (word1[ci] != word2[cj]) {
              break;
            }
          }
          // 走到底都相等，无所谓了，我们随便取一个
          if (ci == m && cj == m) {
            ret.push_back(word1[i++]);
          } else if (ci == m) {
            ret.push_back(word2[j++]);
          } else if (cj == n) {
            ret.push_back(word1[i++]);
          } else {
            // 分出胜负了
            if (word1[ci] > word2[cj]) {
              ret.push_back(word1[i++]);
            } else {
              ret.push_back(word2[j++]);
            }
          }
        }
      } else {
        if (i < m) {
          ret.push_back(word1[i++]);
        }
        if (j < n) {
          ret.push_back(word2[j++]);
        }
      }
    }

    return ret;
  }
};
