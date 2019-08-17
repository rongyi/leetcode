// http://leetcode.com/problems/longest-string-chain/description/
#include "xxx.h"

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    unordered_map<string, int> cache;
    unordered_set<string> dict;
    for (auto &w : words) {
      dict.insert(w);
    }
    vector<string> uniq(dict.begin(), dict.end());
    sort(uniq.begin(), uniq.end(),
         [](string &l, string &r) { return l.size() > r.size(); });
    int ret = 1;

    for (int i = 0; i < uniq.size(); ++i) {
      int cur = chain(uniq[i], cache, dict);
      ret = max(ret, cur);
    }

    return ret;
  }

private:
  int chain(string &s, unordered_map<string, int> &cache,
            unordered_set<string> &words) {
    if (cache.find(s) != cache.end()) {
      return cache[s];
    }
    const int n = s.size();
    int ret = 1;
    for (int i = 0; i < n; ++i) {
      string next_chain = s.substr(0, i);
      if (i < n - 1) {
        next_chain += s.substr(i + 1);
      }
      // cout << next_chain << endl;
      if (words.find(next_chain) != words.end()) {
        ret = max(ret, 1 + chain(next_chain, cache, words));
      }
    }

    cache[s] = ret;
    return ret;
  }
};

int main() {
  Solution so;
  string input{"abcde"};
  unordered_map<string, int> cache;
  unordered_set<string> words;
  so.chain(input, cache, words);
}
