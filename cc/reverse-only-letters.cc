// http://leetcode.com/problems/reverse-only-letters/description/
#include "xxx.hpp"

class Solution {
public:
  string reverseOnlyLetters(string S) {
    const int n = S.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
      while (i < j && !isalpha(S[i])) {
        i++;
      }
      while (j > i && !isalpha(S[j])) {
        j--;
      }
      swap(S[i], S[j]);
      i++;
      j--;
    }
    return S;
  }
};

int main() {
  Solution so;
  auto ret = so.reverseOnlyLetters("?6C40E");
  cout << ret << endl;
}
