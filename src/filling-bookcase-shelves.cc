// http://leetcode.com/problems/filling-bookcase-shelves/description/
#include "xxx.h"

class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelf_width,
                       int cur_index = 0, int cur_width = 0,
                       int cur_height = 0) {
    if (cur_index >= books.size()) {
      return cur_height;
    }
    if (dp_[cur_index][cur_width] != 0) {
      return dp_[cur_index][cur_width];
    }
    dp_[cur_index][cur_width] = min(
        // 重新开一层，作为这一个新层的第一个
        cur_height + minHeightShelves(books, shelf_width, cur_index + 1,
                                      books[cur_index][0], books[cur_index][1]),
        // 放一起, 高度就是最高的那个
        cur_width + books[cur_index][0] > shelf_width
            ? numeric_limits<int>::max()
            : minHeightShelves(books, shelf_width, cur_index + 1,
                               cur_width + books[cur_index][0],
                               max(cur_height, books[cur_index][1])));
    return dp_[cur_index][cur_width];
  }

private:
  int dp_[1001][1001];
};
