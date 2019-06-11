// http://leetcode.com/problems/k-similar-strings/description/
#include "xxx.h"

class Solution {
public:
  int kSimilarity(string A, string B) {
    // swap A ==> B
    for (int i = 0; i < A.size(); i++) {
      if (A[i] == B[i]) {
        continue;
      }
      vector<int> matches;
      for (int j = i + 1; j < A.size(); j++) {
        //     i      j
        // A  A[i]   A[j]
        // B  B[i]   B[j]
        // 不完美的情况，至少要让swap有意义
        // 那就是A[j] 换过来要和B[i]相等 而且原位 A[j] != B[j]
        // 否则换了就零和了
        if (A[j] == B[i] && A[j] != B[j]) {
          matches.push_back(j);
          // 完美的情况，一次swap，能让两个字符归位
          if (A[i] == B[j]) {
            swap(A[i], A[j]);
            return 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1));
          }
        }
      }
      int best = A.size() - 1;
      for (int j : matches) {
        swap(A[i], A[j]);
        best = min(best, 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1)));
        swap(A[i], A[j]);
      }
      return best;
    }
    return 0;
  }
};
