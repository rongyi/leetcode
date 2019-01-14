// https://leetcode.com/problems/soup-servings/description/
#include "xxx.h"
class Solution {
public:
  double soupServings(int N) {
    return N >= 4800 ? 1.0 : f(N, N);
  }

private:
  double f (int a, int b) {
    if (a <= 0 && b <= 0) {
      return 0.5;
    }
    if (a <= 0) {
      return 1.0;
    }
    if (b <= 0) {
      return 0;
    }
    string spoon = to_string(a) + ":" + to_string(b);
    // 递归加缓存
    if (cache_.find(spoon) == cache_.end()) {
      cache_[spoon] = 0.25 * (f(a - 100, b) + f(a - 75, b - 25) + f(a - 50, b - 50) + f(a - 25, b - 75));
    }

    return cache_[spoon];
  }
private:
  unordered_map<string, double> cache_;
};
