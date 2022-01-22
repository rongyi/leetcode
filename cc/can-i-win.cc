// http://leetcode.com/problems/can-i-win/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/can-i-win/discuss/95320/7-liner-C%2B%2B-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // 第一个随便取一个数字就赢了
    if (desiredTotal < 2) {
      return true;
    }
    // 和在所有可取数字之内，那么第一个只要取那个数字就赢了
    if (desiredTotal <= maxChoosableInteger) {
      return true;
    }

    int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    // 怎么取都不够，所以没得玩
    if (desiredTotal > sum) {
      return false;
    }
    // 怎么取都无所谓，谁最后取最后一块谁赢
    if (sum == desiredTotal) {
      return maxChoosableInteger % 2;
    }

    // true赢
    // false输
    unordered_map<int, bool> cache;

    return dfs(maxChoosableInteger, desiredTotal, 0, cache);
  }

private:
  // k每一位上0/1的意义： 1: picked; 0: not picked
  bool dfs(int maxChoosableInteger, int desiredTotal, int k,
           unordered_map<int, bool> &cache) {
    // 看到负数，说明前一步对手那步已经把和超过了或者正好，说明此时输了
    if (desiredTotal <= 0) {
      return false;
    }
    if (cache.count(k)) {
      return cache[k];
    }
    for (int i = 0; i < maxChoosableInteger; ++i) {
      // 该位可取以及对手赢不了
      // 取的数字实际上是 i + 1,因为可取区间是[1, maxChoosableInteger]
      // 所以剩下的数字是 desiredTotal - (i + 1)
      if (!(k & (1 << i)) && !dfs(maxChoosableInteger, desiredTotal - i - 1,
                                  k | (1 << i), cache)) {
        return cache[k] = true;
      }
    }
    return cache[k] = false;
  }
};
