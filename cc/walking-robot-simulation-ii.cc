// https://leetcode.com/problems/walking-robot-simulation-ii/
#include "xxx.hpp"

class Robot {
public:
  Robot(int width, int height)
      : w_(width), h_(height), cur_dir_(0), x_(0), y_(0) {
    dirs_ = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    perimeter_ = 2 * (w_ + h_ - 2);
  }

  void step(int k) {
    if (k >= perimeter_) {
      k %= perimeter_;
      if (x_ == 0 && y_ == 0 && cur_dir_ == 0) {
        cur_dir_ = 3;
      }
    }
    while (k > 0) {
      auto &d = dirs_[cur_dir_];
      int dx = d[0];
      int dy = d[1];
      int nx = x_ + dx;
      int ny = y_ + dy;
      // change direction?
      if (nx < 0 || ny < 0 || nx >= w_ || ny >= h_) {
        cur_dir_ = (cur_dir_ + 1) % 4;
        // just change direction , no move yet, so no --k
      } else {
        x_ = nx;
        y_ = ny;
        --k;
      }
    }
  }

  vector<int> getPos() { return {x_, y_}; }

  string getDir() {
    if (cur_dir_ == 0) {
      return "East";
    } else if (cur_dir_ == 1) {
      return "North";
    } else if (cur_dir_ == 2) {
      return "West";
    }
    return "South";
  }

private:
  // 0 east
  // 1 north
  // 2 west
  // 3 south
  int cur_dir_;
  int w_;
  int h_;

  int x_;
  int y_;
  vector<vector<int>> dirs_;
  int perimeter_;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
