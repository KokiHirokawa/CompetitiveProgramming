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
    UnionFind uf(10);

    printf("%lld\n", uf.find(1));
    printf("%lld\n", uf.find(5));

    if (uf.same(1, 2)) puts("same!");
    else puts("not same!");

    uf.unite(1, 5);

    if (uf.same(1, 5)) puts("same!");
    else puts("not same!");

    return 0;
}