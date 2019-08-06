// http://leetcode.com/problems/clumsy-factorial/description/
#include "xxx.h"

class Solution {
public:
  int clumsy(int N) {
    string ops{"*/+-"};
    int cur_idx = 0;
    deque<int> q;
    q.push_back(N);

    for (int i = N - 1; i >= 1; i--) {
      auto op = ops[cur_idx++ % ops.size()];
      // * / can be directly applied
      // 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
      // 就是把 */先算了，然后形成 a + b -c + d...这样的规律
      int num1 = q.back();
      int calc = 0;
      if (op == '*') {
        calc = num1 * i;
        q.pop_back();
        q.push_back(calc);
      } else if (op == '/') {
        calc = num1 / i;
        q.pop_back();
        q.push_back(calc);
      } else {
        q.push_back(i);
      }
    }
    int ret = q.front();
    q.pop_front();
    bool is_plus = true;
    while (!q.empty()) {
      if (is_plus) {
        ret += q.front();
      } else {
        ret -= q.front();
      }
      q.pop_front();
      is_plus ^= true;
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.clumsy(10);
  cout << ret << endl;
}
