// http://leetcode.com/problems/perfect-rectangle/description/
#include "xxx.h"

struct pairhash { // double hash function for pair key
  template <typename T, typename U>
  size_t operator()(const pair<T, U> &p) const {
    size_t l = hash<T>()(p.first), r = hash<U>()(p.second);
    return l + 0x9e3779b9 + (r << 6) + (r >> 2);
  }
};

class Solution {
public:
  // 思路： 1. 小矩形加起来面积等于大的面积
  //       2. 出现奇数次重合的只能是四个边角
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    int area = 0;

    int xmin = numeric_limits<int>::max();
    int ymin = xmin;

    int xmax = numeric_limits<int>::min();
    int ymax = xmax;

    unordered_map<pair<int, int>, int, pairhash> m;

    vector<pair<int, int>> points = {{0, 1}, {0, 3}, {2, 3}, {2, 1}};
    for (auto &v : rectangles) {
      for (auto d : points) {
        if (++m[make_pair(v[d.first], v[d.second])] > 4) {
          return false;
        }
      }
      area += (v[3] - v[1]) * (v[2] - v[0]);

      xmin = min(xmin, v[0]), ymin = min(ymin, v[1]), xmax = max(xmax, v[2]),
      ymax = max(ymax, v[3]);
    }
    if (area != (xmax - xmin) * (ymax - ymin)) {
      return false;
    }

    unordered_set<pair<int, int>, pairhash> s{
        {xmin, ymin}, {xmin, ymax}, {xmax, ymax}, {xmax, ymin}};

    for (auto kv : m) {
      if (kv.second & 1) {
        auto it = s.find(kv.first);
        if (it != s.end()) {
          s.erase(it);
        } else {
          return false;
        }
      }
    }

    return s.empty();
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{
      {1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
  auto ret = so.isRectangleCover(input);
  cout << ret << endl;
}
