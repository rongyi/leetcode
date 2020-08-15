// http://leetcode.com/problems/numbers-with-repeated-digits/description/
#include "xxx.h"

class Solution {
public:
  int numDupDigitsAtMostN(int N) {
    vector<int> digits;
    for (int i = N + 1; i > 0; i /= 10) {
      digits.push_back(i % 10);
    }
    reverse(digits.begin(), digits.end());
    int ret = 0;
    const int n = digits.size();
    for (int i = 1; i < n; i++) {
      ret += 9 * perm(9, i - 1);
    }

    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
      for (int j = i > 0 ? 0 : 1; j < digits[i]; ++j) {
        if (!visited.count(j)) {
          ret += perm(9 - i, n - i - 1);
        }
      }
      if (visited.count(digits[i])) {
        break;
      }
      visited.insert(digits[i]);
    }

    return N - ret;
  }

private:
  int perm(int m, int n) {
    if (n == 0) {
      return 1;
    }
    return perm(m, n - 1) * (m - n + 1);
  }
};

int main() {
  Solution so;
  so.numDupDigitsAtMostN(199);
}
