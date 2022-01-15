// https://leetcode.com/problems/count-nodes-with-the-highest-score/
#include "xxx.h"

class Solution {

public:
  int countHighestScoreNodes(vector<int> &parents) {
    int sz = parents.size();
    vector<vector<int>> child(sz);
    vector<int> cnt(sz, 1);
    for (int i = 1; i < parents.size(); ++i) {
      child[parents[i]].push_back(i);
    }

    /* TLE version :)
    for (int i = 1; i < sz; ++i) {
      int node = i;

      while (true) {
        node = parents[node];
        if (node == -1) {
          break;
        }
        cnt[node] += 1;
      }
    }*/
    // dfs to eliminate TLE
    calculate(cnt, 0, child);

    // initial case: drop root node
    int max_count = 1;
    long long max_score = 1;
    for (auto &c : child[0]) {
      max_score *= cnt[c];
    }
    // delete each node
    for (int i = 1; i < sz; ++i) {
      int parent_score = cnt[0] - cnt[i];
      // two child score
      long long cur_score = parent_score;
      for (auto &c : child[i]) {
        cur_score *= cnt[c];
      }
      if (cur_score > max_score) {
        max_score = cur_score;
        max_count = 1;
      } else if (cur_score == max_score) {
        max_count++;
      }
      // ignore smaller case
    }

    return max_count;
  }

private:
  int calculate(vector<int> &cnt, int cur, vector<vector<int>> &child) {
    // cnt[cur] += child[cur].size();
    for (auto c : child[cur]) {
      cnt[cur] += calculate(cnt, c, child);
    }

    return cnt[cur];
  }
};

int main() {
  Solution so;
  vector<int> input{-1, 2, 0, 2, 0};
  so.countHighestScoreNodes(input);
}
