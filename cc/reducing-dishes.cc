// http://leetcode.com/problems/reducing-dishes/description/
#include "xxx.hpp"

class Solution {
public:
  int maxSatisfaction(vector<int> &satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int sum = 0;
    int result = 0;

    for (int i = satisfaction.size() - 1;
         i >= 0 && satisfaction[i] + result > 0; --i) {
      result += satisfaction[i];
      sum += result;
    }

    return sum;
  }
};
