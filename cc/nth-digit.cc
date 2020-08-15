// http://leetcode.com/problems/nth-digit/description/
#include "xxx.h"

class Solution {
public:
  int findNthDigit(int n) {
    // number with 1 digits: 1,2,3,..,9 ==>9 in total
    // number with 2 digits: 10,11,...,99 ==> 90 in total
    // number with 3 digits: 100,101,...,999 ==> 900 in total
    // .....
    // number with b digits: 10^b,10^b+1,...,10^(b+1)-1 ==> 9*10^b in total
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
    // 找到对应那个数 ，应该是从  n - (sum + 1) 推导过来, sum + 1 调到第一个 a位数上来。 n减从而算出了offset。
    // a == 2时
    // 6 7 8 9  1   0  1  1  1  2 1  3 序列
    // 6 7 8 9  10  11 12 13 14 15...  n的值
    // (n - (sum + 1) ) / a ==> 得到落在那个数字上
    // (n - (sum + 1) ) % 1 ==> 得到该位数字的index上。
    long dig = (n - sum - 1) / a;
    // 找到对应那个数的第几位
    int bit = (n - sum - 1) % a;
    long num = long(pow(10, b)) /* 这里和前面计算减一对应其实这里是这n位数开始的第一个数字 比如： 10 */ + dig;
    std::string str = std::to_string(num);
    return str[bit] - '0';
  }
};
int main() {
  Solution so;
  auto n = so.findNthDigit(11);
  cout << n << endl;
}
