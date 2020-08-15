// http://leetcode.com/problems/verifying-an-alien-dictionary/description/
#include "xxx.h"

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    vector<string> cp = words;

    // 越大代表顺序越高
    unordered_map<char, int> index;
    for (int i = 0; i < order.size(); i++) {
      index[order[i]] = i;
    }
    sort(words.begin(), words.end(), [&index](string &l, string &r) {
      if (l.empty()) {
        return true;
      }
      int llen = l.size();
      int rlen = r.size();
      int minlen = min(llen, rlen);
      int i = 0;
      for (; i < minlen; i++) {
        // index[l[i]] < index[r[i]];
        auto l1 = index[l[i]];
        auto l2 = index[r[i]];
        if (l1 < l2) {
          return true;
        } else if (l1 > l2) {
          return false;
        }
      }
      if (i == llen) {
        return true;
      }

      return false;
    });
    for (int i = 0; i < words.size(); i++) {
      cout << words[i] << endl;
      if (words[i] != cp[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<string> input{"apple", "app"};
  string order{"abcdefghijklmnopqrstuvwxyz"};
  so.isAlienSorted(input, order);
}
