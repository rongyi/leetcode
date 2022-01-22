// http://leetcode.com/problems/student-attendance-record-i/description/
#include "xxx.hpp"

class Solution {
public:
  bool checkRecord(string s) {
    int num_absent = count(s.begin(), s.end(), 'A');
    if (num_absent > 1) {
      return false;
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L') {
        int j = i;
        while (j < s.size() && s[j] == 'L') {
          j++;
        }
        if (j - i > 2) {
          return false;
        }
      }
    }

    return true;
  }
};
