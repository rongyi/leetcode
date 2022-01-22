// http://leetcode.com/problems/decoded-string-at-index/description/
#include "xxx.hpp"

class Solution {
public:
  // 用递归的思路去做
  string decodeAtIndex(string S, int K) {
    return dorepeat(S, 0, S.size() - 1, K);
  }
  string decodeAtIndexMLE(string S, int K) {
    string tape;
    for (auto c : S) {
      if (tape.size() >= K) {
        break;
      }
      if (isdigit(c)) {
        int repeat = c - '0' - 1;
        auto origin = tape;
        for (int i = 0; i < repeat; i++) {
          tape += origin;
          // cout << tape << endl;
          if (tape.size() >= K) {
            break;
          }
        }
      } else {
        tape.push_back(c);
        if (tape.size() >= K) {
          break;
        }
      }
    }
    return string{tape[K - 1]};
  }

private:
  string dorepeat(string &str, int start, int end, int k) {
    long long cnt = 0;
    for (int i = start; i <= end; i++) {
      if (isdigit(str[i])) {
        int num = str[i] - '0' - 1;
        long long oldcnt = cnt;
        while (num) {
          cnt += oldcnt;
          if (cnt >= k) {
            // 多出那一块去掉
            // 显然，结束应该在这个位置之前
            return dorepeat(str, start, i - 1, k - (cnt - oldcnt));
          }
          --num;
        }
      } else {
        ++cnt;
        if (cnt == k) {
          return string{str[i]};
        }
      }
    }
    return "";
  }
};

int main() {
  Solution so;
  cout << so.decodeAtIndex("a2b3c4d5e6f7g8h9", 10) << endl;
}
