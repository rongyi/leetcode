// http://leetcode.com/problems/compare-version-numbers/description/
#include "xxx.hpp"

class Solution {
public:
  int compareVersion(string version1, string version2) {
    vector<int> v1 = parse(version1);
    vector<int> v2 = parse(version2);
    int sz1 = v1.size();
    int sz2 = v2.size();

    for (int i = 0; i < max(sz1, sz2); i++) {
      int num1 = i < sz1 ? v1[i] : 0;
      int num2 = i < sz2 ? v2[i] : 0;
      if (num1 < num2) {
        return -1;
      } else if (num1 > num2) {
        return 1;
      }
    }

    return 0;
  }

private:
  vector<int> parse(string &v) {
    vector<int> ret;

    stringstream ss(v);
    string cur;
    while (getline(ss, cur, '.')) {
      ret.push_back(stoi(cur));
    }

    return ret;
  }
};
