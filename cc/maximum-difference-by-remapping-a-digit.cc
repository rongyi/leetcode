// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
#include "xxx.hpp"

class Solution {
public:
  int minMaxDifference(int num) {
    string s1 = to_string(num);
    // always change the first one can make value
    // to max and min
    string s2 = s1;
    bool chmax = false;
    char c = '9';
    for (int i = 0; i < s1.size(); i++) {
      // first one not 9
      if (s1[i] != '9') {
        c = s1[i];
        break;
      }
    }

    for (int i = 0; c != '9' && i < s1.size(); i++) {
      if (s1[i] == c) {
        s1[i] = '9';
      }
    }

    int maxnum = stoi(s1);

    c = '0';
    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] != '0') {
        c = s2[i];
        break;
      }
    }
    int minnum = 0;
    for (int i = 0; c != '0' && i < s2.size(); i++) {
      if (s2[i] == c) {
        minnum = minnum * 10 + 0;
      } else {
        minnum = minnum * 10 + (s2[i] - '0');
      }
    }

    return maxnum - minnum;
  }
};
