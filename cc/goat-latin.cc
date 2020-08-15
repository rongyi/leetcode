// http://leetcode.com/problems/goat-latin/description/
#include "xxx.h"

class Solution {
public:
  string toGoatLatin(string S) {
    unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    istringstream ss(S);
    string cur{};
    ostringstream ret;
    int acount = 1;
    while (ss >> cur) {

      if (vowel.find(cur[0]) != vowel.end()) {
        ret << cur << "ma" << string(acount++, 'a');
      } else {
        ret << cur.substr(1) << cur[0] << "ma" << string(acount++, 'a');
      }
      ret << " ";
    }
    string s = ret.str();
    s.pop_back();

    return s;
  }
};

int main() {
  // Solution so;
  cout << string(2, 'a') << endl;
}
