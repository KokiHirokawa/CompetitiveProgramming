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
    ll n, m;
    cin >> n >> m;

    vector<vector<bool>> r(n, vector<bool>(n, false));
    rep2(i, m) {
        ll x, y;
        cin >> x >> y;
        --x;
        --y;
        r[x][y] = r[y][x] = true;
    }

    ll res = 0;
    rep2(i, 1 << n) {
        vector<ll> idxs;
        ll size = 0;

        rep2(j, n) {
            if (i >> j & 1) {
                idxs.push_back(j);
                ++size;
            }
        }

        bool flag = true;
        for (auto j: idxs) {
            for (auto k: idxs) {
                if (j == k) continue;
                if (!r[j][k]) flag = false;
            }
        }
        if (flag) res = max(res, size);
    }

    printf("%lld\n", res);
    return 0;
}