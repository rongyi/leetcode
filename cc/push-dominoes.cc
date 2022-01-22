// http://leetcode.com/problems/push-dominoes/description/
#include "xxx.hpp"

class Solution {
public:
  string pushDominoes(string s) {
    const int n = s.size();
    int r = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        // ....L case
        if (r == -1) {
          int j = i - 1;
          while (j >= 0 && s[j] == '.') {
            s[j] = 'L';
            j--;
          }
        } else {
          // R .... L case
          int start = r + 1;
          int end = i - 1;
          while (start < end) {
            s[start] = 'R';
            s[end] = 'L';
            start++;
            end--;
          }
          r = -1;
        }

      } else if (s[i] == 'R') {
        if (r != -1) {
          // R....R case
          int j = i - 1;
          while (j > r && s[j] == '.') {
            s[j] = 'R';
            j--;
          }
        }
        r = i;
      }
    }

    // R.... case
    if (r != -1) {
      int j = r + 1;
      while (j < n && s[j] == '.') {
        s[j] = 'R';
        j++;
      }
    }
    return s;
  }
};

int main() {
  Solution so;
  auto ret = so.pushDominoes("L.....RR.RL.....L.R.");
  cout << ret << endl;
}
