// http://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
#include "xxx.h"

class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    set<pair<int, int>> visited;
    int island = 0;
    for (auto &stone : stones) {
      if (visited.find({stone[0], stone[1]}) == visited.end()) {
        island++;
        pair<int, int> cur = {stone[0], stone[1]};
        dfs(stones, visited, cur);
      }
    }
    return stones.size() - island;
  }

private:
  void dfs(vector<vector<int>> &stones, set<pair<int, int>> &visited,
           pair<int, int> &cur) {
    visited.insert(cur);
    for (auto &ns : stones) {
      pair<int, int> next_stone = {ns[0], ns[1]};
      if (visited.find({ns[0], ns[1]}) == visited.end()) {
        if (cur.first == next_stone.first || cur.second == next_stone.second) {
          dfs(stones, visited, next_stone);
        }
      }
    }
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  auto ret = so.removeStones(input);
  cout << ret << endl;
}
