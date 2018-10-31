// http://leetcode.com/problems/summary-ranges/description/
#include "simpleone.h"

// 就是概括一下区间，这里的summary时是总结不是和

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    // remember the index
    unordered_map<long long, int> uniq;
    for (int i = 0; i < nums.size(); i++) {
      uniq[nums[i]] = i;
    }
    vector<string> ret;

    for (int i = 0; i < nums.size();) {
      auto cur = nums[i];
      auto u = upperof(cur, uniq);
      if (u == cur) {
        ret.push_back(to_string(cur));
      } else {
        ret.push_back(to_string(cur) + "->" + to_string(u));
      }
      i = uniq[u] + 1;
    }

    return ret;
  }

private:
  // 测试case有放最大值，让你溢出循环酸爽一下，用long long规避
  int upperof(long long i, unordered_map<long long, int> &uniq) {
    long long ret = i;
    while (uniq.find(ret) != uniq.end()) {
      ret++;
    }
    ret--;

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-2147483648,-2147483647,2147483647};
  auto ret = so.summaryRanges(input);
  for (auto s : ret) {
    cout << s << " ";
  }
  cout << endl;
}
