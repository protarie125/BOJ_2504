#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> s;
  stack<char> T{};

  ll ans = 0;
  ll part = 1;
  for (auto i = 0; i < s.length(); ++i) {
    const auto& x = s[i];
    if (x == '(') {
      T.push(x);
      part *= 2;
    } else if (x == '[') {
      T.push(x);
      part *= 3;
    } else if (x == ')') {
      if (T.empty() || T.top() == '[') {
        cout << 0;
        return 0;
      }

      if (s[i - 1] == '(') {
        ans += part;
      }
      T.pop();
      part /= 2;
    } else if (x == ']') {
      if (T.empty() || T.top() == '(') {
        cout << 0;
        return 0;
      }

      if (s[i - 1] == '[') {
        ans += part;
      }
      T.pop();
      part /= 3;
    }
  }

  if (T.empty()) {
    cout << ans;
  } else {
    cout << 0;
  }

  return 0;
}