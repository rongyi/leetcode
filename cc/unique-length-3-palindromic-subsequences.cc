// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
#include "xxx.hpp"

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    // think like this: abcdeaa
    // take left a, right a
    // all the elements in between can be the middle one
    int sz = s.size();
    vector<int> start(26, -1);
    vector<int> end(26, 0);
    vector<int> count(26, 0);
    for (int i = 0; i < sz; ++i) {
      if (start[s[i] - 'a'] == -1) {
        start[s[i] - 'a'] = i;
      }
      end[s[i] - 'a'] = i;
      count[s[i] - 'a']++;
    }

    int ret = 0;
    for (int i = 0; i < 26; ++i) {
      if (count[i] < 2) {
        continue;
      }
      set<char> uniq;

      // just count them, no need to use some prefix trick, shit
      for (int j = start[i] + 1; j < end[i]; ++j) {
        uniq.insert(s[j]);
      }

      ret += uniq.size();
    }

    return ret;
  }
};

int main() {
  Solution so;
  so.countPalindromicSubsequence("aabca");
}
