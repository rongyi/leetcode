// https://leetcode.com/problems/most-popular-video-creator/
#include "xxx.hpp"

// shitty problem
class Solution {
public:
  vector<vector<string>> mostPopularCreator(vector<string> &creators,
                                            vector<string> &ids,
                                            vector<int> &views) {
    long long max_view = 0;
    map<string, vector<pair<int, string>>> group;
    map<string, long long> director_views;
    int sz = creators.size();
    for (int i = 0; i < sz; ++i) {
      group[creators[i]].push_back({-views[i], ids[i]});
      director_views[creators[i]] += views[i];
      max_view = max(max_view, director_views[creators[i]]);
    }

    vector<vector<string>> ret;
    for (auto &kv : director_views) {
      if (kv.second == max_view) {
        auto &cur_views = group[kv.first];
        sort(cur_views.begin(), cur_views.end());
        ret.push_back({kv.first, cur_views[0].second});
      }
    }

    return ret;
  }
};
