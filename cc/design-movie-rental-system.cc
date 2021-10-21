// http://leetcode.com/problems/design-movie-rental-system/description/
#include "xxx.h"

class MovieRentingSystem {
public:
  MovieRentingSystem(int _, vector<vector<int>> &entries) {
    // e: shop, movie, price
    for (auto &e : entries) {
      // insert the price
      // [shop]at[movie] -> price
      price_[e[0]][e[1]] = e[2];
      avail_[e[1]].insert({e[2], e[0]});
    }
  }

  // unrented e.g search in available
  vector<int> search(int movie) {
    vector<int> ret;
    for (auto &p : avail_[movie]) {
      ret.push_back(p.second);
      if (ret.size() >= 5) {
        break;
      }
    }

    return ret;
  }

  void rent(int shop, int movie) {
    auto p = price_[shop][movie];
    // insert to rented_
    rented_.insert({p, shop, movie});
    // delete from avail_
    // movie -> {price, shop}
    avail_[movie].erase(avail_[movie].find({p, shop}));
  }

  void drop(int shop, int movie) {
    auto p = price_[shop][movie];
    // insert in avail_
    // movie -> {price, shop}
    avail_[movie].insert({p, shop});
    // delete in rented_
    // {price, shop, movie}
    rented_.erase(rented_.find({p, shop, movie}));
  }

  vector<vector<int>> report() {
    vector<vector<int>> ret;

    for (auto &r : rented_) {
      ret.push_back({r[1], r[2]});
      if (ret.size() >= 5) {
        break;
      }
    }

    return ret;
  }

private:
  // {price, shop, movie}, for report
  set<array<int, 3>> rented_;
  // [shop]at[movie] -> price
  // NOTE shop is way smaller than movie
  // if I choose the first key as movie, we get TLE
  // I think this is unrelevent, but it's not
  unordered_map<int, unordered_map<int, int>> price_;
  // movie -> {price, shop}
  unordered_map<int, set<pair<int, int>>> avail_;
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
