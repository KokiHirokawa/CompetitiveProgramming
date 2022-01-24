#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int max_prefix_length = INT_MAX;
            for (string s: strs) {
                max_prefix_length = min(max_prefix_length, (int)s.length());
            }

            string res;
            rep(max_prefix_length) {
                char c = strs[0][i];
                rep3(j, 1, strs.size()) {
                    if (strs[j][i] != c) return res;
                }
                res.push_back(c);
            }
            return res;
        }
};

int main() {
    Solution s;

    vector<string> input1 = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(input1) << endl;

    vector<string> input2 = {"dog", "racecar", "car"};
    cout << s.longestCommonPrefix(input2) << endl;

    return 0;
}