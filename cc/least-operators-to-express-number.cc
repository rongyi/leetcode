// http://leetcode.com/problems/least-operators-to-express-number/description/
#include "xxx.hpp"

class Solution {
public:
  int leastOpsExpressTarget(int x, int target) {
    // 小了，两种方式
    // 1. 1 + 1 + 1 ... ==> target, 其中 1又可以是 x / x 所以总共是target + target - 1
    //                                           产生1的除有这么多|       |中间的加号
    // 2. x - (1 + 1 ...) == target ==> 1的个数是 x - target, 所以总共是 (x - target) + (x - target) - 1 + 1
    //                                                              产生1的除       中间的加号          |  前面那个减号
    if (target < x) {
      return min(target * 2 - 1, (x - target) * 2);
    }
    // 给的一样
    if (x == target) {
      return 0;
    }

    long long multi = x;
    int numop = 0;
    while (multi  < target) {
      numop++;
      multi *= x;
    }

    if (multi == target) {
      return numop;
    }
    // 此时multi肯定大于 target了
    // x = 7 target = 37
    // 在7和49之间这个可以是7+ 30，或者是49 - 12

    int l = numeric_limits<int>::max();
    int r = numeric_limits<int>::max();

    // 为毛要小于才看，因为我本身求一个target，你给我说
    // 再算一个更大的，然后再加上当前的这些步骤，这不扯吗
    if (multi - target < target) {
      l = leastOpsExpressTarget(x, multi - target) + numop;
    }
    // 退掉一个 * x，所以numop 要减1，在这个基础上用加法
    r = leastOpsExpressTarget(x, target - (multi / x)) + numop - 1;

    return min(l, r) + 1;
  }
};
