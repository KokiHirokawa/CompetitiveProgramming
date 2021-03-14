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

struct mint {
    ll x;

    mint(ll x = 0): x(x % MOD) {}

    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint& operator-=(const mint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
};

mint c[4005][4005];

void init() {
    c[0][0] = 1;
    erep2(i, 4000) {
        erep2(j, i) {
            c[i + 1][j] += c[i][j];
            c[i + 1][j + 1] += c[i][j];
        }
    }
}

mint comb(int n, int k) {
    return c[n][k];
}

int main() {
    init();

    int n, k;
    cin >> n >> k;

    erep3(i, 1, k) {
        mint blue = comb(k - 1, i - 1);
        mint red = comb(n - k + 1, i);
        mint ans = blue * red;
        printf("%lld\n", ans.x);
    }
    return 0;
}