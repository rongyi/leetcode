// http://leetcode.com/problems/concatenated-words/description/
#include "xxx.h"

class Solution {
public:
  // 意思是从一堆单词里找到一些复合词，这些复合词是有这个集合里某些单词拼起来的
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    vector<string> ret;
    sort(words.begin(), words.end(),
         [](const string &l1, const string &l2) -> bool {
           return l1.size() < l2.size();
         });
    unordered_set<string> pre_words;

    for (int i = 0; i < words.size(); ++i) {
      if (canForm(words[i], pre_words)) {
        ret.push_back(words[i]);
      }
      pre_words.insert(words[i]);
    }

    return ret;
  }

public:
  bool canForm(string &s, unordered_set<string> &dict) {
    if (dict.empty()) {
      return false;
    }
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; ++j) {
        if (!dp[j]) {
          continue;
        }
        // cout << s.substr(j, i - j) << endl;
        if (dict.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};

int main() {
  Solution so;
  // vector<string> input{"cat", "cats",        "catsdogcats",
  //                      "dog", "dogcatsdog",  "hippopotamuses",
  //                      "rat", "ratcatdogcat"};
  // so.findAllConcatenatedWordsInADict(input);

  string input{"abcd"};
  unordered_set<string> dict{"ab", "c", "d"};
  auto ret = so.canForm(input, dict);
  cout << ret << endl;
}
