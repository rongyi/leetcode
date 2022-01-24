// https://leetcode.com/problems/vowels-of-all-substrings/
#include "xxx.hpp"

class Solution {
public:
  long long countVowels(string word) {
    long long ret = 0;
    long long sz = word.size();

    for (int i = 0; i < sz; ++i) {
      char cur = word[i];
      bool isvowel =
          (cur == 'a' || cur == 'o' || cur == 'e' || cur == 'i' || cur == 'u');
      if (isvowel) {
        ret += (i + 1) * (sz - i);
      }
    }

    return ret;
  }
  long long countVowelsTLE(string word) {
    int sz = word.size();
    vector<int> prefix(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      char cur = word[i];
      bool isvowel =
          (cur == 'a' || cur == 'o' || cur == 'e' || cur == 'i' || cur == 'u');
      prefix[i + 1] = prefix[i] + isvowel;
    }
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i; j < sz; ++j) {
        ret += (prefix[j + 1] - prefix[i /* - 1 + 1*/]);
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  so.countVowels("aba");
}
