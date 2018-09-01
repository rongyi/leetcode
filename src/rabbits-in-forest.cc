// https://leetcode.com/problems/rabbits-in-forest/description/
#include "one.h"

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    if (answers.empty()) {
      return 0;
    }
    unordered_map<int, int> dict;
    int ret = 0;
    for (auto an : answers) {
      if (an == 0) {
        ++ret;
      }
      if (dict.find(an) == dict.end()) {
        dict[an] = an + 1;      // include himself
      }
    }
    for (auto kv : dict) {
      ret += kv.second;
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
