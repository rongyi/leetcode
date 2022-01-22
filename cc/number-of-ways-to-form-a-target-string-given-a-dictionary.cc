// http://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
#include "xxx.hpp"

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    const int m = words[0].size();
    candidate_len_ = m;
    const int n = target.size();
    mod_ = 1e9 + 7;

    dp_ = vector<vector<long long>>(m + 1, vector<long long>(n + 1, -1));
    freq_ = vector<vector<long long>>(m, vector<long long>(26, 0));
    for (auto &w : words) {
      for (int i = 0; i < w.size(); ++i) {
        freq_[i][w[i] - 'a']++;
      }
    }

    return dfs(target, 0, 0);
  }

private:
  // w 在候选词组的位置，并不是指某一个词的序列而是，纵向的看单词的位置
  // t 在目的词的位置
  int dfs(string &target, int w, int t) {
    // 说明产生一个OK的
    if (t >= target.size()) {
      return 1;
    }
    // 说明用完了也没产生一个OK的
    if (w >= candidate_len_) {
      return 0;
    }
    // cache
    auto &ret = dp_[w][t];
    if (ret > -1) {
      return ret;
    }

    // 不取这一位
    // 取这一位
    // 两种情况
    auto cur = target[t] - 'a';
    ret = (dfs(target, w + 1, t) +
           freq_[w][cur] * dfs(target, w + 1, t + 1) % mod_) %
          mod_;

    return ret;
  }

private:
  vector<vector<long long>> dp_;
  vector<vector<long long>> freq_;
  long long candidate_len_;
  long long mod_;
};
