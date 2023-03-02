// http://leetcode.com/problems/leetcode/maximal-rectangle/description/
#include "xxx.hpp"

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> heights(n + 1, 0);
    int ret = largestRectangleArea(heights);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          heights[j] += 1;
        } else {
          heights[j] = 0;
        }
      }
      ret = max(ret, largestRectangleArea(heights));
    }
    return ret;
  }

private:
  int largestRectangleArea(vector<int> &heights) {

    int sz = heights.size();
    int ret = 0;
    vector<int> stk;
    for (int i = 0; i < sz;) {
      if (stk.empty() || heights[stk.back()] < heights[i]) {
        stk.push_back(i);
        i++;
      } else {
        int idx = stk.back();
        stk.pop_back();
        if (stk.empty()) {
          ret = max(ret, i * heights[idx]);
        } else {
          ret = max(ret, (i - stk.back() - 1) * heights[idx]);
        }
      }
    }
    return ret;
  }
};
