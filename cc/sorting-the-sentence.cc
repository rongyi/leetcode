// http://leetcode.com/problems/sorting-the-sentence/description/
#include "xxx.h"

class Solution {
public:
  string sortSentence(string s) {
    int len = s.size();
    int sz = 0;
    int prev = 0;
    vector<string> words;
    for (int i = 0; i < len; ++i) {
      if (s[i] == ' ') {
        sz++;
        auto w = s.substr(prev, i - prev);
        prev = i + 1;
        words.push_back(w);
      }
    }
    // the last one
    words.push_back(s.substr(prev));
    sz++; // size means the count of space
    // start with index 1 so make it one more bigger
    vector<string> sorted_words(sz + 1, "");
    for (int i = 0; i < words.size(); ++i) {
      string &cur_word = words[i];
      int j = 0;
      while (j < cur_word.size() && !isdigit(cur_word[j])) {
        j++;
      }
      auto tmp = cur_word.substr(j);
      auto idx = stoi(tmp);
      sorted_words[idx] = cur_word.substr(0, j);
    }
    ostringstream ss;
    for (int i = 1; i < sorted_words.size(); ++i) {
      ss << sorted_words[i] << " ";
    }
    string ret = ss.str();
    ret.pop_back(); // the last space
    return ret;
  }
};
