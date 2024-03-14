#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    set<vector<int>> seen;
    vector<vector<int>> ret;
    vector<int> cur_seq;
    backtrack(nums, 0, cur_seq, ret, seen);

    return ret;
  }
  void backtrack(vector<int> &nums, int idx, vector<int> &cur_seq,
                 vector<vector<int>> &ret, set<vector<int>> &seen) {
    if (cur_seq.size() > 1 && !seen.count(cur_seq)) {
      ret.push_back(cur_seq);
      seen.insert(cur_seq);
    }
    for (int i = idx; i < nums.size(); i++) {
      if (cur_seq.empty() || nums[i] >= cur_seq[cur_seq.size() - 1]) {
        cur_seq.push_back(nums[i]);
        backtrack(nums, i + 1, cur_seq, ret, seen);
        cur_seq.pop_back();
      }
    }
  }
};
