// http://leetcode.com/problems/maximum-product-of-word-lengths/description/
#include "simpleone.h"
class Solution {
public:
  int maxProductTLEVersionHAHAHA(vector<string> &words) {
    const int n = words.size();
    unordered_map<char, unordered_set<int>> occr;
    unordered_set<int> total;
    for (int i = 0; i < n; i++) {
      total.insert(i);
      for (auto c : words[i]) {
        occr[c].insert(i);
      }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
      auto cur_word = words[i];
      auto cur_total = total;
      bool allcontinue = true;
      for (auto c : cur_word) {
        auto cur_occset = occr[c];
        // this word is occr in every word
        if (cur_occset.size() == n) {
          // cout << "all occ" << c << endl;
          break;
        }
        allcontinue = false;

        auto comple_set = complement(total, cur_occset);
        cur_total = intersection(cur_total, comple_set);
      }
      if (allcontinue) {
        continue;
      }
      for (auto comple_index : cur_total) {
        // cout << comple_index << endl;
        if (comple_index == i) {
          continue;
        }
        ret = max(ret, (int)cur_word.size() * (int)words[comple_index].size());
      }
    }

    return ret;
  }

public:
  // return total - a
  unordered_set<int> complement(unordered_set<int> &total,
                                unordered_set<int> &a) {
    unordered_set<int> ret;
    for (auto t : total) {
      if (a.find(t) == a.end()) {
        ret.insert(t);
      }
    }
    return ret;
  }
  unordered_set<int> intersection(unordered_set<int> &a,
                                  unordered_set<int> &b) {
    unordered_set<int> ret;
    for (auto cura : a) {
      if (b.find(cura) != b.end()) {
        ret.insert(cura);
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"abc", "a"};
  auto ret = so.maxProduct(input);
  cout << ret << endl;
}
