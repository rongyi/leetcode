// http://leetcode.com/problems/fancy-sequence/description/
#include "xxx.hpp"

class Fancy {
public:
  // 这种方式比较好理解一点，分段的处理
  // https://leetcode.com/problems/fancy-sequence/discuss/910235/Focus-on-having-multiple-solutions-for-same-problem.-O(root-N)-Update-and-O(1)-Query-solution.
  Fancy() : mod_(1e9 + 7), bucket_len_(225) {}

  void append(int val) {
    if ((lst_.size() % bucket_len_) == 0) {
      lst_.push_back(val);
      ma_pair.push_back({1, 0});
      return;
    }

    resolve_last_bucket();
    lst_.push_back(val);
  }

  void addAll(int inc) {
    for (int i = 0; i < ma_pair.size(); ++i) {
      ma_pair[i].second = (ma_pair[i].second + inc) % mod_;
    }
  }

  void multAll(int m) {
    for (int i = 0; i < ma_pair.size(); ++i) {
      ma_pair[i].first = (ma_pair[i].first * m) % mod_;
      ma_pair[i].second = (ma_pair[i].second * m) % mod_;
    }
  }

  int getIndex(int idx) {
    if (idx >= lst_.size()) {
      return -1;
    }
    int bck_idx = idx / bucket_len_;

    return (lst_[idx] * ma_pair[bck_idx].first + ma_pair[bck_idx].second) %
           mod_;
  }

private:
  void resolve_last_bucket() {
    // last bucket
    int start = (lst_.size() / bucket_len_) * bucket_len_;
    for (int i = start; i < lst_.size(); ++i) {
      lst_[i] = (lst_[i] * ma_pair.back().first + ma_pair.back().second) % mod_;
    }

    ma_pair.back().first = 1;
    ma_pair.back().second = 0;
  }

private:
  int mod_;
  int bucket_len_;
  vector<long long> lst_;
  vector<pair<long long, long long>> ma_pair; // mul, add
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
