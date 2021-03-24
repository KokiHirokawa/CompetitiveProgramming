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
    char s[100005];
    cin >> s;

    int n = strlen(s);

    vector<vector<ll>> dp(100005, vector<ll>(13));
    dp[0][0] = 1;

    rep2(i, n) {
        int c;
        if (s[i] == '?') c = -1;
        else c = s[i] - '0';

        rep2(j, 10) {
            if (c != -1 && c != j) continue;

            rep2(ki, 13) {
                dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
            }
        }

        rep2(j, 13) dp[i + 1][j] %= MOD;
    }

    printf("%lld\n", dp[n][5]);
    return 0;
}