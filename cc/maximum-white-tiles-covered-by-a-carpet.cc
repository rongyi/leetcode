// https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/
#include "xxx.hpp"

class Solution {
public:
  int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());
    int sz = tiles.size();
    // methos: count holes
    // start point holes
    map<int, int> holes;
    // start -> end
    map<int, int> end_mark;
    holes[tiles[0][0]] = 0;
    int hole_sum = 0;
    for (int i = 0; i < sz; ++i) {
      end_mark[tiles[i][0]] = tiles[i][1];
    }
    for (int i = 1; i < sz; ++i) {
      hole_sum += tiles[i][0] - tiles[i - 1][1] - 1;
      holes[tiles[i][0]] = hole_sum;
    }
    int ret = 0;

    for (int i = 0; i < sz; ++i) {
      int range_start = tiles[i][0];
      int carpet_cover_end = range_start + carpetLen - 1;
      auto last_in_start_it = prev(holes.upper_bound(carpet_cover_end));
      auto last_in_end = end_mark[last_in_start_it->first];
      auto holes_prefix = holes[last_in_start_it->first];

      // range like this:
      // ---------------------------- carpet cover
      //                     |        last tile end
      //                     |<-----> this is also holes
      if (last_in_end < carpet_cover_end) {
        holes_prefix += carpet_cover_end - last_in_end;
      }

      holes_prefix -= holes[range_start];

      ret = max(ret, carpetLen - holes_prefix);
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{{1, 1}};
  so.maximumWhiteTiles(input, 1);
  return 0;
}
