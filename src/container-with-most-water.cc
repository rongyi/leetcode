// http://leetcode.com/problems/container-with-most-water/description/
#include "one.h"

class Solution {
public:
  int maxArea(vector<int> &height) {
    const int n = height.size();
    int ret = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
      ret = max(ret, min(height[left], height[right]) * (right - left));
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
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
