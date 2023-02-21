// http://leetcode.com/problems/text-justification/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ret;
    vector<string> cur_line_words;
    int line_words_sz = 0;

    for (auto &w : words) {
      int peek_len = line_words_sz + cur_line_words.size() + w.size();
      // fit int current line
      if (peek_len <= maxWidth) {
        cur_line_words.push_back(w);
        line_words_sz += w.size();
      } else {
        // trigger a new line output
        if (cur_line_words.size() == 1) {
          string cur = cur_line_words[0];
          // padding space
          cur.append(maxWidth - cur.size(), ' ');
          ret.push_back(cur);
        } else {
          int avg_space =
              (maxWidth - line_words_sz) / (cur_line_words.size() - 1);
          int padding_space =
              (maxWidth - line_words_sz) % (cur_line_words.size() - 1);
          string cur = cur_line_words[0];
          for (int j = 1; j < cur_line_words.size(); j++) {
            if (j <= padding_space) {
              cur.append(avg_space + 1, ' ');
            } else {
              cur.append(avg_space, ' ');
            }
            cur += cur_line_words[j];
          }
          ret.push_back(cur);
        }

        // then put current in a fresh new line
        cur_line_words.clear();
        cur_line_words.push_back(w);
        line_words_sz = w.size();
      }
    }
    string cur = cur_line_words[0];
    for (int j = 1; j < cur_line_words.size(); ++j) {
      cur += ' ' + cur_line_words[j];
    }
    cur.append(maxWidth - cur.size(), ' ');
    ret.push_back(cur);

    return ret;
  }
};
