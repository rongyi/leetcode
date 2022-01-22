// http://leetcode.com/problems/anagram-mapping/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
    vector<int> ret;
    unordered_map<int, int> dict;
    for (int i = 0; i < B.size(); ++i) {
      dict[B[i]] = i;
    }

    for (int i = 0; i < A.size(); ++i) {
      ret.push_back(dict[A[i]]);
    }
    return ret;
  }
};
