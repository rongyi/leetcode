// http://leetcode.com/problems/smallest-sufficient-team/description/
#include "xxx.h"

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vector<vector<string>> &people) {
    const int n = req_skills.size();
    unordered_map<int, vector<int>> ret;
    ret[0] = {};
    ret.reserve(1 << n);

    unordered_map<string, int> skill_map;
    for (int i = 0; i < req_skills.size(); ++i) {
      skill_map[req_skills[i]] = i;
    }
    for (int i = 0; i < people.size(); ++i) {
      int cur_skill = 0;
      for (int j = 0; j < people[i].size(); ++j) {
        cur_skill |= 1 << skill_map[people[i][j]];
      }

      for (auto it = ret.begin(); it != ret.end(); ++it) {
        // 加上当前小哥people[i]的技能
        int comb = it->first | cur_skill;
        // 如果这个状态没存过，或者是这个状态需要的人比从
        // 某个状态加当前小哥需要的人还多，那么就存
        // 这个小的，殊途同归的意思，同归到相同的技能栈
        if (ret.find(comb) == ret.end() ||
            ret[comb].size() > 1 + ret[it->first].size()) {
          ret[comb] = it->second;
          ret[comb].push_back(i);
        }
      }
    }
    return ret[(1 << n) - 1];
  }

  vector<int> smallestSufficientTeamVersion1(vector<string> &req_skills,
                                             vector<vector<string>> &people) {
    unordered_map<string, int> skills;
    const int n = req_skills.size();
    // record the index
    for (int i = 0; i < n; ++i) {
      skills[req_skills[i]] = i;
    }

    const int m = people.size();
    vector<int> people_skill(m, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < people[i].size(); ++j) {
        int tmp = skills[people[i][j]];
        people_skill[i] |= (1 << tmp);
      }
    }
    int s = (1 << n);
    vector<int> dp(s, numeric_limits<int>::max());
    vector<int> parent(s, -1);
    vector<int> parent_state(s, 0);

    dp[0] = 0;
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i] == numeric_limits<int>::max()) {
          continue;
        }
        int tmp = i | people_skill[j];
        // 已记录的需要tmp技能栈需要的人数，比dp[i] + 当前小哥people[j]
        // 还要多，那么我们可以继续缩一下
        if (dp[tmp] > dp[i] + 1) {
          parent[tmp] = j;
          parent_state[tmp] = i;
          dp[tmp] = dp[i] + 1;
        }
      }
    }

    int tmp = s - 1;
    vector<int> ret;
    while (parent[tmp] != -1) {
      ret.push_back(parent[tmp]);
      tmp = parent_state[tmp];
    }

    return ret;
  }
};
