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

using ull = unsigned long long;

int main() {
    ll n;
    cin >> n;

    ll res = 1;
    vector<ull> factorial(n + 1);
    erep3(i, 1, n) factorial[i] = i;

    /// 素因数分解用の配列
    vector<ull> primes(n + 1, 0);
    erep3(i, 2, n) {
        ll prime = 2;
        while (factorial[i] != 1) {
            if (factorial[i] % prime == 0) {
                factorial[i] /= prime;
                primes[prime]++;
            } else {
                prime++;
            }
        }
    }

    erep3(i, 2, n) {
        res = res * (primes[i] + 1) % MOD;
    }
    printf("%lld\n", res);
    return 0;
}