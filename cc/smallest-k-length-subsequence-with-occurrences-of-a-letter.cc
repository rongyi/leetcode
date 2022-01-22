// https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/
#include "xxx.hpp"

class Solution {
public:
  string smallestSubsequence(string s, int k, char target, int repetition) {
    int sz = s.size();
    int remain = count(s.begin(), s.end(), target);
    string stack;
    for (int i = 0; i < sz; ++i) {
      while (!stack.empty() && stack.back() > s[i] &&
             /*There are enough characters left to construct a k-size string*/
             (sz - i + stack.size() > k)
             /* If the character to be popped is the same as letter, then there
              should also be at least r character letter left.*/
             && (stack.back() != target || remain > repetition)) {
        if (stack.back() == target) {
          repetition++;
        }
        stack.pop_back();
      }
      if (stack.size() < k) {
        // When adding new element to stack, we just need to
        // 1. check if the stack is already full (has size of k),
        // 2. and if the character is not the same as letter, then also check if
        //    we are leaving enough space for the matching characters.
        if (s[i] == target) {
          stack += s[i];
          repetition--;
        } else if (k - (int)stack.size() >
                   repetition) { // the left space must reserver repetition pos
                                 // for
                                 // target
          stack += s[i];
        }
      }
      if (s[i] == target) {
        remain--;
      }
    }

    return stack;
  }
};
int main() {
  Solution so;
  cout << so.smallestSubsequence("acde", 3, 'e', 1) << endl;
}
