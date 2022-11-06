// https://leetcode.com/problems/sort-the-people/
#include "xxx.hpp"

class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    // name is not uniq, we must do a bind first
    vector<pair<string, int>> name_heights;
    for (int i = 0; i < names.size(); ++i) {
      name_heights.push_back({names[i], heights[i]});
    }

    sort(name_heights.begin(), name_heights.end(),
         [](pair<string, int> &l, pair<string, int> &r) {
           return l.second > r.second;
         });

    vector<string> ret;
    for (auto &p : name_heights) {
      ret.push_back(p.first);
    }

    return ret;
  }
};
