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
    ll a, b;
    cin >> a >> b;

    vector<bool> isPrime(b - a, true), isPrimeSmall(1000000, true);
    for (ll i = 2; i * i < b; i++) {
        if (!isPrimeSmall[i]) continue;

        for (ll j = i * 2; j * j < b; j += i) isPrimeSmall[j] = false;
        for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) isPrime[j - a] = false;
    }

    ll res = 0;
    for (auto i: isPrime) if (i) res++;

    printf("%lld\n", res);
    return 0;
}