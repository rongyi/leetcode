// http://leetcode.com/problems/pyramid-transition-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    unordered_map<string, vector<char>> tris;
    for (auto &s : allowed) {
      tris[s.substr(0, 2)].push_back(s.back());
    }
    return dfs(bottom, tris, 0, "");
  }
private:
  bool dfs(string bottom, unordered_map<string, vector<char>> &tris, int start,
           string next) {
    if (bottom.size() == 1) {
      return true;
    }
    if (start == (int)bottom.size() - 1) {
      return dfs(next, tris, 0, "");
    }
    for (char c : tris[bottom.substr(start, 2)]) {
      if (dfs(bottom, tris, start + 1, next + c)) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  string bottom{"BCD"};
  vector<string> allowed{"BCG", "CDE", "GEA", "FFF"};
  so.pyramidTransition(bottom, allowed);
}
