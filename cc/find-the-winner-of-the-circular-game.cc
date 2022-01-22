// http://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
#include "xxx.hpp"

class Solution {
public:
  int findTheWinner(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      q.push(i);
    }

    int cnt = 0;
    while (q.size() >= 2) {
      auto cur_friend = q.front();
      q.pop();
      cnt++;
      if (cnt == k) {
        // cur_friend get out!
        cnt = 0;
      } else {
        // to the end
        q.push(cur_friend);
      }
    }

    return q.front();
  }
};

int main() {
  Solution so;
  so.findTheWinner(5, 2);
}
