// http://leetcode.com/problems/count-the-repetitions/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/count-the-repetitions/discuss/119679/brutal-force-%2B-optimization-easy-understanding-c%2B%2B
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    int j = 0;
    const int len1 = s1.length();
    const int len2 = s2.length();

    while (count1 < n1) {
      if (s1[i] == s2[j]) {
        j += 1;
        if (j == len2) {
          j = 0;
          count2 += 1;
        }
      }
      i += 1;
      if (i == len1) {
        i = 0;
        count1 += 1;
      }
    }

    return count2 / n2;
  }
};

int main() {
  Solution so;
  auto ret = so.getMaxRepetitions("abab", 5, "aabb", 1);
  cout << ret << endl;
}
