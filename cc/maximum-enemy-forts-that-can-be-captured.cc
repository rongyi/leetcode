// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/
#include "xxx.hpp"

class Solution {
public:
  int captureForts(vector<int> &forts) {
    bool has_one = false;
    bool has_negone = false;
    int ret = 0;
    int prev_one = -1;
    int prev_negone = -1;
    for (int i = 0; i < forts.size(); ++i) {
      if (forts[i] == 1) {
        has_one = true;
        prev_one = i;
        if (has_negone) {
          ret = max(ret, (i - prev_negone - 1));
          has_negone = false;
        }
      }
      if (forts[i] == -1) {
        has_negone = true;
        prev_negone = i;
        if (has_one) {
          ret = max(ret, (i - prev_one - 1));
          has_one = false;
        }
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> input{1, 0, 0, -1, 0, 0, 0, 0, 1};

  so.captureForts(input);

  return 0;
}
