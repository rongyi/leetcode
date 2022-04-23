// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
#include "xxx.hpp"

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k, int i = 0) {
    if (i == piles.size() || k == 0) {
      return 0;
    }
    if (dp_[i][k] == 0) {
      // pick j count at pile i
      for (int j = 0, sum = 0;
           j <= piles[i].size() /* note the equal case, the full selection of
                                   current pile case need one more round*/
           && k - j >= 0;
           ++j) {
        dp_[i][k] = max(dp_[i][k], sum + maxValueOfCoins(piles, k - j, i + 1));
        if (j < piles[i].size()) {
          sum += piles[i][j];
        }
      }
    }
    return dp_[i][k];
  }

private:
  // i pile
  // k pick kth
  int dp_[1001][2001] = {};
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{
      {100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}};
  so.maxValueOfCoins(input, 7);
  return 0;
}
