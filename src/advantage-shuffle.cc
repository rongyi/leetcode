// http://leetcode.com/problems/advantage-shuffle/description/
#include "xxx.h"

class Solution {
public:
  vector<int> advantageCount(vector<int> &A, vector<int> &B) {
    map<int, int> count;
    for (auto num : A) {
      count[num]++;
    }
    vector<int> ret;
    for (auto num : B) {
      auto it = count.upper_bound(num);
      int x = 0;
      if (it == count.end()) {
        x = count.begin()->first;
      } else {
        x = it->first;
      }
      count[x]--;
      if (count[x] == 0) {
        count.erase(x);
      }
      ret.push_back(x);
    }

    return ret;
  }
};
