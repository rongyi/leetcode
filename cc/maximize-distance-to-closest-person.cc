// http://leetcode.com/problems/maximize-distance-to-closest-person/description/
#include "xxx.hpp"

class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    const int n = seats.size();
    vector<int> dist1(n, numeric_limits<int>::max());
    vector<int> dist2(n, numeric_limits<int>::max());
    int left_person_idx = -1;
    for (int i = 0; i < n; i++) {
      if (seats[i] == 1) {
        left_person_idx = i;
      } else {
        if (left_person_idx != -1) {
          dist1[i] = i - left_person_idx;
        }
      }
    }
    int ret = 0;
    int right_person_idx = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (seats[i] == 1) {
        right_person_idx = i;
      } else {
        if (right_person_idx != -1) {
          dist2[i] = right_person_idx - i;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (seats[i] == 0) {
        ret = max(ret, min(dist1[i], dist2[i]));
      }
    }
    return ret;
  }
};
