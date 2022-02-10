// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
#include "xxx.hpp"

class Solution {
public:
  // 30 ms, faster than 33.53% of C++
  // what?
  int minimumBuckets(string s) {
    int bucket = 0;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      if (s[i] == 'H') {
        // has bucket at its left
        if (i > 0 && s[i - 1] == 'B') {
          continue;
        }

        // put bucket at its right
        if (i < sz - 1 && s[i + 1] == '.') {
          bucket++;
          // change it to make right H to just use this bucket
          s[i + 1] = 'B';
          continue;
        }

        // put bucket at its left
        if (i > 0 && s[i - 1] == '.') {
          bucket++;
          // change to bucket has no effect
          continue;
        }

        return -1;
      }
    }

    return bucket;
  }
};

class SolutionShit {
public:
  // this shit result:
  // Runtime: 20 ms, faster than 87.34% of C++ online submissions
  int minimumBuckets(string s) {
    int sz = s.size();
    if (sz == 1 && s[0] == 'H') {
      return -1;
    }
    if (sz == 2 && s == "HH") {
      return -1;
    }
    int bucket = 0;
    // find H.H
    for (int i = 0; i < sz - 2;) {
      // HHH or HHHH will have houses no bucket
      if (s[i] == 'H' && s[i + 1] == 'H' && s[i + 2] == 'H') {
        return -1;
      } else if (i == 0 && s[i] == 'H' && s[i + 1] == 'H') {
        // HH at beginning is not valid
        return -1;
      } else if (i == sz - 3 && s[i + 1] == 'H' && s[i + 2] == 'H') {
        // HH at end
        return -1;
      } else if (s[i] == 'H' && s[i + 1] == '.' && s[i + 2] == 'H') {
        bucket++;
        s[i] = 'X';
        s[i + 1] = 'B';
        s[i + 2] = 'X';
        i += 3;
      } else {
        i++;
      }
    }

    for (int i = 0; i < sz; ++i) {
      if (s[i] == '.') {
        if (i > 0 && s[i - 1] == 'H') {
          bucket++;
          s[i - 1] = 'X';
        }
        if (i < sz - 1 && s[i + 1] == 'H') {
          bucket++;
          s[i + 1] = 'X';
        }
      }
    }

    // check for houses have no bucket
    for (auto &c : s) {
      if (c == 'H') {
        return -1;
      }
    }

    return bucket;
  }
};

int main() {
  Solution so;
  so.minimumBuckets(".H..H.HH");
}
