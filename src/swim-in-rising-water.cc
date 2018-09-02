// https://leetcode.com/problems/swim-in-rising-water/description/
#include "one.h"

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    const int n = grid.size();
    int ret = 0;
    unordered_set<int> visited{};
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    priority_queue<elevation, vector<elevation>, greater<elevation>> q;

    q.push({grid[0][0], 0, 0});
    visited.insert(0);

    while (!q.empty()) {
      auto cur = q.top();
      q.pop();

      ret = max(ret, cur.height_);
      if (cur.i_ == n - 1 && cur.j_ == n - 1) {
        return ret;
      }
      for (auto dir : dirs) {
        int x = cur.i_ + dir[0];
        int y = cur.j_ + dir[1];
        if (x < 0 || x > n - 1 || y < 0 || y > n - 1 ||
            visited.find(x * n + y) != visited.end()) {
          continue;
        }
        visited.insert(x * n + y);
        q.push({grid[x][y], x, y});
      }
    }

    return ret;
  }

private:
  struct elevation {
    int height_;
    int i_;
    int j_;
    bool operator<(elevation other) const { return height_ < other.height_; }
    bool operator>(elevation other) const { return height_ > other.height_; }
  };
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1, 2, 3, 4},
                            {24, 23, 22, 21, 5},
                            {12, 13, 14, 15, 16},
                            {11, 17, 18, 19, 20},
                            {10, 9, 8, 7, 6}};
  auto ret = so.swimInWater(input);
  cout << ret << endl;
}
