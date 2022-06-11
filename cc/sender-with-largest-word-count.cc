// https://leetcode.com/problems/sender-with-largest-word-count/
#include "xxx.hpp"

class Solution {
public:
  string largestWordCount(vector<string> &messages, vector<string> &senders) {
    string maxkey = {};
    int maxcnt = 0;
    map<string, int> cnt;
    int sz = messages.size();

    for (int i = 0; i < sz; ++i) {
      cnt[senders[i]] += words(messages[i]);
      if (cnt[senders[i]] > maxcnt) {
        maxcnt = cnt[senders[i]];
        maxkey = senders[i];
      } else if (cnt[senders[i]] == maxcnt) {
        // lex order max!
        maxkey = max(maxkey, senders[i]);
      }
    }

    return maxkey;
  }
private:
  int words(string &msg) {
    int spaces = 0;
    for (auto c : msg) {
      if (c == ' ') {
        spaces++;
      }
    }

    return spaces + 1;
  }
};
