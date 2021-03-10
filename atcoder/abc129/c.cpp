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
    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1);
    dp[0] = 1;

    rep2(i, m) {
        int m;
        cin >> m;
        dp[m] = -1;
    }

    erep3(i, 1, n) {
        if (i == 1) {
            if (dp[1] != -1) dp[1] = 1;
        } else {
            if (dp[i - 2] == -1 && dp[i - 1] == -1) {
                puts("0");
                return 0;
            } else if (dp[i] == -1) {
                continue;
            } else {
                dp[i] = max(0, dp[i - 2]) + max(0, dp[i - 1]);
                dp[i] %= MOD;
            }
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}