// https://leetcode.com/problems/number-of-flowers-in-full-bloom/
#include "xxx.hpp"

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
      vector<int> &persons) {
    vector<int> starts;
    vector<int> ends;
    for (auto &f: flowers) {
      starts.push_back(f[0]);
      ends.push_back(f[1]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    vector<int> ret;
    for (auto &p: persons) {
      int started = upper_bound(starts.begin(), starts.end(), p) - starts.begin();
      int ended = lower_bound(ends.begin(), ends.end(), p)  - ends.begin();
      ret.push_back(started - ended);
    }


    return ret;
  }
};
