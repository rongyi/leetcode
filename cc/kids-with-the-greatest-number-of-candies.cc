// http://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
#include "xxx.hpp"

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    auto peak = *max_element(begin(candies), end(candies));
    vector<bool> ret;
    for (int i = 0; i < candies.size(); ++i) {
      if (candies[i] + extraCandies >= peak) {
        ret.push_back(true);
      } else {
        ret.push_back(false);
      }
    }

    return ret;
  }
};
