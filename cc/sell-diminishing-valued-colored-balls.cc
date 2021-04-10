// http://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/
#include "xxx.h"

class Solution {
public:
  int maxProfit(vector<int> &inventory, int orders) {
    // 从大到小
    sort(inventory.rbegin(), inventory.rend());

    const long mod = 1e9 + 7;
    const long n = inventory.size();
    long cur = inventory[0];
    long ret = 0;
    long i = 0;
    while (orders > 0) {
      // 这边的i增加也有点trick，一开始的i停留在cur上，所以
      // 更新cur至下一位数字保证了i也会一直跟进
      while (i < n && inventory[i] == cur) {
        ++i;
      }
      long next = (i == n) ? 0 : inventory[i];
      // 总共有多少个
      long h = cur - next;
      long r = 0;
      long cnt = min((long)orders, i * h);

      // 那个最扁矩形的里面的球太多了，那就要多少行和升下的一个零头r
      if (orders < i * h) {
        h = orders / i;
        r = orders % i;
      }
      long val = cur - h;
      // 等差公式
      // len * (end + start) / 2
      // len = h
      // start = val + 1
      // end = cur
      // 算分数
      // 再注意这个乘以i，代表的是多少个这样的分数，也就是这一行每一个都能拿这个分数
      // 结合这里的图看
      // https://leetcode.com/problems/sell-diminishing-valued-colored-balls/discuss/927560/C%2B%2B-Binary-Answer-or-Sort%2BGreedy
      ret = (ret + (cur + val + 1) * h / 2 * i + val * r) % mod;
      // 算个数，不要搞混了
      orders -= cnt;
      cur = next;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{5, 3, 2, 2, 1};
  cout << so.maxProfit(input, 7) << endl;
}
