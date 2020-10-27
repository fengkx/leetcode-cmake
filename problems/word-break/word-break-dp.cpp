#include "headers.h"

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> d;
    int maxLen = 0;
    for (auto w : wordDict) {
      d.insert(w);
      maxLen = max(maxLen, (int)w.size());
    }

    unordered_set<string>::iterator dt;
    vector<bool> m(s.size() + 1);
    m[0] = true;

    for (int hi = 1; hi <= s.size(); ++hi) {
      for (int i = hi - 1; i >= 0; --i) {
        if (hi - i > maxLen) continue;
        dt = d.find(s.substr(i, hi - i));
        if (m[i] && dt != d.end()) {
          m[hi] = true;
          break;
        }
      }
    }
    return m[s.size()];
  }
};
TEST(wordBreak, wordBreak) {
  Solution s;
  vector<string> v{"a", "b"};
  EXPECT_EQ(s.wordBreak("ab", v), true);
  vector<string> v2{"aaaa", "aaa"};
  EXPECT_EQ(s.wordBreak("aaaaaaa", v2), true);
  vector<string> v3{"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                    "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
  auto astr =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaa";
  EXPECT_EQ(s.wordBreak(astr, v3), false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}