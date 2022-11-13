// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
#include "xxx.hpp"

class Solution {
public:
  // cost me two hours
  string robotWithString(string s) {
    int sz = s.size();
    vector<int> after_min_idx(sz, 0);
    char min_val = 'z' + 1;
    int min_idx = sz - 1;
    for (int i = sz - 1; i >= 0; --i) {
      if (s[i] < min_val) {
        min_val = s[i];
        min_idx = i;
      }
      after_min_idx[i] = min_idx;
    }
    string paper{};
    string t{};
    for (int i = 0; i < sz; ++i) {
      // means we just push this number in stack
      if (i < after_min_idx[i]) {
        // before push this number, we want to check if there are
        // equal value in stack, if we have, we pop this value
        // and because this may cause chain action
        // i.e. the smaller value may exposed to stack's top
        // so we use while to activate this chain action
        // e.g. t ['a', 'b']
        // and current value is 'b'
        // so we don't use current 'b' , instead we use 'b' in the top stack
        // just becuase some smaller value may be depressed in this stack
        // we want to release them
        while (!t.empty() && t.back() <= s[after_min_idx[i]]) {
          paper.push_back(t.back());
          t.pop_back();
        }
        t.push_back(s[i]);
      } else if (i == after_min_idx[i]) {
        // there are two options to push char to paper
        // one is this current number
        // and the other is top stack
        // we pick the smaller one
        // and activate the chain action using while
        // before this last nubmer is pushed to paper
        // we want all smaller string in stack to go to paper first
        while (!t.empty() && t.back() <= s[i]) {
          paper.push_back(t.back());
          t.pop_back();
        }
        paper.push_back(s[i]);
      }
    }
    // the left char in stack will go out reversely
    reverse(t.begin(), t.end());

    return paper + t;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  // string input{"vzhofnpo"};
  //  string input{"bac"};
  string input{"mmuqezwmomeplrtskz"};
  cout << so.robotWithString(input) << endl;

  return 0;
}
