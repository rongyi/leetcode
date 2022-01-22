// http://leetcode.com/problems/generate-random-point-in-a-circle/description/
#include "xxx.hpp"

class Solution {
public:
  Solution(double radius, double x_center, double y_center)
      : radius_(radius), x_(x_center), y_(y_center) {}

  vector<double> randPoint() {
    // 随机一个角度
    double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
    // 随机一个长度
    // 我们不能把圆这样看成是很多半径的集合——或者说，这条半径上不同位置的点的密集程度是不一样的。显然距离圆心更远的一端被选择的概率应该更大。
    // 如果不用平方根的话，那么表示圆的时候
    // (len * cos(theta)) ^ 2 + (len * sin(theta) ^ 2，
    // 这里就相当于对随机出的[0, 1]
    // 中的小数平方了，那么其就不是等概率的了
    double len = sqrt((double)rand() / RAND_MAX) * radius_;

    // 极坐标表示法
    return {x_ + len * cos(theta), y_ + len * sin(theta)};
  }

private:
  double radius_;
  double x_;
  double y_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
