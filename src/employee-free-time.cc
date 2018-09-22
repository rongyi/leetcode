// http://leetcode.com/problems/employee-free-time/description/

#include "one.h"
struct Interval {
  int start;
  int end;
  Interval(int a, int b) : start(a), end(b) {}
};

class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule) {
    vector<Interval> flat;
    for (auto is : schedule) {
      flat.insert(flat.begin(), is.begin(), is.end());
    }
    sort(flat.begin(), flat.end(),
         [](const Interval &a, const Interval &b)->bool { return a.start < b.start; });
    vector<Interval> ret;
    auto t = flat[0];
    for (auto itv : flat) {
      if (t.end < itv.start) {
        ret.push_back(Interval(t.end, itv.start));
        t = itv;
      } else {
        if (t.end < itv.end) {
          t = itv;
        }
      }
    }

    return ret;
  }
};
int main() {
  Solution so;
  vector<vector<Interval>> input{{Interval(1, 2), Interval(5, 6)}, {Interval(1, 3), Interval(4, 10)}};
  auto ret = so.employeeFreeTime(input);
  for (auto r : ret) {
    cout << r.start << "  " << r.end;
    cout << endl;
  }
}
