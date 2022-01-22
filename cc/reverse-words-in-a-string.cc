// http://leetcode.com/problems/reverse-words-in-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  void reverseWords(string &s) {
    if (s.empty()) {
      return;
    }
    stack<string> stk;

    // trim leading and trailing spaces
    int i = 0;
    int j = s.size() - 1;
    while (s[i] == ' ') {
      i++;
    }
    while (s[j] == ' ') {
      j--;
    }

    int prev = i;
    for (; i < j;) {
      auto cur = s[i];
      if (cur == ' ') {
        stk.push(s.substr(prev, i - prev));
        while (s[i] == ' ') {
          i++;
        }
        prev = i;
      } else {
        i++;
      }
    }
    stk.push(s.substr(prev, j - prev + 1));

    stringstream ss;
    while (!stk.empty()) {
      ss << stk.top() << " ";
      stk.pop();
    }



    auto ret = ss.str();
    ret = ret.substr(0, ret.size() - 1);
    s.replace(s.begin(), s.end(), ret);
  }
};

int main() {
  Solution so;
  string input{"1 "};
  so.reverseWords(input);
  cout << input << endl;
}
