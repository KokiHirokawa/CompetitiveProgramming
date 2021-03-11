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

ll h, w;
vector<vector<char>> grid;

ll right(ll y, ll x, ll res) {
    if (w <= x || grid[y][x] == '#') return res;
    return right(y, x + 1, res + 1);
}

ll down(ll y, ll x, ll res) {
    if (h <= y || grid[y][x] == '#') return res;
    return down(y + 1, x, res + 1);
}

int main() {
    cin >> h >> w;

    vector<vector<ll>> vertical(h, vector<ll>(w, 0)), horizontal(h, vector<ll>(w, 0));

    grid.resize(h);
    rep2(i, h) grid[i].resize(w);

    rep2(i, h) rep2(j, w) cin >> grid[i][j];

    ll res = 0;
    rep2(i, h) rep2(j, w) {
        if (grid[i][j] == '#') {
            continue;
        }

        if (i - 1 < 0 || grid[i - 1][j] == '#') {
            horizontal[i][j] = down(i, j, 0);
        } else {
            horizontal[i][j] = horizontal[i - 1][j];
        }

        if (j - 1 < 0 || grid[i][j - 1] == '#') {
            vertical[i][j] = right(i, j, 0);
        } else {
            vertical[i][j] = vertical[i][j - 1];
        }

        res = max(res, horizontal[i][j] + vertical[i][j] - 1);
    }

    printf("%lld\n", res);
    return 0;
}