// http://leetcode.com/problems/search-suggestions-system/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &ps,
                                           string searchWord) {
    sort(ps.begin(), ps.end());
    vector<vector<string>> ret(searchWord.size());
    for (int l = 1; l <= searchWord.size(); ++l) {
      auto w = searchWord.substr(0, l);
      auto it = lower_bound(ps.begin(), ps.end(), w);
      for (; it != ps.end() && it->substr(0, l) == w && ret[l - 1].size() < 3;
           ++it) {
        ret[l - 1].push_back(*it);
      }
    }
    return ret;
  }
};
int main() {
  vector<string> input{"ca", "ma", "mb", "mbc"};
  auto it = lower_bound(input.begin(), input.end(), "mb");
  cout << *it << endl;
}
