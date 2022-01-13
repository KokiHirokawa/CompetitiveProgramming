#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;
using ll = long long;

struct Edge {
    int from;
    int to;
    ll cost;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> es(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;

        Edge e = { a, b, c };
        es[i] = e;
    }

    vector<ll> d(n, LLONG_MIN);
    d[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            Edge e = es[j];
            if (d[e.from] != LLONG_MIN && d[e.from] + e.cost > d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
            }
        }

        // 終点に影響がない形で閉路があった場合に誤検知してしまうため、もう(n-1)*m回のループを回し、
        // 1回目と2回目のループ終了時点でのd[n - 1]を比較し、異なっていればd[n - 1]の値はinfになりえる
        // if (i == n - 1) {
        //     printf("inf\n");
        //     return 0;
        // }
    }

    ll ans = d[n - 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Edge e = es[j];
            if (d[e.from] != LLONG_MIN && d[e.from] + e.cost > d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }

    if (ans == d[n - 1]) {
        printf("%lld\n", d[n - 1]);
    } else {
        printf("inf\n");
    }
    return 0;
}