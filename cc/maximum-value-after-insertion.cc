// http://leetcode.com/problems/maximum-value-after-insertion/description/
#include "xxx.hpp"

class Solution {
public:
  string maxValue(string n, int x) {
    int sz = n.size();
    string xs = to_string(x);
    bool isnegative = (n[0] == '-');
    // negative?
    int i = 0;
    // for postive, we find the first num smaller than cur, insert at this place
    // for negative, we find the first num bigger than cur, insert at this place
    for (; i < sz; ++i) {
      if (isnegative) {
        if (x < (n[i] - '0')) {
          n.insert(i, xs);
          break;
        }
      } else {
        if (x > (n[i] - '0')) {
          n.insert(i, xs);
          break;
        }
      }
    }

    if (i == sz) {
      n.insert(i, xs);
    }

    return n;
  }
};

int main() {
  string s{"hello"};
  s.insert(0, "hh");
  cout << s << endl;
}
