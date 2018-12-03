// http://leetcode.com/problems/reconstruct-itinerary/description/
#include "simpleone.h"

// Hierholzer’s Algorithm
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B
class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto kv : tickets) {
      cache_[kv.first].insert(kv.second);
    }
    visit("JFK");

    return vector<string>(route_.rbegin(), route_.rend());
  }

private:
  void visit(string airport) {
    while (cache_[airport].size()) {
      string next = *cache_[airport].begin();
      cache_[airport].erase(cache_[airport].begin());

      visit(next);
    }
    route_.push_back(airport);
  }

private:
  map<string, multiset<string>> cache_;
  vector<string> route_;
};

int main() {
  Solution so;
  // vector<pair<string, string>>
  // input{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
  vector<pair<string, string>> input{
      {"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
  auto ret = so.findItinerary(input);
  for (auto &s : ret) {
    cout << s << "  ";
  }
  cout << endl;
}
