// http://leetcode.com/problems/count-number-of-teams/description/
#include "xxx.h"

class Solution {
public:
  // For each soldier, count how many soldiers on the left and right have less
  // and greater ratings.
  // This soldier can form less[left] * greater[right] + greater[left] *
  // less[right] teams.
  int numTeams(vector<int> &rating) {
    const int n = rating.size();
    int ret = 0;
    for (int i = 1; i < n - 1; ++i) {
      int less[2] = {};
      int great[2] = {};
      for (int j = 0; j < n; ++j) {
        if (rating[j] > rating[i]) {
          great[i < j]++;
        }
        if (rating[j] < rating[i]) {
          less[i < j]++;
        }
      }
      ret += less[0] * great[1] + less[1] * great[0];
    }

    return ret;
  }
};
