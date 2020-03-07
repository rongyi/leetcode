// http://leetcode.com/problems/video-stitching/description/
#include "xxx.h"

class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int T) {
    sort(clips.begin(), clips.end());
    int ret = 0;
    int cur_end = 0;
    int pre_end = -1;

    for (auto &v : clips) {
      // 已经走很远了
      if (v[1] <= cur_end) {
        continue;
      }
      // 有gap
      if (v[0] > cur_end) {
        return -1;
      }
      if (v[0] > pre_end) {
        pre_end = cur_end;
        ++ret;
      }
      cur_end = v[1];
      if (cur_end >= T) {
        return ret;
      }
    }

    return -1;
  }

  int videoStitching2(vector<vector<int>> &clips, int T) {
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
