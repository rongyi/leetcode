// http://leetcode.com/problems/occurrences-after-bigram/description/
#include "xxx.h"

class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> ret;
    const string key = first + " " + second + " ";
    recur(text, key, ret);
    return ret;
  }

private:
  void recur(string text, const string &key, vector<string> &ret) {
    auto it = text.find(key);
    if (it != string::npos && it + key.size() < text.size()) {
      // key有可能是作为单词的部分出现
      // 这地方非常恶心 a good will match: he is aaaa good
      if (it > 0 && text[it - 1] != ' ') {
        // 从下一个单词开始
        return recur(text.substr(text.find(' ', it)), key, ret);
      }
      auto next_space = text.find(' ', it + key.size());
      if (next_space == string::npos) {
        ret.push_back(text.substr(it + key.size()));
      } else {
        ret.push_back(
            text.substr(it + key.size(), next_space - (it + key.size())));
      }
      // 继续
      recur(text.substr(it + key.size()), key, ret);
    }
  }
};

int main() {
  Solution so;
  auto ret = so.findOcurrences("a b cd ", "a", "b");
  cout << ret.size() << endl;
  cout << ret[0].size() << endl;
}
