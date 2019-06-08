// http://leetcode.com/problems/hand-of-straights/description/
#include "xxx.h"

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int W) {
    if (W == 1) {
      return true;
    }

    unordered_map<int, int> count;
    unordered_set<int> uniq;

    for (auto h : hand) {
      count[h]++;
      uniq.insert(h);
    }
    vector<int> suniq(uniq.begin(), uniq.end());
    sort(suniq.begin(), suniq.end());

    const int n = suniq.size();
    for (int i = 0; i < n;) {
      int cur = suniq[i];
      bool intersection = false;
      for (int w = 0; w < W; w++) {
        if (count.find(cur + w) == count.end()) {
          return false;
        }
        count[cur + w]--;
        if (!intersection && count[cur + w]) {
          intersection = true;
          i += w;
        }
      }

      if (!intersection) {
        i += W;
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 6, 2, 3, 4, 7, 8};
  so.isNStraightHand(input, 3);
}
