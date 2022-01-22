// http://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/
#include "xxx.hpp"

class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    bool changed = true;
    int ret = 0;
    while (!initialBoxes.empty() && changed) {
      changed = false;
      vector<int> newbox;
      for (auto b : initialBoxes) {
        // if we can open this box, just open it
        if (status[b]) {
          changed = true;
          newbox.insert(end(newbox), containedBoxes[b].begin(),
                        containedBoxes[b].end());
          for (auto k : keys[b]) {
            status[k] = 1;
          }
          ret += candies[b];
        } else { // else put this back in queue
          newbox.push_back(b);
        }
      }

      swap(initialBoxes, newbox);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> status{1, 0, 1, 0};
  vector<int> candies{7, 5, 4, 100};
  vector<vector<int>> keys{{}, {}, {1}, {}};
  vector<vector<int>> contained_boxes{{1, 2}, {3}, {}, {}};
  vector<int> initial{0};

  int ret = so.maxCandies(status, candies, keys, contained_boxes, initial);
  cout << ret << endl;
}
