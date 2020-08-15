// http://leetcode.com/problems/erect-the-fence/description/
#include "xxx.h"

// bool operator==(const Point &p1, const Point &p2) {
//   return p1.x == p2.x && (p1.y == p2.y);
// };

class Solution {
public:
  vector<Point> outerTrees(vector<Point> &points) {
    ps_ = points;
    set<Point, comp> uniq;
    const int n = points.size();
    int first_index = 0;
    int next_index = -1;
    for (int i = 0; i < n; i++) {
      if (points[i].x < points[first_index].x) {
        first_index = i;
      }
    }
    int cur_index = first_index;

    uniq.insert(points[first_index]);
    while (cur_index != first_index || next_index == -1) {
      next_index = 0;
      for (int i = 1; i < n; i++) {
        if (cur_index == i) {
          continue;
        }
        // cross > 0意味着什么？ 意味着在固定最左侧节点后我们可以找到一个
        // 屁股还能往上翘吗？能就继续撅
        auto cross = crossProduct(cur_index, i, next_index);
        if (cross > 0 ||
            (cross == 0 &&
             distance(points[cur_index], points[i]) >
                 distance(points[cur_index], points[next_index]))) {
          next_index = i;
        }
      }

      for (int i = 0; i < n; i++) {
        if (cur_index == i) {
          continue;
        }
        // if i and next_index is same, just insert this point
        if (crossProduct(cur_index, i, next_index) == 0) {
          uniq.insert(points[i]);
        }
      }
      cur_index = next_index;
    }
    vector<Point> ret(uniq.begin(), uniq.end());
    return ret;
  }

private:
  struct comp {
    bool operator()(Point a, Point b) const {
      return a.x == b.x ? a.y < b.y : a.x < b.x;
    }
  };
  int distance(Point &p1, Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  }
  // 1. > 0
  //     b
  //    / \
  //   /   \
  //  v     v
  //  a      c
  // 2. == 0 (collinea)
  // a -- b -- c
  // 3. < 0
  //  a      c
  //  ^      ^
  //  \     /
  //   \   /
  //     c
  int crossProduct(int ai, int bi, int ci) {
    int bax = ps_[bi].x - ps_[ai].x;
    int bay = ps_[bi].y - ps_[ai].y;

    int bcx = ps_[bi].x - ps_[ci].x;
    int bcy = ps_[bi].y - ps_[ci].y;

    return bax * bcy - bay * bcx;
  }

private:
  vector<Point> ps_;
};

int main() {
  Solution so;
  Point p1(1, 0);
  Point p2(2, 0);
  Point p3(3, 1);
  // auto ret = so.crossProduct(p1, p2, p3);
  // cout << ret << endl;
}
