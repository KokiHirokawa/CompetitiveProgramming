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

int main() {
    int n;
    cin >> n;

    vector<int> a(n), m(n);
    rep2(i, n) cin >> a[i] >> m[i];

    int K;
    cin >> K;

    vector<vector<int>> dp(n + 1, vector<int>(K + 1, -1));
    dp[0][0] = 0;

    rep2(i, n) erep2(j, K) {
        if (dp[i][j] >= 0) {
            dp[i + 1][j] = m[i];
        } else if (j < a[i] || dp[i + 1][j - a[i]] <= 0) {
            dp[i + 1][j] = -1;
        } else {
            dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
        }
    }

    if (dp[n][K] >= 0) puts("YES");
    else puts("YES");
    return 0;
}