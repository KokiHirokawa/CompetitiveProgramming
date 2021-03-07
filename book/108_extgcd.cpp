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

ll extgcd(ll a, ll b, ll &x, ll &y) {
    int d = a;

    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= a / b * x;
    } else {
        x = 1;
        y = 0;
    }

    return d;
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll x, y;
    extgcd(a, b, x, y);

    ll h, i, j, k;
    h = i = j = k = 0;

    if (x >= 0) h = x;
    else i = abs(x);

    if (y >= 0) j = y;
    else k = abs(y);

    printf("%lld %lld %lld %lld\n", h, i, j, k);
    return 0;
}