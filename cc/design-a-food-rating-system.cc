// https://leetcode.com/problems/design-a-food-rating-system/
#include "xxx.hpp"

class FoodRatings {
public:
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    int sz = foods.size();
    for (int i = 0; i < sz; ++i) {
      auto fd = foods[i];
      auto scr = ratings[i];
      auto cuis = cuisines[i];

      food_score_[fd] = scr;
      food_cuisine_[fd] = cuis;

      cuisine_food_by_score_[cuis].insert({-scr, fd});
    }
  }

  void changeRating(string food, int newRating) {
    auto old_score = food_score_[food];
    food_score_[food] = newRating;

    cuisine_food_by_score_[food_cuisine_[food]].erase({-old_score, food});
    cuisine_food_by_score_[food_cuisine_[food]].insert({-newRating, food});
  }

  string highestRated(string cuisine) {
    return cuisine_food_by_score_[cuisine].begin()->second;
  }

private:
  map<string, int> food_score_;
  map<string, string> food_cuisine_;
  // cuisine -> {-score, foodname}
  map<string, set<pair<int, string>>> cuisine_food_by_score_;
};

#if 0

// original answer

class FoodRatings {
public:
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    int sz = foods.size();
    for (int i = 0; i < sz; ++i) {
      auto fd = foods[i];
      auto scr = ratings[i];
      auto cuis = cuisines[i];

      food_score_[fd] = scr;
      food_cuisine_[fd] = cuis;

      cuisine_food_by_score_[cuis][scr].insert(fd);
    }
  }

  void changeRating(string food, int newRating) {
    auto old_score = food_score_[food];
    food_score_[food] = newRating;

    cuisine_food_by_score_[food_cuisine_[food]][old_score].erase(food);
    // don't forget this
    if (cuisine_food_by_score_[food_cuisine_[food]][old_score].empty()) {
      cuisine_food_by_score_[food_cuisine_[food]].erase(old_score);
    }

    cuisine_food_by_score_[food_cuisine_[food]][newRating].insert(food);
  }

  string highestRated(string cuisine) {
    auto hi_set = cuisine_food_by_score_[cuisine].end();
    hi_set = prev(hi_set);

    // with lexicographically smallest
    return *(hi_set->second.begin());
  }

private:
  map<string, int> food_score_;
  map<string, string> food_cuisine_;
  // cuisine -> {score -> {food set}}
  map<string, map<int, set<string>>> cuisine_food_by_score_;
};

#endif
