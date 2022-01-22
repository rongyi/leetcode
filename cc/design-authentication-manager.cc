// http://leetcode.com/problems/design-authentication-manager/description/
#include "xxx.hpp"

class AuthenticationManager {
public:
  // 细节实现题
  AuthenticationManager(int timeToLive) : ttl_(timeToLive) {}

  void generate(string tokenID, int currentTime) {
    tokens_[tokenID] = {currentTime, currentTime + ttl_};
  }

  void renew(string tokenID, int currentTime) {
    // no token, nothing happens
    if (tokens_.find(tokenID) == tokens_.end()) {
      return;
    }
    auto cur_duration = tokens_[tokenID];
    // expired token, nothing happens
    // 等于会先过期
    if (cur_duration.second <= currentTime) {
      return;
    }

    tokens_[tokenID] = {cur_duration.first, currentTime + ttl_};
  }

  int countUnexpiredTokens(int currentTime) {
    int unexp = 0;
    for (auto &kv : tokens_) {
      // 等于会先过期
      if (kv.second.second > currentTime) {
        unexp++;
      }
    }

    return unexp;
  }

private:
  int ttl_;
  map<string, pair<int, int>> tokens_;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenID,currentTime);
 * obj->renew(tokenID,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
