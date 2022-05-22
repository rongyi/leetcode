// https://leetcode.com/problems/substring-with-largest-variance/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/substring-with-largest-variance/discuss/2039178/Weird-Kadane
  int largestVariance(string s) {
    int ret = 0;
    set<char> uniq(s.begin(), s.end());
    // assume a is the bigger one
    // and b is the smaller one
    for (char a : uniq) {
      for (char b : uniq) {
        int blc = 0;
        bool has_b = false;
        bool first_b = false;
        for (auto cur : s) {
          blc += (cur == a);
          if (cur == b) {
            has_b = true;
            // this means we crop the begin b
            // because we met b again, so the blc is not change
            // minus current b, and crop begin b(plus 1)
            // the blc is not change
            if (first_b && blc >= 0) {
              first_b = false;
            } else if (--blc < 0) {
              first_b = true;
              // only one b is enough
              blc = -1;
            }
          }

          if (has_b) {
            ret = max(ret, blc);
          }
        }
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.largestVariance("aabbbbaabbbaaaaba");
  return 0;
}
