// https://leetcode.com/problems/put-marbles-in-bags/
#include "xxx.hpp"

class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    // fast path
    int sz = weights.size();
    if (sz == k || k == 1) {
      return 0;
    }

    long long max_score = 0;
    long long min_score = 0;
    vector<int> score(sz - 1, 0);
    for (int i = 0; i < sz - 1; i++) {
      // when we put a bar between weights
      // our score will increse weights[i] + weights[i + 1]
      score[i] = weights[i] + weights[i + 1];
    }
    sort(score.begin(), score.end());
    for (int i = 0; i < k - 1; i++) {
      max_score += score[sz - 2 - i];
      min_score += score[i];
    }

    return max_score - min_score;
  }
};
