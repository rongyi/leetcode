// http://leetcode.com/problems/maximum-swap/description/
#include "xxx.hpp"

class Solution {
public:
  int maximumSwap(int num) {
    string s = to_string(num);
    string cp = s;
    // fast path
    sort(cp.begin(), cp.end(), [](char &a, char &b) { return a > b; });
    if (stoi(cp) == num) {
      return num;
    }

    // 思路： 找到一个升序的地方，然后在升序之后找到最大的最靠后的那个index
    // 然后在升序之前找一个最靠前并小于这个值的，然后交换
    const int n = s.size();
    int pivot = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] < s[i + 1]) {
        pivot = i;
        break;
      }
    }
    char max_after = 0;
    int max_idx = 0;
    // 顺序能保证最大值最靠后
    for (int i = pivot + 1; i < n; i++) {
      max_after = max(max_after, s[i]);
      if (s[i] == max_after) {
        max_idx = i;
      }
    }
    for (int i = 0; i <= pivot; i++) {
      if (s[i] < s[max_idx]) {
        swap(s[i], s[max_idx]);
        break;
      }
    }

    return stoi(s);
  }
};

int main() {
  Solution so;
  auto ret = so.maximumSwap(10909091);
  cout << ret << endl;
}
