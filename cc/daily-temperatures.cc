// http://leetcode.com/problems/daily-temperatures/description/
#include "xxx.hpp"

class Solution {
public:
  // We compute the result in reverse order. Given temperatures = [73, 74, 75,
  // 71, 69, 72, 76, 73], suppose that we already obtain number of days for i >=
  // 3: res = [?, ?, ?, 2, 1, 1, 0, 0] where ? denotes values to be determined.
  // In order to find the number of days for i = 2, we proceed as follows:

  // Let j = i + 1, i.e., j = 3. If temperatures[i] < temperatures[j], res[i] =
  // 1; Otherwise, temperatures[i] >= temperatures[j]. we examine the value of
  // res[j], which is equal to 2, which means that the most recent day with
  // higher temperature than temperatures[j] in the future is 2 days away. Since
  // temperatures[i] >= temperatures[j], the most recent day with higher
  // temperature than temperatures[i] should be at least 2 days away. Therefore,
  // we can skip some days and arrive directly at day j + res[j]. This process
  // continues until we find higher temperature or we know we should stop as
  // descibed in the third point. If temperatures[j] == 0, we shoud directly set
  // res[i] to 0 since we know we cannot find higher temperature in the future.
  vector<int> dailyTemperatures(vector<int> &t) {
    const int n = t.size();
    vector<int> ret(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      int j = i + 1;
      // 后面这个温度不够高，那么久跳，
      // 怎么跳？一个一个？不，根据后面这个计算好的值来跳，因为中间的数字都不会比它高
      while (j < n && t[j] <= t[i]) {
        if (ret[j] > 0) {
          j += ret[j];
        } else {
          j = n;
        }
      }

      if (j < n) {
        ret[i] = j - i;
      }
    }
    return ret;
  }
};
