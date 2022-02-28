// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
#include "xxx.hpp"

class Solution {
public:
  int kIncreasing(vector<int> &arr, int k) {
    int sz = arr.size();
    int ret = 0;

    for (int i = 0; i < k; ++i) {
      vector<int> v{arr[i]};
      int len = 1;
      for (int j = i + k; j < sz; j += k) {
        auto it = upper_bound(begin(v), end(v), arr[j]);
        if (it == end(v)) {
          v.push_back(arr[j]);
        } else {
          *it = arr[j];
        }
        ++len;
      }

      ret += len - v.size();
    }

    return ret;
  }
};

int main() {
  vector<int> input{1, 3, 4, 7};
  auto it = upper_bound(input.begin(), input.end(), 5);
  cout << *it << endl;
}
