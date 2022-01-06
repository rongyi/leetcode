// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
#include "xxx.h"
class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    int ret = 0;
    vector<int> flat;
    for (auto &row : grid) {
      flat.insert(end(flat), begin(row), end(row));
    }
    nth_element(begin(flat), begin(flat) + flat.size() / 2, end(flat));
    for (int i = 0; i < flat.size(); ++i) {
      if (abs(flat[flat.size() / 2] - flat[i]) % x) {
        return -1;
      }
      ret += abs(flat[flat.size() / 2] - flat[i]) / x;
    }

    return ret;
  }
};

int main() {
  vector<int> input{1, 3, 2, 4, 7, 5};
  nth_element(input.begin(), input.begin() + input.size() - 1, input.end());
  for (auto i : input) {
    cout << i << " ";
  }
  cout << endl;
}
