// http://leetcode.com/problems/queue-reconstruction-by-height/description/
#include "xxx.hpp"

class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
    auto cmp = [](const pair<int, int> &l, const pair<int, int> &r) ->bool {
                 return l.first > r.first || (l.first == r.first && l.second < r.second);
               };
    // 矮子插队无所谓，反正高个子看不到
    // 所以这里的思路就是先把高的排好，然后矮的放在固定的位置即可
    sort(people.begin(), people.end(), cmp);
    vector<pair<int, int>> ret;
    for (auto p : people) {
      ret.insert(ret.begin() + p.second, p);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<pair<int, int>> input {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
  so.reconstructQueue(input);
  for (auto p : input) {
    cout << p.first << "  " << p.second << endl;
  }

}
