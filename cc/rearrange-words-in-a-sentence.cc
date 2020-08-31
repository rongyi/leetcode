// http://leetcode.com/problems/rearrange-words-in-a-sentence/description/
#include "xxx.h"

class Solution {
public:
  string arrangeWords(string text) {
    text[0] = tolower(text[0]);
    istringstream ss(text);
    string cur;

    // order by lenth, and pushed by words order
    map<int, vector<string>> words;
    while (getline(ss, cur, ' ')) {
      words[cur.size()].push_back(cur);
    }
    ostringstream output;
    for (auto &kv : words) {
      for (auto &w : kv.second) {
        output << w;
        output << ' ';
      }
    }

    string ret = output.str();
    ret[0] = toupper(ret[0]);
    ret.pop_back();

    return ret;
  }
};
