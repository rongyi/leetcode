// http://leetcode.com/problems/angle-between-hands-of-a-clock/description/
#include "xxx.hpp"

class Solution {
public:
  double angleClock(int hour, int minutes) {
    double ret = 0;
    if (minutes == 0) {
      ret = hour * 30;
    } else {
      // 这里算的是分针在前，时针在后的走法
      // 之间的夹角，粗略的计算，没有算细节偏移，比如12点半就先算六格180度出来
      ret = ((minutes / 5 - hour + 12) % 12) * (double)30;
      // 然后分针的细节微调，分针走拉大空间 x / 5 * 30 代入5分钟验证
      ret += (minutes % 5) / (double)5 * 30;
      // 时针走压缩距离，公式： x / 60 * 30, 代入一圈60分验证得30度，
      ret -= (double)minutes * 0.5;
      if (ret < 0) {
        ret = -ret;
      }
    }

    if (ret > 180) {
      ret = 360 - ret;
    }
    return ret;
  }
};

int main() {
  Solution so;
  cout << so.angleClock(1, 4) << endl;
}
