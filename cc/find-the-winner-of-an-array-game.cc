// http://leetcode.com/problems/find-the-winner-of-an-array-game/description/
#include "xxx.h"

class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    const int n = arr.size();
    if (k >= n - 1) {
      return *max_element(arr.begin(), arr.end());
    }
    queue<int> q;

    for (int i = 2; i < n; ++i) {
      q.push(arr[i]);
    }
    q.push(min(arr[0], arr[1]));

    int winner = max(arr[0], arr[1]);
    int cur = 1;
    if (cur >= k) {
      return winner;
    }
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      if (winner > top) {
        cur++;
        if (cur >= k) {
          return winner;
        }
        q.push(top);
      } else {
        // old winner to end
        q.push(winner);

        winner = top;
        cur = 1;
      }
    }

    return winner;
  }
};
