// http://leetcode.com/problems/nth-digit/description/
#include "simpleone.h"

class Solution {
public:
  int findNthDigit(int n) {
    // number with 1 digits: 1,2,3,..,9 9 in total
    // number with 2 digits: 10,11,...,99 90 in total
    // number with 3 digits: 100,101,...,999 900 in total
    // .....
    // number with b digits: 10^b,10^b+1,...,10^(b+1)-1 9*10^b in total
    int a = 1, b = 0;
    long sum = 0;
    // a is the number of digits for that number
    // b is the power of one number
    // sum record the total number digits
    sum += a * (9 * long(pow(10, b)));
    while (sum < n) {
      a++;
      b++;
      sum += a * (9 * long(pow(10, b)));
    }
    // We need to deduce the last part
    sum -= a * (9 * long(pow(10, b)));
    // 找到对应那个数
    long dig = (n - sum - 1) / a;
    // 找到对应那个数的第几位
    int bit = (n - sum - 1) % a;
    long num = long(pow(10, b)) + dig;
    std::string str = std::to_string(num);
    return str[bit] - '0';
  }
};
int main() {
  Solution so;
  auto n = so.findNthDigit(11);
  cout << n << endl;
}
