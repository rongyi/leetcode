// http://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
#include "xxx.hpp"

class Solution {
public:
  string getHappyString(int n, int k) {
    vector<string> ret;
    queue<string> q;
    q.push("a");
    q.push("b");
    q.push("c");
    // what a wonderful loop
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      if (x.size() == n) {
        ret.push_back(x);
      }
      string s1{};
      string s2{};

      if (x.back() == 'a') {
        s1 = x + "b";
        s2 = x + "c";
      } else if (x.back() == 'b') {
        s1 = x + "a";
        s2 = x + "c";
      } else {
        s1 = x + "a";
        s2 = x + "b";
      }
      if (s1.length() <= n) {
        q.push(s1);
      }
      if (s2.length() <= n) {
        q.push(s2);
      }
    }
    if (k - 1 >= ret.size()) {
      return "";
    }

    return ret[k - 1];
  }
};
