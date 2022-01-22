// http://leetcode.com/problems/short-encoding-of-words/description/
#include "xxx.hpp"

class Solution {
public:
  int minimumLengthEncoding(vector<string> &w) {
    unordered_set<string> uniq(w.begin(), w.end());
    for (auto s : uniq) {
      for (int i = 1; i < s.size(); i++) {
        uniq.erase(s.substr(i));
      }
    }
    int ret = 0;
    for (auto s : uniq) {
      ret += 1 + s.size();
    }
    return ret;
  }
  int minimumLengthEncodingTLE(vector<string> &w) {
    unordered_set<string> uniq(w.begin(), w.end());
    vector<string> words;
    for (auto s : uniq) {
      words.push_back(s);
    }

    sort(words.begin(), words.end(),
         [](const string &l, const string &r) { return l.size() > r.size(); });
    unordered_set<string> visited;
    const int n = words.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (visited.find(words[i]) != visited.end()) {
        continue;
      }
      string pattern = words[i];
      for (int j = i + 1; j < n; j++) {
        string cur = words[j];
        // match
        if (pattern.substr(pattern.size() - cur.size()) == cur) {
          visited.insert(cur);
        }
      }
    }
    for (auto &s : words) {
      if (visited.find(s) != visited.end()) {
        continue;
      }
      ret += 1 + s.size();
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"time", "me", "bell"};
  so.minimumLengthEncoding(input);
}
