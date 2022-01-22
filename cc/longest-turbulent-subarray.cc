// http://leetcode.com/problems/longest-turbulent-subarray/description/
#include "xxx.hpp"

class Solution {
public:
  int maxTurbulenceSize(vector<int> &A) {
    if (A.size() < 2) {
      return A.size();
    }
    // 0 ==
    // 1 <
    // 2 >
    vector<int> normals;
    for (int i = 0; i < A.size() - 1; i++) {
      if (A[i] < A[i + 1]) {
        normals.push_back(1);
      } else if (A[i] > A[i + 1]) {
        normals.push_back(2);
      } else {
        normals.push_back(0);
      }
    }
    // for (auto n : normals) {
    //   cout << n << " ";
    // }
    // cout << endl;
    int i = 0;
    while (i < normals.size()) {
      if (normals[i] == 0) {
        i++;
        continue;
      }
      break;
    }

    // 说明清一色的相等
    if (i == normals.size()) {
      return 1;
    }
    int prev = normals[i];
    bool start_next = false;
    int cur_len = 1;
    int ret = 0;
    for (int j = i + 1; j < normals.size(); j++) {
      if (normals[j] == 0) {
        start_next = true;

        ret = max(ret, cur_len);
        // cout << "curlena" << cur_len << endl;
        continue;
      }

      if (start_next) {
        start_next = false;
        prev = normals[j];
        cur_len = 1;
        continue;
      }

      if (normals[j] == 3 - prev) {
        cur_len++;
      } else {
        ret = max(ret, cur_len);
        cur_len = 1;
      }
      prev = normals[j];
    }
    ret = max(ret, cur_len);
    return ret + 1;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 8, 45, 88, 48, 68, 28, 55, 17, 24};
  so.maxTurbulenceSize(input);
}
