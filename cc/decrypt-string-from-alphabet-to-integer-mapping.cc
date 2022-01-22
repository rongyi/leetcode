// http://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/description/
#include "xxx.hpp"

class Solution {
public:
  string freqAlphabets(string s) {
    const int n = s.size();
    ostringstream ss;
    for (int i = 0; i < n; i++) {
      // it's a unit
      if (i + 2 < n && s[i + 2] == '#') {
        int sum = 0;
        sum = sum * 10 + (s[i] - '0');
        sum = sum * 10 + (s[i + 1] - '0');
        char c = 'a' + sum - 1;
        ss << c;
        i += 2;
      } else {
        char c = 'a' + (s[i] - '0') - 1;
        ss << c;
      }
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  cout << so.freqAlphabets("10#11#12") << endl;
}
