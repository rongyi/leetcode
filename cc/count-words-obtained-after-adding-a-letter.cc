// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
#include "xxx.hpp"

class SolutionTLE {
public:
  int wordCount(vector<string> &startWords, vector<string> &targetWords) {
    int sz = startWords.size();
    vector<bitset<26>> ws(sz);
    for (int i = 0; i < sz; ++i) {
      for (auto &c : startWords[i]) {
        ws[i].set(c - 'a');
      }
    }
    int ret = 0;
    for (auto &tw : targetWords) {
      bitset<26> cur_ts;
      for (auto &c : tw) {
        cur_ts.set(c - 'a');
      }
      for (int i = 0; i < sz; ++i) {
        // candidate need to be a subset of current words
        if ((ws[i] == cur_ts) || (ws[i] & cur_ts) != ws[i] ||
            (ws[i].count() + 1 != cur_ts.count())) {
          continue;
        }
        // now I can add whatever not in candidate to gen target word
        ++ret;
        break;
      }
    }

    return ret;
  }
};

// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/discuss/1676859/Trie-vs.-Bitmask-vs.-Sorting
class Solution {
public:
  int wordCount(vector<string> &startWords, vector<string> &targetWords) {
    auto mask_as_int_fn = [](string &w) -> int {
      return accumulate(w.begin(), w.end(), 0, [](int acc, char cur) {
        return acc + (1 << (cur - 'a'));
      });
    };
    set<int> masks;
    for (auto &w : startWords) {
      masks.insert(mask_as_int_fn(w));
    }
    int ret = 0;
    for (auto &w : targetWords) {
      auto cur_mask = mask_as_int_fn(w);
      ret += any_of(w.begin(), w.end(), [&](char &c) -> bool {
        return masks.count(cur_mask - (1 << (c - 'a')));
      });
    }

    return ret;
  }
};

