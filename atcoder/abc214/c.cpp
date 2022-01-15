#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;

typedef pair<ll, ll> P;
struct Edge { ll to, cost; };

int main() {
    ll n;
    cin >> n;

    vector< vector<Edge> > edges(n + 1);

    for (int i = 1; i <= n; i++) {
        ll _s;
        cin >> _s;

        ll to;
        if (i == n) {
            to = 1;
        } else {
            to = i + 1;
        }

        Edge e = { to, _s };
        edges[i].push_back(e);
    }

    for (int i = 1; i <= n; i++) {
        ll _t;
        cin >> _t;

        Edge e = { i, _t };
        edges[0].push_back(e);
    }

    vector<ll> d(n + 1, LLONG_MAX);
    d[0] = 0;

    /// first: 最短距離
    /// second: 頂点のindex
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, 0));

    while (!que.empty()) {
        P p = que.top();
        que.pop();

        for (auto e: edges[p.second]) {
            if (d[e.to] > p.first + e.cost) {
                d[e.to] = p.first + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld\n", d[i]);
    }
    return 0;
}