// http://leetcode.com/problems/next-greater-element-iii/description/
#include "xxx.hpp"

class Solution {
public:
  int nextGreaterElement(int n) {
    string s = to_string(n);
    string cp = s;
    sort(cp.begin(), cp.end(), [](char &l, char &r) { return l > r; });
    if (cp == s) {
      return -1;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = s.size() - 1; i > 0;) {
      pq.push(s[i]);
      if (s[i] <= s[i - 1]) {
        i--;
      } else {
        // swap
        // find the smallest numer after i - 1 which is bigger than i - 1
        while (!pq.empty() && pq.top() <= s[i - 1]) {
          pq.pop();
        }
        auto d = pq.top();
        int j = s.size() - 1;
        while (s[j] != d) {
          j--;
        }
        swap(s[j], s[i - 1]);
        // sort last
        sort(s.begin() + i, s.end());
        break;
      }
    }
    long long ret = stoll(s);
    if (ret > numeric_limits<int>::max()) {
      return -1;
    }
    return (int)ret;
  }
};

int main() {
  Solution so;
  // cout << so.nextGreaterElement(230241) << endl;
  // cout << so.nextGreaterElement(12222333) << endl;
  cout << so.nextGreaterElement(12443322) << endl;
  // cout << so.nextGreaterElement(12) << endl;
}
