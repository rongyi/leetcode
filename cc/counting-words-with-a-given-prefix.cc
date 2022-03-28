// https://leetcode.com/problems/counting-words-with-a-given-prefix/
#include "xxx.hpp"

class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int ret = 0;
    int psz = pref.size();
    for (auto &w: words) {
      if (w.size() < psz) {
        continue;
      }
      //slow?
      //if (w.substr(0, psz) == pref) {
        //ret++;
      //}
      // ok
      bool valid = true;
      for (int i = 0; i < psz; ++i) {
        if (w[i] != pref[i]) {
          valid = false;
          break;
        }
      }
      ret += valid;
    }

    return ret;
  }
};
