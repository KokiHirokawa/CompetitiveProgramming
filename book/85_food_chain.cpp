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

struct UnionFind {
    private:
        vector<ll> to;
        vector<ll> ranks;
    public:
        UnionFind(ll n): to(n), ranks(n, 0) {
            for (ll i = 0; i < n; ++i) to[i] = i;
        }
        ll find(ll x) {
            if (to[x] == x) {
                return x;
            } else {
                return to[x] = find(to[x]);
            }
        }
        bool same(ll x, ll y) {
            return find(x) == find(y);
        }
        void unite(ll x, ll y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            if (ranks[x] < ranks[y]) {
                to[x] = y;
            } else {
                to[y] = x;
                if (ranks[x] == ranks[y]) ranks[x]++;
            }
        }
};

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> type(k), x(k), y(k);
    rep2(i, k) {
        cin >> type[i];

        ll _x, _y;
        cin >> _x >> _y;
        --_x;
        --_y;
        x[i] = _x;
        y[i] = _y;
    }

    UnionFind uf(n * 3);
    ll res = 0;

    rep2(i, k) {
        ll t = type[i];
        ll _x = x[i];
        ll _y = y[i];

        if (_x < 0 || n <= _x || _y < 0 || n <= _y) {
            res++;
            continue;
        }

        if (t == 1) {
            if (uf.same(_x, _y + n) || uf.same(_x, _y + 2 * n)) {
                res++;
            } else {
                uf.unite(_x, _y);
                uf.unite(_x + n, _y + n);
                uf.unite(_x + 2 * n, _y + 2 * n);
            }
        } else {
            if (uf.same(_x, _y) || uf.same(_x, _y + 2 * n)) {
                printf("%lld\n", i);
                res++;
            } else {
                uf.unite(_x, _y + n);
                uf.unite(_x + n, _y + 2 * n);
                uf.unite(_x + 2 * n, _y);
            }
        }
    }

    printf("%lld\n", res);
    return 0;
}