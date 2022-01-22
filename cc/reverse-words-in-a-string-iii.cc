// http://leetcode.com/problems/reverse-words-in-a-string-iii/description/
#include "xxx.hpp"

class Solution {
public:
  string reverseWords(string s) {
    stringstream ss(s);
    string cur;
    stringstream retss;
    while (getline(ss, cur, ' ')) {
      reverse(cur.begin(), cur.end());
      retss << cur << ' ';
    }

    auto ret = retss.str();
    // the last useless ' '
    ret.pop_back();
    return ret;
  }
};
int main() {
  Solution so;
  so.reverseWords("Let's take LeetCode contest");
}
