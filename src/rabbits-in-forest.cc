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
