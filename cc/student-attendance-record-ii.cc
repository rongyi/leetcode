// http://leetcode.com/problems/student-attendance-record-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/student-attendance-record-ii/discuss/101643/Share-my-O(n)-C%2B%2B-DP-solution-with-thinking-process-and-explanation
  int checkRecord(int n) {
    if (n < 1) {
      return 0;
    }
    if (n == 1) {
      return 3;
    }
    long long m = 1000000007;
    // end with A, P, L
    vector<long long> A(n + 5, 0);
    vector<long long> P(n + 5, 0);
    vector<long long> L(n + 5, 0);

    // initial state
    P[0] = 1;
    L[0] = 1;
    L[1] = 3;
    A[0] = 1;
    A[1] = 2;
    A[2] = 4;

    // P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ≥ 2.
    // L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ≥ 3.
    // A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ≥ 4.
    for (int i = 1; i < n; i++) {
      A[i - 1] %= m;
      P[i - 1] %= m;
      L[i - 1] %= m;

      P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;
      if (i > 1) {
        L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;
      }
      if (i > 2) {
        A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
      }
    }

    return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
  }
};

int main() {
  Solution so;
  auto ret = so.checkRecord(2);
  cout << ret << endl;
}
