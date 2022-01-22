// http://leetcode.com/problems/number-of-different-integers-in-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  int numDifferentIntegers(string word) {
    set<string> count;
    int start_idx = -1;
    const int n = word.size();
    for (int i = 0; i < word.size();) {
      if (isdigit(word[i])) {
        start_idx = i;
        while (i < word.size() && isdigit(word[i])) {
          i++;
        }
        // leading zero, no all zero
        while (start_idx < i - 1 && word[start_idx] == '0') {
          start_idx++;
        }

        count.insert(word.substr(start_idx, i - start_idx));
      } else {
        i++;
      }
    }

    return count.size();
  }
};

int main() {
  Solution so;
  auto ret = so.numDifferentIntegers("a123bc34d8ef34");
  cout << ret << endl;
}
