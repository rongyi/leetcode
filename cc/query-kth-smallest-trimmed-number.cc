// https://leetcode.com/problems/query-kth-smallest-trimmed-number/
#include "xxx.hpp"

class Solution {
public:
  vector<int> smallestTrimmedNumbers(vector<string> &nums,
                                     vector<vector<int>> &queries) {
    int sz = nums[0].size();
    vector<int> ret;
    for (auto &q : queries) {
      vector<pair<string, int>> trimed;
      for (int i = 0; i < nums.size(); ++i) {
        trimed.push_back({nums[i].substr(sz - q[1]), i});
      }
      sort(trimed.begin(), trimed.end());
      ret.push_back(trimed[q[0] - 1].second);
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<string> input{"24", "37", "96", "04"};
  vector<vector<int>> input2{{2, 1}, {2, 2}};
  so.smallestTrimmedNumbers(input, input2);
  return 0;
}
