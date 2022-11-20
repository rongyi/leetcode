// https://leetcode.com/problems/determine-if-two-events-have-conflict/
#include "xxx.hpp"

class Solution {
public:
  bool haveConflict(vector<string> &event1, vector<string> &event2) {
    vector<int> e1{parse_time(event1[0]), parse_time(event1[1])};
    vector<int> e2{parse_time(event2[0]), parse_time(event2[1])};
    if (e1[1] < e2[0] || e2[1] < e1[0]) {
      return false;
    }
    return true;
  }

private:
  int parse_time(string &s) {
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    int min = (s[3] - '0') * 10 + (s[4] - '0');
    return hour * 60 + min;
  }
};
