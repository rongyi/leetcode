// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
#include "xxx.hpp"

class Solution {
public:
  bool areNumbersAscending(string s) {
    int sz = s.size();
    int prev = numeric_limits<int>::min();
    for (int i = 0; i < sz;) {
      // don't care number or regular word
      // just parse it
      int j = i;
      while (j < sz && s[j] != ' ') {
        j++;
      }

      auto cur = s.substr(i, j - i);
      // the first is not digit, then
      // it is not a number string
      if (isdigit(s[i])) {
        int curi = stoi(cur);
        if (curi <= prev) {
          return false;
        }
        prev = curi;
      }

      // a new round start
      i = j + 1;
    }

    return true;
  }
};

int main() {
  Solution so;
  so.areNumbersAscending(
      "1 box has 3 blue 4 red 6 green and 12 yellow marbles");
}
