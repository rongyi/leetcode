// http://leetcode.com/problems/remove-boxes/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
  int removeBoxes(vector<int> &boxes) {
    const int m = boxes.size();
    // dp[i][j][k] : from i to j and the left of i has k elements which have
    // same color with boxes[i]
    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(m, vector<int>(m, 0)));

    return remove(boxes, 0, m - 1, 0, dp);
  }

private:
  int remove(vector<int> &boxes, int i, int j, int k,
             vector<vector<vector<int>>> &dp) {
    if (i > j) {
      return 0;
    }

    // cache hit
    if (dp[i][j][k] > 0) {
      return dp[i][j][k];
    }
    int l_origin = i;
    int k_origin = k;
    // find the clour is same as boxes[i] and make them together to delete
    for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++) {
      ;
    }

    int ret = (k + 1) * (k + 1) + remove(boxes, i + 1, j, 0, dp);
    for (int m = i + 1; m <= j; m++) {
      if (boxes[m] == boxes[i]) {
        ret = max(ret, remove(boxes, m, j, k + 1, dp) +
                           remove(boxes, i + 1, m - 1, 0, dp));
      }
    }

    dp[l_origin][j][k_origin] = ret;

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3};
  so.removeBoxes(input);
}
