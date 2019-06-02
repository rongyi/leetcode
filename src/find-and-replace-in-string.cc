// http://leetcode.com/problems/find-and-replace-in-string/description/
#include "xxx.h"

class Solution {
private:
  struct sed {
    int index_;
    string match_;
    string replace_;
  };

public:
  string findReplaceString(string S, vector<int> &indexes,
                           vector<string> &sources, vector<string> &targets) {
    const int n = sources.size();
    vector<sed> seds;

    // 讨厌的是这里的排序，因为index不是按序给出来的
    for (int i = 0; i < n; i++) {
      seds.push_back({indexes[i], sources[i], targets[i]});
    }
    sort(seds.begin(), seds.end(),
         [](const sed &l, const sed &r) { return l.index_ < r.index_; });

    ostringstream ss;
    // indicate the start for next round
    int start = 0;
    for (int i = 0; i < n;) {
      int cur_start = seds[i].index_;
      // 从start到cur_start这一段没有人要过来匹配
      // 所以直接把这段接入新的string
      if (start < cur_start) {
        ss << S.substr(start, cur_start - start);
        start = cur_start;
      } else {
        string match = S.substr(cur_start, seds[i].match_.size());
        if (match == seds[i].match_) {
          ss << seds[i].replace_;
        } else {
          ss << match;
        }
        start = start + seds[i].match_.size();
        i++;
      }
    }
    // last part
    if (start < S.size()) {
      ss << S.substr(start);
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  // "vmokgggqzp"
  vector<int> indexes{3, 5, 1};
  vector<string> sour{"kg", "ggq", "mo"};
  vector<string> target{"s", "so", "bfr"};
  auto ret = so.findReplaceString("vmokgggqzp", indexes, sour, target);
  cout << ret << endl;
}
