// http://leetcode.com/problems/frog-jump/description/
#include "xxx.h"

class Solution {
public:
  bool canCross(vector<int> &stones, int pos = 0, int k = 0) {
    // The number of stones is less than 1100 so pos will always be less than
    // 2^11 (2048).
    int key = pos | (k << 11);

    if (dp_.count(key) > 0) {
      return dp_[key];
    }
    for (int i = pos + 1; i < stones.size(); ++i) {
      int gap = stones[i] - stones[pos];
      // 为什么有这个判断？
      // 因为序列是递增的
      // 所以小了放过这个元素继续看后面的元素
      if (gap < k - 1) {
        continue;
      }
      // 当前的gap都已经比k + 1大了，后面的元素与当前这块石头的距离只能是更大，所以
      // 后面不用做了，直接返回
      if (gap > k + 1) {
        dp_[key] = false;
        return false;
      }
      // 在条件 k - 1, k, k + 1范围内，继续递归调用
      if (canCross(stones, i, gap)) {
        dp_[key] = true;
        return true;
      }
    }

    dp_[key] = (pos == int(stones.size() - 1));
    return dp_[key];
  }

private:
  unordered_map<int, int> dp_;
};

int main() {
  Solution so;
  vector<int> input{0, 1, 3, 5, 6, 8, 12, 17};
  auto ret = so.canCross(input);
  cout << ret << endl;
}
