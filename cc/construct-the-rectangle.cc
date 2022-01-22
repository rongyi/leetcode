// http://leetcode.com/problems/construct-the-rectangle/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> constructRectangle(int area) {
    double d = sqrt((double)area);

    for (int i = (int)d; i > 0; --i) {
      if (area % i == 0) {
        auto w = max(i, area / i);
        auto l = area / w;
        return {w, l};
      }
    }
    return {-1, -1};
  }
};

int main() {
  Solution so;
  so.constructRectangle(4);
}
