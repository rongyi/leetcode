// http://leetcode.com/problems/guess-the-word/description/
#include "xxx.h"

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  void findSecretWord(vector<string> &wordlist, Master &master) {
    // 一个单词长6， 猜10次
    for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
      auto candi = wordlist[rand() % (wordlist.size())];
      x = master.guess(candi);
      vector<string> wordlist2;
      for (auto w : wordlist) {
        if (match(candi, w) == x) {
          wordlist2.push_back(w);
        }
      }
      wordlist = wordlist2;
    }
  }

private:
  int match(string a, string b) {
    int matches = 0;
    for (int i = 0; i < a.length(); ++i)
      if (a[i] == b[i])
        matches++;
    return matches;
  }
};
