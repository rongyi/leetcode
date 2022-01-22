// http://leetcode.com/problems/increasing-subsequences/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(nums, ret, cur, 0);
    return ret;
  }

private:
  void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &cur,
           int pos) {
    if (cur.size() > 1) {
      ret.push_back(cur);
    }
    unordered_set<int> uniq;
    for (int i = pos; i < nums.size(); ++i) {
      if ((cur.empty() || nums[i] >= cur.back()) &&
          (uniq.find(nums[i]) == uniq.end())) {
        cur.push_back(nums[i]);
        dfs(nums, ret, cur, i + 1);
        cur.pop_back();

        // 以 4 6 7 7 举例来说
        // 第一轮走头此时 最后一个 7 弹出，
        // for循环进入下一个，由于是最后一个元素
        // 所以循环结束。再弹倒数第二个 7， 此时for循环进入下一个，也即最后一个
        // 7 如果此时没有uniq的判断，我们还会把 4 6 7(这个7是最后一个7)
        // 加入到结果中 因为之前已经产生了 4 6 7(第一个7)
        // ，所以此时我们不应考虑这个组合，  所以加了个set来去重，
        // 弹出倒数第二个7时，此时将7加入这个uniq
        // set中，后面再遇到这个7
        // 就忽略，有点绕，最好gdb跟踪一下就清楚了
        uniq.insert(nums[i]);
      }
    }
  }
};

int main() {
  Solution so;
  vector<int> input{4, 6, 7, 7};
  auto ret = so.findSubsequences(input);
  for (auto vec : ret) {
    for (auto i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
}
