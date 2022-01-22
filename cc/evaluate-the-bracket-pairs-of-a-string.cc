// http://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  string evaluate(string s, vector<vector<string>> &knowledge) {
    map<string, string> dict;
    for (auto &p : knowledge) {
      dict[p[0]] = p[1];
    }
    const int n = s.size();
    string ret{};
    for (int i = 0; i < n;) {
      // only care about the starting case
      if (s[i] == '(') {
        int j = i + 1;
        // now j is on ')'
        while (j < n && s[j] != ')') {
          j++;
        }
        string key = s.substr(i + 1, j - i - 1);
        if (dict.find(key) == dict.end()) {
          ret.push_back('?');
        } else {
          ret += dict[key];
        }

        // ignore the )
        i = j + 1;
      } else {
        ret.push_back(s[i]);
        i++;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<string>> input{{"name", "bob"}, {"age", "two"}};
  so.evaluate("(name)is(age)yearsold", input);
}
