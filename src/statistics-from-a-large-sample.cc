// http://leetcode.com/problems/statistics-from-a-large-sample/description/
#include "xxx.h"

class Solution {
public:
  vector<double> sampleStats(vector<int> &count) {
    double ret[5] = {255, 0, 0, 0, 0};
    int total = accumulate(count.begin(), count.end(), 0);
    int max_count = 0;
    int m1 = (total + 1) / 2;
    int m2 = m1 + (total % 2 == 0 ? 1 : 0);
    for (auto i = 0, cur_count = 0; i < count.size(); cur_count += count[i++]) {
      ret[0] = count[i] ? min((int)ret[0], i) : ret[0];
      ret[1] = count[i] ? i : ret[1];
      ret[2] += (double)i * count[i] / total;

      if (cur_count < m1 && cur_count + count[i] >= m1) {
        ret[3] += (double)i / 2;
      }
      if (cur_count < m2 && cur_count + count[i] >= m2) {
        ret[3] += (double)i / 2;
      }

      ret[4] = max_count < count[i] ? i : ret[4];

      max_count = max(max_count, count[i]);
    }

    return vector<double>(begin(ret), end(ret));
  }
};
