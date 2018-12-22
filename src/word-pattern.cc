// http://leetcode.com/problems/word-pattern/description/
#include "xxx.h"

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    auto words = split(' ', str);
    unordered_map<char, string> dict;
    unordered_map<string, char> dictr;
    if (pattern.size() != words.size()) {
      return false;
    }
    for (int i = 0; i < pattern.size(); i++) {
      const auto c = pattern[i];
      const auto w = words[i];
      // construct the relation ship
      if (dict.find(c) == dict.end()) {
        if (dictr.find(w) != dictr.end()) {
          return false;
        }
        dict[c] = w;
        dictr[w] = c;
        continue;
      }
      // we compare the
      if (dict[c] != w) {
        return false;
      }
    }
    return true;
  }

public:
  inline vector<string> split(const char delim, const string &input) {
    vector<string> ret;
    if (input.empty()) {
      return ret;
    }

    size_t token_start_pos = 0;
    size_t token_size = 0;

    for (size_t i = 0; i <= input.size() - 1; ++i) {
      if (input[i] == delim) {
        if (token_size > 0) {
          ret.push_back(std::string(input, token_start_pos, token_size));
        }
        token_start_pos = i + 1;
        token_size = 0;
      } else {
        ++token_size;
      }
    }

    // the last one
    token_size = input.size() - token_start_pos;
    if (token_size > 0) {
      ret.push_back(std::string(input, token_start_pos, token_size));
    }

    return ret;
  }
};
