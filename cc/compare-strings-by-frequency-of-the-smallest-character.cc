// http://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
#include "xxx.hpp"

class Solution {
public:
  // 又被喷的很惨
  vector<int> numSmallerByFrequency(vector<string> &queries,
                                    vector<string> &words) {
    vector<int> qcount;
    vector<int> wcount;
    for (auto &q : queries) {
      qcount.push_back(count(q));
    }
    for (auto &w : words) {
      wcount.push_back(count(w));
    }
    sort(wcount.begin(), wcount.end());
    vector<int> ret;
    for (int i = 0; i < qcount.size(); ++i) {
      auto u = upper_bound(wcount.begin(), wcount.end(), qcount[i]);
      ret.push_back(wcount.end() - u);
    }

    return ret;
  }
  int count(string &s) {
    auto c = *min_element(s.begin(), s.end());
    return count_if(s.begin(), s.end(), [&c](char cur) { return cur == c; });
  }
};

int main() {
  Solution so;
  string input{"dcce"};
  cout << so.count(input) << endl;
}
