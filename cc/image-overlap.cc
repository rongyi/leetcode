// http://leetcode.com/problems/image-overlap/description/
#include "xxx.hpp"

class Solution {
public:
  int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
    const int N = A.size();
    vector<int> la;
    vector<int> lb;
    for (int i = 0; i < N * N; i++) {
      if (A[i / N][i % N] == 1) {
        la.push_back(i / N * 100 + i % N);
      }
    }
    for (int i = 0; i < N * N; i++) {
      if (B[i / N][i % N] == 1) {
        lb.push_back(i / N * 100 + i % N);
      }
    }
    unordered_map<int, int> count;
    for (auto a : la) {
      for (auto b : lb) {
        count[a - b]++;
      }
    }
    int ret = 0;
    for (auto kv : count) {
      ret = max(ret, kv.second);
    }
    return ret;
  }
};
