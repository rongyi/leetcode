// http://leetcode.com/problems/flood-fill/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    m_ = image.size();
    n_ = image[0].size();
    dirs_ = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    const int tip = image[sr][sc];
    vector<vector<bool>> visited(m_, vector<bool>(n_, false));
    dfs(image, visited, tip, newColor, sr, sc);

    return image;
  }

private:
  void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited,
           const int tip, const int overwrite, int x, int y) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_ || visited[x][y] ||
        image[x][y] != tip) {
      return;
    }
    visited[x][y] = true;
    image[x][y] = overwrite;
    for (int i = 0; i < 4; i++) {
      auto nx = dirs_[i][0] + x;
      auto ny = dirs_[i][1] + y;
      dfs(image, visited, tip, overwrite, nx, ny);
    }
  }

private:
  int m_;
  int n_;
  vector<vector<int>> dirs_;
};
