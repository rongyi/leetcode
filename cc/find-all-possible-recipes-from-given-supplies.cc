// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#include "xxx.hpp"

class Solution {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    int sz = recipes.size();
    unordered_set<string> spls(supplies.begin(), supplies.end());
    vector<int> indegree(sz, 0);
    unordered_map<string, vector<int>> neibs;
    vector<string> ret;

    for (int i = 0; i < sz; ++i) {
      for (auto &grid : ingredients[i]) {
        // needed ingredient not in supplies so we mark the needed relationship
        if (spls.find(grid) == spls.end()) {
          indegree[i]++;
          // when grid is ready, see if we can "wake up" those recipes
          neibs[grid].push_back(i);
        }
      }
    }
    queue<string> q;
    for (int i = 0; i < sz; ++i) {
      if (indegree[i] == 0) {
        q.push(recipes[i]);
      }
    }
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      ret.push_back(cur);
      for (auto &wait_recipe : neibs[cur]) {
        indegree[wait_recipe]--;
        // wake up?
        if (indegree[wait_recipe] == 0) {
          q.push(recipes[wait_recipe]);
        }
      }
    }

    return ret;
  }
};

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
