// http://leetcode.com/problems/leetcode/maximal-rectangle/description/
#include "one.h"

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    const int m = matrix.size();

    int ret = 0;
    vector<int> histogram;
    for (int i = 0; i < m; ++i) {
      histogram.resize(matrix[i].size());
      for (int j = 0; j < matrix[i].size(); ++j) {
        histogram[j] = (matrix[i][j] == '0') ? 0 : 1 + histogram[j];
      }
      ret = max(ret, largestRectangleArea(histogram));
    }

    return ret;
  }

private:
  int largestRectangleArea(vector<int> &heights) {
    auto ret = 0;
    heights.push_back(0);
    const int n = heights.size();
    stack<int> stk;
    for (int i = 0; i < n;) {
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
