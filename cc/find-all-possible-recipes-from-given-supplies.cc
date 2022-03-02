// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#include "xxx.hpp"

class SolutionBruteForce {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    bool round = true;
    unordered_set<string> spls(supplies.begin(), supplies.end());
    int sz = recipes.size();
    vector<bool> vis(sz, false);
    vector<string> ret;

    // there's no start endtrypoint, we use a loop to check all
    while (round) {
      round = false;
      for (int i = 0; i < sz; ++i) {
        if (vis[i]) {
          continue;
        }
        bool can_make = true;
        for (auto &g : ingredients[i]) {
          if (spls.find(g) == spls.end()) {
            can_make = false;
            break;
          }
        }
        if (can_make) {
          vis[i] = true;
          round = true;
          // recipes[i] as ingredients for other recipes
          spls.insert(recipes[i]);
        }
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (vis[i]) {
        ret.push_back(recipes[i]);
      }
    }

    return ret;
  }
};
