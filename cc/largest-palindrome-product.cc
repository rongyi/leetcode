// http://leetcode.com/problems/largest-palindrome-product/description/
#include "xxx.hpp"

class Solution {
public:
  int largestPalindrome(int n) {
    if (n == 1) {
      return 9;
    }
    // start and end included
    int start = pow(10, n - 1);
    int end = pow(10, n) - 1;
    // 超过这个数不行
    long max_product = (long)end * end;
    long first_half = max_product / pow(10, n);

    while (first_half >= start) {
      long par = mkpar(first_half);
      for (int i = end; i >= start && par <= max_product && (long)i * (long)i >= par; --i) {
        // 找到一个数， i * j == par
        if (par % i == 0) {
          return par % 1337;
        }
      }

      first_half--;
    }
    return -1;
  }

private:
  long mkpar(int first_half) {
    auto str = to_string(first_half);
    auto pstr = str;
    std::reverse(str.begin(), str.end());
    pstr += str;

    return stol(pstr);
  }
};
int main() {
  Solution so;
  auto ret = so.largestPalindrome(2);
  cout << ret << endl;
}
