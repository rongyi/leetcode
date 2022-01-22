// http://leetcode.com/problems/vowel-spellchecker/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    vector<string> ret;
    // lower ==> origin
    unordered_map<string, string> dict;
    for (auto &w : wordlist) {
      dict.insert({w, w});
      dict.insert({lowerKey(w), w});
      dict.insert({vowelKey(w), w});
    }

    for (auto q : queries) {
      auto it = dict.find(q);
      if (it == dict.end()) {
        it = dict.find(lowerKey(q));
      }
      if (it == dict.end()) {
        it = dict.find(vowelKey(q));
      }

      if (it != dict.end()) {
        ret.push_back(it->second);
      } else {
        ret.push_back("");
      }
    }

    return ret;
  }

private:
  string lowerKey(string &s) {
    return accumulate(s.begin(), s.end(), string("_"), [](string acc, char c) {
      return acc + (char)tolower(c);
    });
  }
  string vowelKey(string &s) {
    return accumulate(s.begin(), s.end(), string(""), [](string acc, char c) {
      return acc + (char)(string("aeiou").find(tolower(c)) != string::npos
                              ? '*'
                              : tolower(c));
    });
  }
};
