// https://leetcode.com/problems/maximum-total-importance-of-roads/
#include "xxx.hpp"

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<long long> degree(n);

    for (auto &edge : roads) {
      degree[edge[0]]++;
      degree[edge[1]]++;
    }
    sort(degree.begin(), degree.end());
    long long sum = 0;
    for (int i = degree.size() - 1; i >= 0; --i) {
      sum += degree[i] * n;
      n--;
    }

    return sum;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
  so.maximumImportance(5, input);
  return 0;
}
