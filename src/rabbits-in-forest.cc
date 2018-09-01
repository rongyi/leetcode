// https://leetcode.com/problems/rabbits-in-forest/description/
#include "one.h"

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    if (answers.empty()) {
      return 0;
    }
    unordered_map<int, int> canbemet;
    int ret = 0;
    for (auto an : answers) {
      // the are the uniq color rabbit
      if (an == 0) {
        ++ret;
        continue;
      }
      // 拿a[2， 1， 2， 2， 2， 2， 2， 2， 1， 1]来说
      // canbemet意思是遇到第一个2之后后续遇到2的时候能不能把这个兔子纳为一个组（同色）内。
      // 所以第一个2之后，我们还可以把两个2纳为一个颜色内，遇到a[4]这个2时就不能为一组了，因为
      // 已经同色的三个都已经问过了。后面的必须是不同色的。
      if (canbemet.find(an) == canbemet.end()) {
        ret += an + 1;
        canbemet[an] = an;
      } else {
        --canbemet[an];
        if (canbemet[an] == 0) {
          canbemet.erase(an);
        }
      }
    }

    return ret;
  }
};


int main() {
  vector<int> input{1, 0, 1, 0, 0};
  Solution so;
  auto ret = so.numRabbits(input);
  cout << ret << endl;
}
