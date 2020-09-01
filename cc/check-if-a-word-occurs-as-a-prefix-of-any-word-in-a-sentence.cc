// http://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
#include "xxx.h"

class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    istringstream ss(sentence);
    string cur;
    vector<string> ws;
    while (getline(ss, cur, ' ')) {
      ws.push_back(cur);
    }
    for (int i = 0; i < ws.size(); ++i) {
      if (ws[i].size() < searchWord.size()) {
        continue;
      }
      if (searchWord == ws[i].substr(0, searchWord.size())) {
        // start from 1
        return i + 1;
      }
    }
    return -1;
  }
};
