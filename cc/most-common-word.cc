// http://leetcode.com/problems/most-common-word/description/
#include "xxx.h"

class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    // normalize
    for (auto &c : paragraph) {
      if (isalpha(c)) {
        c = tolower(c);
      } else {
        c = ' ';
      }
    }

    istringstream ss(paragraph);
    unordered_set<string> black(banned.begin(), banned.end());
    string cur{};

    string ret{};
    int max_occ = 0;
    unordered_map<string, int> count;
    while (ss >> cur) {
      if (black.find(cur) == black.end()) {
        count[cur]++;
        if (count[cur] > max_occ) {
          max_occ = count[cur];
          ret = cur;
        }
      }
    }

    return ret;
  }
};
