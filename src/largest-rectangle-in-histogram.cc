// http://leetcode.com/problems/largest-rectangle-in-histogram/description/
#include "one.h"

class Solution {
public:
  int largestRectangleAreaTLEVersion(vector<int> &heights) {
    auto maxarea = 0;
    heights.push_back(0);
    const int n = heights.size();
    for (int i = 0; i < n; ++i) {
      maxarea = max(maxarea, heights[i]);
      auto minh = heights[i];
      for (int j = i - 1; j >= 0; --j) {
        minh = min(minh, heights[j]);
        maxarea = max(maxarea, (i - j + 1) * minh);
      }
    }

    return maxarea;
  }
  int largestRectangleArea(vector<int> &heights) {
    auto ret = 0;
    heights.push_back(0);
    const int n = heights.size();
    stack<int> stk;
    for (int i = 0; i < n; ) {
      if (stk.empty() || heights[stk.top()] < heights[i]) {
        stk.push(i++);
      } else {
        auto idx = stk.top();
        stk.pop();
        auto w = stk.empty() ? i : i - stk.top() - 1;
        ret = max(ret, w * heights[idx]);
      }
    }

    return ret;
  }
};
int main() {
  Solution so;
  vector<int> input{2, 1, 5, 6, 2, 3};
  auto ret = so.largestRectangleArea(input);
  cout << ret << endl;
}
