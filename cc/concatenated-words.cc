// http://leetcode.com/problems/concatenated-words/description/
#include "xxx.h"

class Solution {
public:
  // 意思是从一堆单词里找到一些复合词，这些复合词是有这个集合里某些单词拼起来的
  // 结合wordbreak看
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    const int n = words.size();
    vector<string> ret;
    sort(words.begin(), words.end(),
         [](const string &l1, const string &l2) -> bool {
           return l1.size() < l2.size();
         });
    unordered_set<string> pre_words;

    for (int i = 0; i < n; ++i) {
      if (canForm(words[i], pre_words)) {
        ret.push_back(words[i]);
      }
      pre_words.insert(words[i]);
    }

    return ret;
  }

public:
  bool canForm(string &s, unordered_set<string> &dict) {
    const int n = s.size();
    if (dict.empty()) {
      return false;
    }
    // "abcd" 4 个字符 有5 个gap
    // |a|b|c|d|  竖线地方就是下刀的地方
    vector<bool> dp(s.size() + 1, false);
    // 任何字符都可以由 "" + 自己构成，所以切最左边第一刀，总是可以。
    dp[0] = true;
    // 因为必须是非空字符构成，从1开始
    for (int i = 1; i < n + 1; i++) {
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
