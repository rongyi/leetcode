// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
#include "xxx.hpp"

// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/discuss/1674049/Mutual-Favorites
class Solution {
public:
  int maximumInvitations(vector<int> &favs) {
    int sz = favs.size();
    int ret = 0;
    // i is liked by all liked[i] bitches
    vector<vector<int>> like(sz);
    for (int i = 0; i < sz; ++i) {
      if (favs[favs[i]] != i) {
        like[favs[i]].push_back(i);
      }
    }
    for (int i = 0; i < sz; ++i) {
      // put two bitches(they like eachother) together and chain all the one
      // like them at both size, one side at a time
      if (favs[favs[i]] == i) {
        ret += dfs(i, like);
      }
    }

    for (int i = 0; i < sz; ++i) {
      int cnt = 0;
      int j = i;
      // the favorite person is not himself, so there must be a cycle
      for (; visited_[j] == false; j = favs[j]) {
        visited_[j] = true;
        ++cnt;
      }
      // from start point i to cycle point j(second time) total len is cnt
      // and we find the distance from start point i to j(the first time)
      // we get the cycle len;
      // i.e. cnt - dis[i..j];
      for (int k = i; k != j; k = favs[k]) {
        --cnt;
      }
      ret = max(ret, cnt);
    }

    return ret;
  }

private:
  int dfs(int i, vector<vector<int>> &like) {
    visited_[i] = true;
    int ret = 0;
    for (auto cur : like[i]) {
      ret = max(ret, dfs(cur, like));
    }

    return 1 + ret;
  }

private:
  bool visited_[100000] = {};
};
