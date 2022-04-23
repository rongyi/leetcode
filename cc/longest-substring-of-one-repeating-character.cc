// https://leetcode.com/problems/longest-substring-of-one-repeating-character/
#include "xxx.hpp"

class Solution {
private:
  struct node {
    // c++11 init with default value
    char left_ = 0;
    char right_ = 0;
    int prefix_len_ = 0;
    int suffix_len_ = 0;
    int longest_ = 0;
    int sz_ = 1;

    void merge(node &l, node &r) {
      longest_ = max(l.longest_, r.longest_);
      // can concat?
      if (l.right_ == r.left_) {
        longest_ = max(longest_, l.suffix_len_ + r.prefix_len_);
      }
      sz_ = l.sz_ + r.sz_;
      left_ = l.left_;
      right_ = r.right_;
      prefix_len_ = l.prefix_len_;
      // prefix can be enlarged?
      if (l.prefix_len_ == l.sz_ && l.left_ == r.left_) {
        prefix_len_ += r.prefix_len_;
      }
      suffix_len_ = r.suffix_len_;
      // suffix_len_ can be enlarged?
      if (r.suffix_len_ == r.sz_ && r.right_ == l.right_) {
        suffix_len_ += l.suffix_len_;
      }
    }
  };

public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int> &queryIndices) {
    vector<int> ret;
    int power_of2 = 1;
    int sz = s.size();
    while (power_of2 < sz) {
      power_of2 <<= 1;
    }
    vector<node> nodes(power_of2 * 2);
    for (int i = 0; i < s.size(); ++i) {
      update(nodes, i, s[i], 0, 0, power_of2 - 1);
    }
    for (int j = 0; j < queryCharacters.size(); ++j) {
      ret.push_back(update(nodes, queryIndices[j], queryCharacters[j], 0, 0,
                           power_of2 - 1));
    }

    return ret;
  }

private:
  // parent: the current header for range from l --> r inclusive
  int update(vector<node> &nodes, int pos, char replace, int parent, int l,
             int r) {
    // in the range
    if (l <= pos && pos <= r) {
      // a range ?
      if (l != r) {
        auto m = l + (r - l) / 2;
        auto l_head = 2 * parent + 1;
        auto r_head = 2 * parent + 2;
        update(nodes, pos, replace, l_head, l, m);
        update(nodes, pos, replace, r_head, m + 1, r);
        nodes[parent].merge(nodes[l_head], nodes[r_head]);
      } else {
        // single one
        nodes[parent].left_ = nodes[parent].right_ = replace;
        nodes[parent].suffix_len_ = nodes[parent].prefix_len_ =
            nodes[parent].longest_ = 1;
      }
    }
    return nodes[parent].longest_;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  string qc{"bcb"};
  vector<int> qi{1, 3, 3};
  so.longestRepeating("babacc", qc, qi);
  return 0;
}
