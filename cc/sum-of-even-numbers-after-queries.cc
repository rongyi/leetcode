// http://leetcode.com/problems/sum-of-even-numbers-after-queries/description/
#include "xxx.h"

class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int> &A,
                                  vector<vector<int>> &queries) {
    int cur_sum = 0;
    // current even number sum
    for (auto a : A) {
      if (a % 2 == 0) {
        cur_sum += a;
      }
    }
    vector<int> ret;
    for (auto &q : queries) {
      int target = A[q[1]];
      int plus = q[0] + target;

      if (target % 2 == 1 || target % 2 == -1) {
        if (plus % 2 == 1 || plus % 2 == -1) {
          ret.push_back(cur_sum);
        } else {
          // 奇数变偶数
          cur_sum += plus;
          ret.push_back(cur_sum);
        }
      } else {
        // 偶数变奇数，
        if (plus % 2 == 1 || plus % 2 == -1) {
          cur_sum -= target;
          ret.push_back(cur_sum);
        } else {
          // 偶数 ==> 偶数
          cur_sum += q[0];
          ret.push_back(cur_sum);
        }
      }
      A[q[1]] = plus;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4};
  vector<vector<int>> queries{{-3, 1}};
  so.sumEvenAfterQueries(input, queries);
}
