// http://leetcode.com/problems/count-different-palindromic-subsequences/description/
#include "xxx.hpp"

class Solution {
public:
  int countPalindromicSubsequences(string S) {
    if (S.empty()) {
      return 0;
    }

    mod_ = pow(10, 9) + 7;
    s_ = S;
    const int n = S.size();
    // 4 come from here
    // Each character S[i] will be in the set {'a', 'b', 'c', 'd'}
    dp_ = vector<vector<vector<int>>>(
        n, vector<vector<int>>(n, vector<int>(4, -1)));

    int ret = 0;
    for (int i = 0; i < 4; i++) {
      ret = (ret + calculate(0, S.size() - 1, i)) % mod_;
    }

    return ret;
  }

private:
  int calculate(int start, int end, int alpha) {
    if (start > end) {
      return 0;
    }
    if (start == end) {
      if (s_[start] == (alpha + 'a')) {
        return 1;
      }
      return 0;
    }
    if (dp_[start][end][alpha] != -1) {
      return dp_[start][end][alpha];
    }
    int count = 0;
    if (s_[start] == s_[end] && s_[start] == (alpha + 'a')) {
      count = 2;
      for (int i = 0; i < 4; i++) {
        count = (count + calculate(start + 1, end - 1, i)) % mod_;
      }
    } else {
      count = (count + calculate(start, end - 1, alpha)) % mod_;
      count = (count + calculate(start + 1, end, alpha)) % mod_;
      count = (count - calculate(start + 1, end - 1, alpha)) % mod_;
      if (count < 0) {
        count += mod_;
      }
    }

    dp_[start][end][alpha] = count;

    return count;
  }

private:
  string s_;
  vector<vector<vector<int>>> dp_;
  int mod_;
};
