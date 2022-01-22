// http://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(vector<int> &target, vector<int> &arr) {
    map<int, int> idx;
    // 因为target里面uniq，所以换成index，这样在arr中来找lis
    for (int i = 0; i < target.size(); ++i) {
      idx[target[i]] = i;
    }
    vector<int> same;
    for (auto &num : arr) {
      if (idx.count(num)) {
        same.push_back(idx[num]);
      }
    }

    return target.size() - lis(same);
  }

public:
  // Longest Increasing Subsequence
  int lis(vector<int> &nums) {
    vector<int> sorted;
    for (auto &num : nums) {
      if (sorted.empty() || sorted.back() < num) {
        sorted.push_back(num);
      } else {
        *lower_bound(sorted.begin(), sorted.end(), num) = num;
      }
    }

    return sorted.size();
  }
};

int main() {
  Solution so;
  vector<int> input{1, 3, 5, 0, 9, 10};
  so.lis(input);
}
