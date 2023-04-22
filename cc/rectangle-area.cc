// http://leetcode.com/problems/rectangle-area/description/

#include "xxx.hpp"

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int sum = (C - A) * (D - B) + (G - E) * (H - F);

    // no intersection
    if (E >= C || H <= B || F >= D || A >= G) {
      return sum;
    }

    // intersection coordinate is the two middle one, after sort
    vector<int> x{A, E, G, C};
    vector<int> y{B, F, H, D};
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    return sum - (x[2] - x[1]) * (y[2] - y[1]);
  }
};
