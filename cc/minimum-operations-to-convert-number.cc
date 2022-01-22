// https://leetcode.com/problems/minimum-operations-to-convert-number/
#include "xxx.hpp"

class Solution {
public:
  int minimumOperations(vector<int> &nums, int start, int goal) {
    set<int> visited;

    queue<int> q;
    q.push(start);

    int layer = -1;
    visited.insert(start);
    while (!q.empty()) {
      layer++;

      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        if (cur == goal) {
          return layer;
        }
        // three modifiction
        if (cur >= 0 && cur <= 1000) {
          // then we try all numbers which is not in visited
          for (auto num : nums) {
            auto n1 = cur + num;
            auto n2 = cur - num;
            auto n3 = cur ^ num;
            if (!visited.count(n1)) {
              //cout << "1keeeeeep " << n1 << endl;
              visited.insert(n1);
              q.push(n1);
            }
            if (!visited.count(n2)) {
              //cout << "2keeeeeep " << n2 << endl;
              visited.insert(n2);
              q.push(n2);
            }
            if (!visited.count(n3)) {
              //cout << "3keeeeeep " << n3 << endl;
              visited.insert(n3);
              q.push(n3);
            }
          }
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
