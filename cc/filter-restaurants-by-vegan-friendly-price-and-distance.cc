// http://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>> &restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<vector<int>> fr;
    for (auto &cur_rest : restaurants) {
      // need veganFriendly and currrent restaurant is not
      if (veganFriendly && !cur_rest[2]) {
        continue;
      }
      // too expensive!
      if (cur_rest[3] > maxPrice) {
        continue;
      }
      // too far!
      if (cur_rest[4] > maxDistance) {
        continue;
      }
      fr.push_back(cur_rest);
    }

    sort(fr.begin(), fr.end(), [](auto &l1, auto &l2) {
      // first by ratings
      if (l1[1] != l2[1]) {
        return l1[1] > l2[1];
      }
      // then by id
      return l1[0] >= l2[0];
    });

    vector<int> ids;
    for (auto &r : fr) {
      ids.push_back(r[0]);
    }

    return ids;
  }
};
