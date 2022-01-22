// http://leetcode.com/problems/count-unhappy-friends/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨
  int unhappyFriends(int n, vector<vector<int>> &preferences,
                     vector<vector<int>> &pairs) {
    vector<unordered_map<int, int>> prefs(n);
    for (int i = 0; i < n; ++i) {
      int psize = preferences[i].size();
      for (int j = 0; j < psize; ++j) {
        prefs[i][preferences[i][j]] = j;
      }
    }
    vector<int> distance(n);
    for (auto &p : pairs) {
      distance[p[0]] = prefs[p[0]][p[1]];
      distance[p[1]] = prefs[p[1]][p[0]];
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < distance[i]; ++j) {
        // i这个小朋友其实更喜欢x，看看x是不是也更喜欢i，如果是就不开心了
        int x = preferences[i][j];
        for (int k = 0; k < distance[x]; ++k) {
          if (i == preferences[x][k]) {
            ret++;
            j = k = n;
          }
        }
      }
    }

    return ret;
  }
};
