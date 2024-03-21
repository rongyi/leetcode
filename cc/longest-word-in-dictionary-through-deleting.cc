// http://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
#include "xxx.hpp"

class Solution {
public:
  string findLongestWord(string s, vector<string> &d) {
    sort(d.begin(), d.end(), [](string &l, string &r) -> bool {
      if (l.size() != r.size()) {
        return l.size() > r.size();
      }
      return l < r;
    });

    for (auto &str : d) {
      if (str.size() > s.size()) {
        continue;
      }
      if (issubseq(str, s)) {
        return str;
      }
    }
    return "";
  }

private:
  bool issubseq(string &sub, string &match) {
    int j = 0;

    for (int i = 0; i < match.size(); i++) {
      if (sub[j] == match[i]) {
        j++;
      }
      if (j == sub.size()) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution so;
  string str{"aewfafwafjlwajflwajflwafj"};
  vector<string> input{"apple", "ewaf",  "awefawfwaf",
                       "awef",  "awefe", "ewafeffewafewf"};
  auto ret = so.findLongestWord(str, input);
  cout << ret << endl;
}
