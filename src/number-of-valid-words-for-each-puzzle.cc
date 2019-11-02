// http://leetcode.com/problems/number-of-valid-words-for-each-puzzle/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findNumOfValidWords(vector<string> &words,
                                  vector<string> &puzzles) {
    const int wlen = words.size();
    const int plen = puzzles.size();

    // set a mask for one letter
    vector<int> letter_mask(26, 0);
    for (int i = 0, mask = 1; i < 26; ++i, mask <<= 1) {
      letter_mask[i] = mask;
    }
    unordered_map<int, int> words_mask;

    // for each word compute word mask
    for (int i = 0; i < wlen; ++i) {
      int cur_mask = 0;
      for (auto &c : words[i]) {
        cur_mask |= letter_mask[c - 'a'];
      }
      ++words_mask[cur_mask];
    }
    vector<int> ret(plen, 0);
    for (int i = 0; i < plen; ++i) {
      int cur_mask = 0;
      for (auto &c : puzzles[i]) {
        cur_mask |= letter_mask[c - 'a'];
      }

      int itmask = cur_mask;
      while (itmask) {
        // contain the first letter of puzzle
        if ((itmask & letter_mask[puzzles[i][0] - 'a']) &&
            words_mask.count(itmask)) {
          ret[i] += words_mask[itmask];
        }
        // so cool!
        itmask = (itmask - 1) & cur_mask;
      }
    }

    return ret;
  }
};
