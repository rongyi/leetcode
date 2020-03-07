// http://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
#include "xxx.h"

class Solution {
public:
  int minTaps(int n, vector<int> &ranges) {
    vector<vector<int>> itvs;
    for (int i = 0; i < ranges.size(); i++) {
      itvs.push_back({i - ranges[i], i + ranges[i]});
    }
    return videoStitching(itvs, n);
  }

private:
  // just like 1124
  int videoStitching(vector<vector<int>> &clips, int T) {
    int ret = 0;
    sort(clips.begin(), clips.end());
    for (auto i = 0, st = 0, end = 0; st < T; st = end, ++ret) {
      while (i < clips.size() && clips[i][0] <= st) {
        //后面的check保证了区间连续，必须是起点在当前st的左边和当前位置往后面就有gap了
        end = max(end, clips[i++][1]);
      }
      if (st == end) {
        return -1;
      }
    }
    return ret;
  }
};
