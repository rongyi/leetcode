// http://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
#include "xxx.hpp"

class Solution {
public:
  int findKthNumberMLE(int n, int k) {
    vector<int> ret;
    recur(1, n, ret, k);
    return ret.back();
  }

  // https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/discuss/92259/C%2B%2B-3ms-solution-using-stack
  // Test the prefix of the answer each time. If the total number of current
  // prefix is less than k, test the next prefix with current prefix +1,
  // otherwise test longer prefix with current prefix * 10
  int findKthNumber(int n, int k) {
    int cur = 1;
    while (k > 0) {
      if (1 == k)
        return cur;
      int sum = calc(n, cur);
      if (k > sum) {
        k -= sum;
        cur = cur + 1;
      } else {
        k--;
        cur = cur * 10;
      }
    }
    return cur;
  }

private:
  int calc(int n, uint64_t x) {
    int ans = 0, t = 1;
    while (x <= n) {
      if (x + t - 1 <= n) {
        ans += t;
      } else {
        ans += n - x + 1;
      }
      x *= 10;
      t *= 10;
    }
    return ans;
  }
  void recur(int begin, int end, vector<int> &ret, int k) {
    if (begin > end) {
      return;
    }
    if (k == ret.size()) {
      return;
    }

    ret.push_back(begin);
    recur(begin * 10, end, ret, k);
    if (begin % 10 != 9) {
      recur(begin + 1, end, ret, k);
    }
  }
};

int main() {
  Solution so;
  auto ret = so.findKthNumber(13, 2);
  cout << ret << endl;
}
