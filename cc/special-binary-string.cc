// https://leetcode.com/problems/special-binary-string/description/
#include "xxx.hpp"

class Solution {
public:
  string makeLargestSpecial(string S) {
    if (S == "") {
      return "";
    }
    const int n = S.size();
    string ret;
    int start = 0;
    // when encounter '1' plus 1, '0' minus 1, when equal to 0, we know we get paired 1, 0
    int count = 0;
    vector<string> paired_subgroup;

    for (int i = 0; i < n; ++i) {
      if (S[i] == '1') {
        count += 1;
      } else {
        count -= 1;
      }
      if (count == 0) {
        paired_subgroup.push_back("1" + makeLargestSpecial(S.substr(start + 1, i - start - 1)) + "0");
        start = i + 1;
      }
    }

    sort(paired_subgroup.begin(), paired_subgroup.end(), greater<string>());

    ret = accumulate(paired_subgroup.begin(), paired_subgroup.end(), ret);

    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.makeLargestSpecial("11011000");
  cout << ret << endl;
}
