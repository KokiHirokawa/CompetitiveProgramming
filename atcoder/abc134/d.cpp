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
    ll n;
    cin >> n;

    vector<ll> a(n);
    rep2(i, n) cin >> a[i];

    vector<ll> x(n, 0);
    ll m = 0;
    for (ll i = n - 1; i >= 0; --i) {
        ll _a = a[i];
        ll sum = 0;

        for (ll j = (i + 1) * 2; j <= n; j += (i + 1)) {
            sum += x[j - 1];
        }

        if (_a != sum % 2) {
            m++;
            x[i] = 1;
        }
    }

    printf("%lld\n", m);

    vector<ll> fx;

    rep2(i, n) if (x[i] == 1) fx.push_back(i + 1);
    for (auto i: fx) {
        if (i < fx.size() - 1) printf("%lld ", i);
        else printf("%lld\n", i);
    }
    return 0;
}