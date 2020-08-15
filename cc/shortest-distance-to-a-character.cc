// http://leetcode.com/problems/shortest-distance-to-a-character/description/
#include "xxx.h"

class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    const int n = S.size();
    vector<int> index{numeric_limits<int>::max()};
    for (int i = 0; i < n; i++) {
      if (S[i] == C) {
        index.push_back(i);
      }
    }
    index.push_back(numeric_limits<int>::max());
    int i = 1;
    vector<int> ret(n, 0);
    for (int j = 0; j < n; j++) {
      if (j == index[i]) {
        i++;
      } else {
        ret[j] = min(abs(index[i - 1] - j), abs(index[i] - j));
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  so.shortestToChar("loveleetcode", 'e');
}
