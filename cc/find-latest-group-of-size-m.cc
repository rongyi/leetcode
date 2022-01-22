// http://leetcode.com/problems/find-latest-group-of-size-m/description/
#include "xxx.hpp"

class Solution {
public:
  int findLatestStep(vector<int> &arr, int m) {
    int ret = -1;
    int n = arr.size();
    if (n == m) {
      return n;
    }
    vector<int> len(n + 2, 0);
    for (int i = 0; i < n; ++i) {
      int a = arr[i];
      int left = len[a - 1];
      int right = len[a + 1];
      len[a - left] = len[a + right] = left + right + 1;
      if (left == m || right == m) {
        ret = i;
      }
    }

    return ret;
  }
  int findLatestStepNaiveTLE(vector<int> &arr, int m) {
    vector<unordered_set<int>> cnt;
    int n = arr.size();
    string layout(n, '0');
    for (int i = 0; i < arr.size(); ++i) {
      layout[n - arr[i]] = '1';
      cnt.push_back(groups(layout));
    }
    for (int i = cnt.size() - 1; i >= 0; --i) {
      if (cnt[i].find(m) != cnt[i].end()) {
        return i + 1;
      }
    }

    return -1;
  }

public:
  unordered_set<int> groups(string s) {
    unordered_set<int> ret;
    int i = 0;
    int start = 0;
    bool has_start = false;
    while (i < s.size()) {
      if (s[i] == '0') {
        if (has_start) {
          auto len = i - start;
          ret.insert(len);
          has_start = false;
        }
      } else {
        if (!has_start) {
          start = i;
          has_start = true;
        }
      }
      i++;
    }
    if (has_start) {
      ret.insert(s.size() - start);
    }

    return ret;
  }
};

int main() {
  Solution so;
  // string s{"10111"};
  // auto ret = so.groups(s);
  // for (auto l : ret) {
  //   cout << l << endl;
  // }

  vector<int> input{3, 5, 1, 2, 4};
  so.findLatestStep(input, 2);
}
