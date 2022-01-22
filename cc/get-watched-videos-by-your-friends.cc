// http://leetcode.com/problems/get-watched-videos-by-your-friends/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &friends, int id,
                                        int level) {
    unordered_set<int> visited{id};
    vector<int> q1{id};

    vector<string> ret;
    while (level-- > 0) {
      vector<int> q2;
      for (auto &f : q1) {
        for (auto next : friends[f]) {
          if (visited.insert(next).second) {
            q2.push_back(next);
          }
        }
      }

      swap(q1, q2);
    }
    unordered_map<string, int> freq;
    for (auto &id : q1) {
      for (auto &mov : watchedVideos[id]) {
        ++freq[mov];
      }
    }

    // can not use map, will lost same count movie
    set<pair<int, string>> sorted;
    for (auto &kv : freq) {
      sorted.insert({kv.second, kv.first});
    }
    for (auto &p : sorted) {
      ret.push_back(p.second);
    }

    return ret;
  }
};
