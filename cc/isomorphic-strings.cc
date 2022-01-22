// http://leetcode.com/problems/isomorphic-strings/description/
#include "xxx.hpp"

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    return doisIsomorphic(s, t) && doisIsomorphic(t, s);
  }

private:
  bool doisIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    // projection from s ==> t
    unordered_map<char, char> p;
    for (int i = 0; i < s.size(); i++) {
      // construct the project
      if (p.find(s[i]) == p.end()) {
        p[s[i]] = t[i];
      } else {
        if (p[s[i]] != t[i]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  auto ret = so.isIsomorphic("ab", "ba");
  cout << ret << endl;
}
