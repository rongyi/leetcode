// http://leetcode.com/problems/design-twitter/description/
#include "xxx.h"

class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() : time_(0) {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tw_[userId].push_back(post(time_++, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> ret;
    vector<pair<post *, post *>> h;

    for (auto &u : follow_relation_[userId]) {
      auto &t = tw_[u];
      if (t.size() > 0) {
        h.emplace_back(t.data(), t.data() + t.size() - 1);
      }
    }

    // his self tw
    auto &t = tw_[userId];
    if (t.size() > 0) {
      h.emplace_back(t.data(), t.data() + t.size() - 1);
    }
    auto f = [](const pair<post *, post *> &x, const pair<post *, post *> &y) {
      return x.second->time_ < y.second->time_;
    };

    make_heap(h.begin(), h.end(), f);

    const int n = 10;
    ret.reserve(n);
    for (int i = 0; (i < n) && !h.empty(); i++) {
      pop_heap(h.begin(), h.end(), f);
      auto &hb = h.back();
      ret.push_back(hb.second->id_);

      if (hb.first == hb.second--) {
        h.pop_back();
      } else {
        push_heap(h.begin(), h.end(), f);
      }
    }

    return ret;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    // er 关注 ee,在 ee的关注
    if (followerId != followeeId) {
      follow_relation_[followerId].insert(followeeId);
    }
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    follow_relation_[followerId].erase(followeeId);
  }

private:
  unordered_map<int, unordered_set<int>> follow_relation_;
  int time_;
  struct post {
    int time_;
    int id_;
    post(int time, int id) : time_(time), id_(id) {}
  };
  unordered_map<int, vector<post>> tw_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
