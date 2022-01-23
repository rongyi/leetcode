// https://leetcode.com/problems/minimum-operations-to-convert-number/
#include "xxx.hpp"

class Solution {
public:
  // bfs, three way: + - ^
  // we find the shortest path
  int minimumOperations(vector<int> &nums, int start, int goal) {
    vector<bool> visited(1001, false);

    queue<int> q;
    q.push(start);

    int layer = -1;
    while (!q.empty()) {
      layer++;

      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        if (cur == goal) {
          return layer;
        }
        if (cur < 0 || cur > 1000 || visited[cur]) {
          continue;
        }
        visited[cur] = true;
        // three modifiction
        // then we try all numbers which is not in visited
        for (auto num : nums) {
          auto n1 = cur + num;
          auto n2 = cur - num;
          auto n3 = cur ^ num;
          q.push(n1);
          q.push(n2);
          q.push(n3);
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution so;

  vector<int> input{2, 8, 16};
  so.minimumOperations(input, 0, 1);
}
