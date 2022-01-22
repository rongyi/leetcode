// http://leetcode.com/problems/largest-time-for-given-digits/description/
#include "xxx.hpp"

class Solution {
public:
  // 又被喷的很惨
  string largestTimeFromDigits(vector<int> &A) {
    sort(A.begin(), A.end());
    bool found = false;
    int max_hour = 0;
    // 伴随着的分钟
    int body_min = 0;

    do {
      auto hour = A[0] * 10 + A[1];
      auto min = A[2] * 10 + A[3];
      if (hour > 23 || min > 59) {
        continue;
      }

      found = true;
      if (hour > max_hour) {
        max_hour = hour;
        body_min = min;
      } else if (hour == max_hour) {
        if (min > body_min) {
          body_min = min;
        }
      }

    } while (next_permutation(A.begin(), A.end()));

    if (!found) {
      return "";
    }
    stringstream ss;
    if (max_hour >= 10) {
      ss << max_hour;
    } else {
      ss << '0' << max_hour;
    }
    ss << ':';
    if (body_min >= 10) {
      ss << body_min;
    } else {
      ss << '0' << body_min;
    }

    return ss.str();
  }

  string largestTimeFromDigitsError(vector<int> &A) {
    unordered_map<int, int> count;
    for (auto i : A) {
      count[i]++;
    }
    // 2 3 : 5 9
    // 0 0   0 0
    // 1 1   1 1
    // 2 2   2 2
    //   3   3 3
    //       4 4
    //       5 5
    //         6
    //         7
    //         8
    //         9
    // not valid condition
    // if (count[5] > 2 || count[4] > 2 || count[3] > 3) {
    //   return "";
    // }
    // // 6 7 8 9总共只能出现一次
    // int totalbig = 0;
    // for (int i = 6; i <= 9; i++) {
    //   totalbig += count[i];
    //   if (totalbig > 1) {
    //     return "";
    //   }
    // }

    string ret{};
    int last = -1;
    bool found = false;
    for (int i = 2; i >= 0; i--) {
      if (count[i]) {
        last = i;
        ret += to_string(i);
        --count[i];
        found = true;
        break;
      }
    }

    if (!found) {
      return "";
    }
    // 20 21 22 23
    if (last == 2) {
      bool found = false;
      for (int i = 3; i >= 0; i--) {
        if (count[i]) {
          ret += to_string(i);
          --count[i];
          found = true;
          break;
        }
      }
      if (!found) {
        return "";
      }
    } else {
      // the second digit is a free choice
      for (int i = 9; i >= 0; i--) {
        if (count[i]) {
          ret += to_string(i);
          --count[i];
          break;
        }
      }
    }

    ret.push_back(':');

    found = false;
    for (int i = 5; i >= 0; i--) {
      if (count[i]) {
        ret += to_string(i);
        --count[i];
        found = true;
        break;
      }
    }

    if (!found) {
      return "";
    }

    for (auto kv : count) {
      if (kv.second > 0) {
        ret += to_string(kv.first);
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4};
  auto ret = so.largestTimeFromDigits(input);
  cout << ret << endl;
}
