// http://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/
#include "xxx.h"

class Solution {
public:
  vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies) {
    set<string> compy_set;
    for (auto &cps : favoriteCompanies) {
      for (auto &c : cps) {
        compy_set.insert(c);
      }
    }
    unordered_map<string, int> compy_indx;
    int i = 1;
    for (auto &cmp : compy_set) {
      compy_indx[cmp] = i++;
    }

    // 这里的bitset换成int就不行了，题目考的也是这点，坑爹，意思到位就行了
    vector<bitset<50001>> compy_masks;
    for (auto &cps : favoriteCompanies) {
      bitset<50001> cur;
      for (auto &c : cps) {
        cur[compy_indx[c]] = 1;
      }
      compy_masks.push_back(cur);
    }

    vector<int> ret;
    for (int i = 0; i < compy_masks.size(); ++i) {
      bool flag = true;
      for (int j = 0; j < compy_masks.size(); ++j) {
        if (i == j) {
          continue;
        }
        if ((compy_masks[i] & compy_masks[j]) == compy_masks[i]) {
          flag = false;
          break;
        }
      }

      if (flag) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};

int main() {
  vector<vector<string>> input{{"leetcode", "google", "facebook"},
                               {"google", "microsoft"},
                               {"google", "facebook"},
                               {"google"},
                               {"amazon"}};
  Solution so;
  so.peopleIndexes(input);
}
