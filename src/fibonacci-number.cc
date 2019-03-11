// http://leetcode.com/problems/fibonacci-number/description/
#include "xxx.h"

class Solution {
public:
  int fib(int N) {
    if (N == 0) {
      return 0;
    }
    if (N == 1) {
      return 1;
    }
    int ret;
    int first = 0;
    int second = 1;
    for (int i = 2; i <= N; i++) {
      ret = first + second;
      first = second;
      second = ret;
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.fib(3);
  cout << ret << endl;
}
