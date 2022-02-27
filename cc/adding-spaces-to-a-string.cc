// https://leetcode.com/problems/adding-spaces-to-a-string/
#include "xxx.hpp"

class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    string ret{};
    for (int i = 0, idx = 0; i < s.size(); ++i) {
      if (idx < spaces.size() && i == spaces[idx]) {
        ret.push_back(' ');
        idx++;
      }
      ret.push_back(s[i]);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 5, 7, 9};
  cout << so.addSpaces("icodeinpython", input) << endl;
}
