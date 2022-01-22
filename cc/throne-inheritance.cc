// http://leetcode.com/problems/throne-inheritance/description/
#include "xxx.hpp"

class ThroneInheritance {
public:
  ThroneInheritance(string kingName) : king_(kingName) {}

  void birth(string parentName, string childName) {
    family_[parentName].push_back(childName);
    parent_[childName] = parentName;
  }

  void death(string name) {
    // 关系不去
    // family_[parent_[name]].remove(name);
    // parent_.erase(name);
    dead_[name] = true;
  }

  vector<string> getInheritanceOrder() {
    vector<string> order{};
    if (!dead_[king_]) {
      order.push_back(king_);
    }

    recur(king_, order);

    return order;
  }

private:
  void recur(string &cur, vector<string> &order) {
    // have kids
    if (family_.count(cur)) {
      for (auto child : family_[cur]) {
        // first push this
        if (!dead_[child]) {
          order.push_back(child);
        }
        // 然后这根线下去
        recur(child, order);
      }
    }
  }

private:
  unordered_map<string, list<string>> family_;
  unordered_map<string, string> parent_;
  unordered_map<string, bool> dead_;
  string king_;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
