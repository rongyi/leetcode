// http://leetcode.com/problems/binary-watch/description/
#include "xxx.hpp"
// page 9 start: 2019年01月18日 星期五 18时59分59秒

class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    // 先算出来，后面直接拿这些值来用。
    // 比bfs肯定要快
    unordered_map<int, unordered_set<int>> hourc;
    unordered_map<int, unordered_set<int>> minc;
    for (int i = 0; i < 12; i++) {
      hourc[countzero(i)].insert(i);
    }
    // including 0 - 12
    for (int i = 0; i < 60; i++) {
      // 有n个1的集合
      minc[countzero(i)].insert(i);
    }

    vector<string> ret;
    for (int i = 0; i <= num; i++) {
      int j = num - i;
      if (hourc.find(i) != hourc.end() && minc.find(j) != minc.end()) {
        auto hset = hourc[i];
        auto mset = minc[j];
        for (auto h : hset) {
          for (auto m : mset) {
            char buff[4];
            ::snprintf(buff, sizeof(buff), "%d", h);
            string buff_hour = buff;
            ::snprintf(buff, sizeof(buff), "%02d", m);
            string buff_min = buff;
            ret.push_back(buff_hour + ":" + buff_min);
          }
        }
      }
    }
    return ret;
  }

private:
  int countzero(int i) {
    int ret = 0;
    while (i) {
      if (i & 1) {
        ret++;
      }
      i >>= 1;
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.readBinaryWatch(1);
  for (auto i : ret) {
    cout << i << endl;
  }
}
