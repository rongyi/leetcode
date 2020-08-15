// https://leetcode.com/problems/buddy-strings/description/
#include "xxx.h"
class Solution {
public:
  bool buddyStrings(string A, string B) {
    const int m = A.size();
    const int n = B.size();
    if (m != n) {
      return false;
    }
    if (n < 2) {
      return false;
    }

    int first = -1;
    int second = -1;
    for (int i = 0; i < n; ++i) {
      if (A[i] != B[i]) {
        if (first == -1) {
          first = i;
        } else {
          if (second == -1) {
            second = i;
            continue;
          }
          return false;
        }
      }
    }
    // equal case, when equal, there must exist an even element
    // so we can switch the even char
    if (first == -1 || second == -1) {
      // test even case
      return has_even(A);
    }

    swap(A[first], A[second]);

    return A == B;
  }

private:
  bool has_even(const string &s) {
    const int n = s.size();
    unordered_map<char, int> cnt;
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i]];
    }
    for (auto cur : cnt) {
      if ((cur.second & 1) == 0) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution so;
  auto ret = so.buddyStrings("ab", "ba");
  cout << ret << endl;
}
