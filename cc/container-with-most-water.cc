// http://leetcode.com/problems/container-with-most-water/description/
#include "xxx.hpp"

class Solution {
public:
  int maxArea(vector<int> &height) {
    int sz = height.size();
    int l = 0;
    int r = sz - 1;
    int ret = 0;
    while (l < r) {
      ret = max(ret, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};
  auto ret = so.maxArea(input);
  cout << ret << endl;
}
