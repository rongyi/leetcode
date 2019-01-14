// http://leetcode.com/problems/trapping-rain-water/description/
#include "xxx.h"

class Solution {
public:
  int trap(vector<int> &height) {
    const int n = height.size();
    if (n < 3) {
      return 0;
    }
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[1] = height[0];
    for (int i = 2; i < n; ++i) {
      left[i] = max(height[i - 1], left[i - 1]);
    }
    right[n - 2] = height[n - 1];
    // 这里放的位置有点锉， 所以后面有个坐标对焦
    // 总体上就是找两边的最大值，然后算差即可
    for (int i = n - 2; i >= 0; --i) {
      right[i] = max(height[i + 1], right[i + 1]);
    }
    int ret = 0;
    for (int i = 1; i < n - 1; ++i) {
      auto low = min(left[i], right[i - 1]);
      if (low > height[i]) {
        ret += (low - height[i]);
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 0, 2};
  auto ret = so.trap(input);
  cout << ret << endl;
}
