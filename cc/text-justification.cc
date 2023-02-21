// http://leetcode.com/problems/text-justification/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ret;
    vector<string> cur_line_words;
    int cur_words_sz = 0;

    for (auto &w : words) {
      // total words len so far + spaces + current word len
      int peek = cur_words_sz + cur_line_words.size() + w.size();
      if (peek <= maxWidth) {
        cur_line_words.push_back(w);
        cur_words_sz += w.size();
      } else {
        if (cur_line_words.size() == 1) {
          string cur = cur_line_words[0];
          cur.append(maxWidth - cur.size(), ' ');
          ret.push_back(cur);
        } else {
          // total spaces / slot
          int div = (maxWidth - cur_words_sz) / (cur_line_words.size() - 1);
          // padding from left
          int mod = (maxWidth - cur_words_sz) % (cur_line_words.size() - 1);
          string cur = cur_line_words[0];
          for (int j = 1; j < cur_line_words.size(); ++j) {
            if (j <= mod) {
              cur.append(div + 1, ' ');
            } else {
              cur.append(div, ' ');
            }
            cur += cur_line_words[j];
          }
          ret.push_back(cur);
        }

        cur_line_words.clear();
        cur_line_words.push_back(w);
        cur_words_sz = w.size();
      }
    }

    string cur = cur_line_words[0];
    for (int j = 1; j < cur_line_words.size(); j++) {
      cur += " " + cur_line_words[j];
    }
    cur.append(maxWidth - cur.size(), ' ');
    ret.push_back(cur);

    return ret;
  }
};
