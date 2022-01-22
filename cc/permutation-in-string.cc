// http://leetcode.com/problems/permutation-in-string/description/
#include "xxx.hpp"

class Solution {
public:
  // naive TLE
  bool checkInclusionTLE(string s1, string s2) {
    sort(s1.begin(), s1.end());
    do {
      if (s2.find(s1) != string::npos) {
        return true;
      }
    } while (next_permutation(s1.begin(), s1.end()));
    return false;
  }
  bool checkInclusion(string s1, string s2) {
    const int m = s1.size();
    const int n = s2.size();
    if (m > n) {
      return false;
    }
    // every single char count in s1
    vector<int> count(26, 0);
    for (int i = 0; i < m; i++) {
      // 拥有的字符资源统计
      count[s1[i] - 'a']++;
      // 此时罩在s2上的第一个sliding window上的使用情况
      count[s2[i] - 'a']--;
    }
    // 使用的干干净净
    if (allzero(count)) {
      return true;
    }
    // 否则，sliding window 朝前滑动
    for (int i = m; i < n; i++) {
      // 滑进来的是使用了某个字符资源
      count[s2[i] - 'a']--;
      // 滑出去的是释放该字符资源
      count[s2[i - m] - 'a']++;
      if (allzero(count)) {
        return true;
      }
    }
    return false;
  }

private:
  bool allzero(vector<int> &input) {
    for (auto i : input) {
      if (i != 0) {
        return false;
      }
    }
    return true;
  }
};
