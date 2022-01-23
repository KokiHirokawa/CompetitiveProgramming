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

struct edge { int u, v, cost; };

bool comp(const edge& left, const edge& right) {
    return left.cost < right.cost;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto size = points.size();
        vector<vector<int>> cost(size, vector<int>(size));

        vector<edge> es;

        rep2(i, size) {
            rep3(j, i + 1, size) {
                vector<int> first = points[i], second = points[j];
                edge e = {(int)i, (int)j, abs(first[0] - second[0]) + abs(first[1] - second[1])};
                es.push_back(e);
            }
        }

        sort(es.begin(), es.end(), comp);
        UnionFind uf(size);

        int result = 0;
        rep(es.size()) {
            edge e = es[i];
            if (!uf.same(e.u, e.v)) {
                uf.unite(e.u, e.v);
                result += e.cost;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> input = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    Solution s;
    cout << s.minCostConnectPoints(input) << endl;

    return 0;
}