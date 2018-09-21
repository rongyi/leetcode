// http://leetcode.com/problems/ranger-module/description/
#include <vector>
using namespace std;

class RangeModule {
public:
  void addRange(int left, int right) {
    vector<pair<int, int>> newrange;
    const int n = ranges_.size();
    int insert_at = 0;

    for (int i = 0; i < n; ++i) {
      // 一脚踢开不相关的区间
      // |-------| |-------|
      //    cur        [left, right)
      if (ranges_[i].second < left) {
        newrange.push_back(ranges_[i]);
        ++insert_at;
      } else if (ranges_[i].first > right) {
        // |-------|        |------|
        //  [left, right)      cur
        newrange.push_back(ranges_[i]);
      } else {
        // 这是就是区间合并的case了，算出最小值，最大值
        left = min(left, ranges_[i].first);
        right = max(right, ranges_[i].second);
      }
    }
    newrange.insert(newrange.begin() + insert_at, {left, right});

    ranges_ = newrange;
  }

  bool queryRange(int left, int right) {
    for (auto p : ranges_) {
      if (p.first <= left && p.second >= right) {
        return true;
      }
    }
    return false;
  }

  void removeRange(int left, int right) {
    vector<pair<int, int>> newrange;
    vector<pair<int, int>> tmp;
    const int n = ranges_.size();
    int insert_at = 0;
    for (int i = 0; i < n; ++i) {
      // 一脚踢开不相关的
      if (ranges_[i].second <= left) {
        newrange.push_back(ranges_[i]);
        ++insert_at;
      } else if (ranges_[i].first >= right) {
        // 这个空间不在已有的区间里面
        newrange.push_back(ranges_[i]);
      } else {
        // 有交集
        // 前面剩下一点
        if (ranges_[i].first < left) {
          tmp.push_back({ranges_[i].first, left});
        }
        // 后面剩下一点
        if (ranges_[i].second > right) {
          tmp.push_back({right, ranges_[i].second});
        }
      }
    }
    newrange.insert(newrange.begin() + insert_at, tmp.begin(), tmp.end());
    ranges_ = newrange;
  }

private:
  vector<pair<int, int>> ranges_;
};
