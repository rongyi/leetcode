// http://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/description/
#include "xxx.h"

class Solution {
public:
  struct State {
    long long mask_ = 0;
    // i表示的是某个段，是batchSize的mod 余数
    // 因为batchsize <= 9 所以这里用5位占一个空间，
    // 8 * 5 == 40位，一个long long 64位足够了
    // 所以打平在这一个一位空间上
    bool empty(int i) const {
      auto x = mask_ >> (i * 5);
      return (x & 0b11111) == 0;
    }

    // value代表的是余这么多的group数量
    void add(int i, long long val) { mask_ += (val << (i * 5)); }
    // mod余i的拿走一个跟别的匹配
    State minus1(int i) const {
      auto ret = *this;
      ret.mask_ -= 1LL << (i * 5);

      return ret;
    }
  };
  int maxHappyGroups(int batchSize, vector<int> &groups) {
    vector<int> cnt(batchSize, 0);
    for (auto x : groups) {
      cnt[x % batchSize]++;
    }
    State state;
    for (int i = 1; i < batchSize; ++i) {
      state.add(i, cnt[i]);
    }

    return dp(0, batchSize, state) + cnt[0];
  }

private:
  int dp(int cur_donut, int n, State cur_state) {
    if (cur_state.mask_ == 0) {
      return 0;
    }
    if (cache_.count(cur_state.mask_)) {
      return cache_[cur_state.mask_];
    }
    auto &ret = cache_[cur_state.mask_];

    for (int i = 1; i < n; ++i) {
      if (!cur_state.empty(i)) {
        ret = max(ret, dp((cur_donut + i) % n, n, cur_state.minus1(i)));
      }
    }

    // 结合前面的挡板，如果state不为0的时候 cur_donut 的时候，产生一个可用组合
    if (cur_donut == 0) {
      ret += 1;
    }

    return ret;
  }

private:
  // numDonut -> State
  unordered_map<long long, int> cache_;
};

int main() {
  Solution so;
  vector<int> input{3, 3, 3};
  auto ret = so.maxHappyGroups(3, input);
  cout << ret << endl;
}
