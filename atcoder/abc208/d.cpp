#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector< vector<ll> > d(n, vector<ll>(n, LLONG_MAX));
    for (ll i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        d[a][b] = c;
    }

    ll result = 0;
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
                if (d[i][j] != LLONG_MAX) {
                    result += d[i][j];
                }
            }
        }
    }

    printf("%lld\n", result);
    return 0;
}