// https://leetcode.com/problems/partition-labels/description/
#include "xxx.h"

class Solution {
public:
  vector<int> partitionLabels(string S) {
    const int n = S.size();
    vector<int> ret;

    // try c++ find_last_of, but this way is awesome!
    unordered_map<char, int> last_index;
    for (int i = 0; i < n; ++i) {
      last_index[S[i]] = i;
    }
    int last = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
      last = max(last, last_index[S[i]]);
      // cout << last << endl;
      if (last == i) {
        ret.push_back(last - start + 1);
        start = last + 1;
        last = 0;
      }
    }


    return ret;
  }
};


int main() {
  Solution so;
  // string input{"zababcbacadefegdehijhklij"};
  string input{"zaz"};
  auto ret = so.partitionLabels(input);
  for (auto l : ret) {
    cout << l << endl;
  }
}
