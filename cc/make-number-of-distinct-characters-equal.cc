// https://leetcode.com/problems/make-number-of-distinct-characters-equal/
#include "xxx.hpp"

class Solution {
public:
  bool isItPossible(string word1, string word2) {
    map<char, int> cnt1;
    map<char, int> cnt2;
    for (auto &c: word1) {
      cnt1[c]++;
    }
    for (auto &c: word2) {
      cnt2[c]++;
    }
    int sz1 = cnt1.size();
    int sz2 = cnt2.size();
    if (abs(sz1 - sz2) > 2) {
      return false;
    }

    return check(cnt1, cnt2);
  }

private:
  // assume cnt1 is the bigger one
  bool check(map<char, int> &cnt1, map<char, int> &cnt2) {
    int l = cnt1.size();
    int r = cnt2.size();
    for (auto &kv1: cnt1) {
      for (auto &kv2: cnt2) {
        if (kv1.first == kv2.first) {
          if (l == r) {
            return true;
          }
          continue;
        }
        int cpl = l;
        int cpr = r;
        if (kv1.second == 1) {
          cpl--;
        }
        if (kv2.second == 1) {
          cpr--;
        }
        if (!cnt2.count(kv1.first)) {
          cpr++;
        }
        if (!cnt1.count(kv2.first)) {
          cpl++;
        }
        if (cpl == cpr) {
          return true;
        }
      }
    }
    return false;
  }
};

