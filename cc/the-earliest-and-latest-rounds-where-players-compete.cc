// http://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/
#include "xxx.h"

class Solution {
public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    vector<int> arr(n);
    for (int i = 1; i <= n; ++i) {
      arr[i - 1] = i;
    }
    first_player_ = firstPlayer;
    second_player_ = secondPlayer;

    dfs(arr, 1);

    return {min_round_, max_round_};
  }
private:
  void dfs(vector<int> &arr, int round) {
    if (arr.size() == 1) {
      return;
    }
    int sz = arr.size() / 2;
    //does two player meet?
    for (int i = 0; i < sz; ++i) {
      if (arr[i] == first_player_ && arr[arr.size() - i - 1] == second_player_) {
        min_round_ = min(min_round_, round);
        max_round_ = max(max_round_, round);
        return;
      }
    }
    bool f1 = false;
    bool f2 = false;
    for (auto &n : arr) {
      if (n == first_player_) {
        f1 = true;
      }
      if (n == second_player_) {
        f2 = true;
      }
    }
    // two player not in this combination
    if (!f1 || !f2) {
      return;
    }
    // middle still set in the middle
    vector<int> nextarr(sz + (arr.size()) % 2);
    int m = (1 << sz);
    // try all the winning combination for the left size player
    // 1 win, 0 lose, e.g right side player win
    for (int i = 0; i < m; ++i) {
      int left = 0;
      int right = nextarr.size() - 1;
      // check every bit
      for (int j = 0; j < sz; ++j) {
        // 1: left wing
        if ((1 << j) & i) {
          nextarr[left++] = arr[j];
        } else {
          // 0: right wing
          nextarr[right--] = arr[arr.size() - j - 1];
        }
      }
      // has middle elements?
      if (arr.size() % 2) {
        nextarr[left] = arr[arr.size() / 2];
      }
      dfs(nextarr, round + 1);
    }
  }

private:
  int first_player_;
  int second_player_;
  int min_round_ = numeric_limits<int>::max();
  int max_round_ = 0;
};
