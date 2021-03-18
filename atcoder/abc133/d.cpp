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
    int n;
    cin >> n;

    vector<ll> a(n), sum(n);
    rep2(i, n) {
        ll _a;
        cin >> _a;

        a[i] = _a;
        sum[i] = _a * 2;
    }

    ll diff = sum[1] - sum[0];
    if (n > 3) {
        for (ll i = 3; i < n - 1; i += 2) diff += (sum[i] - sum[i - 1]);
    }

    vector<ll> x(n);
    x[0] = (sum[n - 1] - diff) / 2;

    rep2(i, n - 1) {
        x[i + 1] = sum[i] - x[i];
    }

    rep2(i, n) {
        if (i != n - 1) printf("%lld ", x[i]);
        else printf("%lld\n", x[i]);
    }
    return 0;
}