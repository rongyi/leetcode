// http://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/
#include "xxx.h"

class Solution {
public:
  int minDeletions(string s) {
    int ret = 0;
    vector<int> count(26, 0);
    for (auto &c : s) {
      count[c - 'a']++;
    }

    // 按照个数从少到多排列
    sort(s.begin(), s.end(), [&count](char &l, char &r) -> bool {
      if (count[l - 'a'] == count[r - 'a']) {
        return l < r;
      }
      return count[l - 'a'] < count[r - 'a'];
    });

    char prev = '0';
    int prev_index = 0;
    set<int> group;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != prev) {
        prev = s[i];

        int cur_count = i - prev_index;
        prev_index = i;
        if (cur_count > 0) {
          bool done = false;
          for (int dstart = cur_count; dstart > 0; dstart--) {
            if (!group.count(dstart)) {
              group.insert(dstart);
              ret += cur_count - dstart;
              done = true;
              break;
            }
          }
          // 删光了
          if (!done) {
            ret += cur_count;
          }
        }
      }
    }

    // 最后一个情况
    int cur_count = s.size() - prev_index;

    bool done = false;
    for (int dstart = cur_count; dstart > 0; dstart--) {
      if (!group.count(dstart)) {
        group.insert(dstart);
        ret += cur_count - dstart;
        done = true;
        break;
      }
    }
    // 删光了

    if (!done) {
      ret += cur_count;
    }

    return ret;
  }
};

int main() {
  Solution so;
  so.minDeletions("bbcebab");
}
