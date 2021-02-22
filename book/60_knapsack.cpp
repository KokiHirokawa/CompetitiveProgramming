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

    vector<int> w(n), v(n);
    rep2(i, n) cin >> w[i] >> v[i];

    int limit;
    cin >> limit;

    const int MAX_V = 10000;
    vector<vector<int>> dp(n + 1, vector<int>(MAX_V + 1, INT8_MAX));
    dp[0][0] = 0;
    rep2(i, n) erep2(j, MAX_V) {
        if (j < v[i]) {
            dp[i + 1][j] = dp[i][j];
        } else {
            dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    }
    int res = 0;
    erep2(i, MAX_V) if (dp[n][i] <= limit) res = i;

    printf("%d\n", res);
    return 0;
}