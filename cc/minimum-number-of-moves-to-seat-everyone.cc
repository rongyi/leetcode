// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
#include "xxx.h"

class Solution {
public:
  int minMovesToSeat(vector<int> &seats, vector<int> &students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int ret = 0;
    for (int i = 0; i < seats.size(); ++i) {
      ret += abs(students[i] - seats[i]);
    }

    return ret;
  }
};
