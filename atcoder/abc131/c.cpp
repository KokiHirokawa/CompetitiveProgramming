#include <bits/stdc++.h>
#include <numeric>
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

ll gcd(ll a, ll b) {
   if (a % b == 0) {
       return(b);
   } else {
       return(gcd(b, a % b));
   }
}

ll lcm(ll a, ll b) {
   return a * b / gcd(a, b);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll res = 0;
    ll base = (a + c - 1) / c * c;
    if (b >= base) {
        res += (b - base) / c + 1;
    }

    base = (a + d - 1) / d * d;
    if (b >= base) {
        res += (b - base) / d + 1;
    }

    ll _lcm = lcm(c, d);
    base = (a + _lcm - 1) / _lcm * _lcm;
    if (b >= base) {
        res -= (b - base) / _lcm + 1;
    }

    printf("%lld\n", b - a + 1 - res);
    return 0;
}