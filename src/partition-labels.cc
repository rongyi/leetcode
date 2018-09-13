// https://leetcode.com/problems/partition-labels/description/
#include "one.h"

class Solution {
public:
  vector<int> partitionLabels(string S) {
    const int n = S.size();
    vector<int> ret;

    unordered_map<char, int> last_index;
    for (int i = 0; i < n; ++i) {
      last_index[S[i]] = i;
    }


    return ret;
  }
};


int main() {
  Solution so;
  // string input{"zababcbacadefegdehijhklij"};
  string input{"zaz"};
  so.partitionLabels(input);
}
