// http://leetcode.com/problems/keys-and-rooms/description/
#include "xxx.hpp"

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (visited.find(cur) == visited.end()) {
        visited.insert(cur);
        if (visited.size() == rooms.size()) {
          return true;
        }
        for (auto key : rooms[cur]) {
          if (visited.find(key) == visited.end()) {
            q.push(key);
          }
        }
      }
    }
    return visited.size() == rooms.size();
  }
};
