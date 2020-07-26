// http://leetcode.com/problems/design-underground-system/description/
#include "xxx.h"

class UndergroundSystem {
public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    in_[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto &p = in_[id];
    auto &up = out_[stationName + '>' + p.first];
    up.first += t - p.second;
    up.second += 1;
  }

  double getAverageTime(string startStation, string endStation) {
    auto target = out_[endStation + '>' + startStation];
    return (double)target.first / target.second;
  }

private:
  unordered_map<int, pair<string, int>> in_;
  unordered_map<string, pair<int, int>> out_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

// tle version
#if 0
class UndergroundSystem {
public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    cache_[stationName][id][0] = t;
    // mark as no end
    cache_[stationName][id][1] = -1;
  }

  void checkOut(int id, string stationName, int t) {
    // update end
    cache_[stationName][id][1] = t;
  }

  double getAverageTime(string startStation, string endStation) {
    int count = 0;
    double sum = 0.0;
    auto &start = cache_[startStation];
    for (auto &kv : cache_[endStation]) {
      // 有始有终
      if (kv.second[1] > 0 && start.count(kv.first)) {
        count += 1;
        sum += kv.second[1] - start[kv.first][0];
        // cout << sum << endl;
      }
    }
    if (count == 0) {
      return 0.0;
    }

    // this is insane
    return sum / count;
  }

private:
  unordered_map<string, unordered_map<int, int[2]>> cache_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
#endif
