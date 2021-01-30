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

int n, k;
vector<int> w, v;
vector<double> y;

bool isOK(double x) {
    rep2(i, n) y[i] = v[i] - w[i] * x;
    sort(y.begin(), y.end(), [](double a, double b) {
        return a > b;
    });

    double sum = 0;
    rep2(i, k) {
        sum += y[i];
    }
    return sum >= 0;
}

int main() {
    cin >> n >> k;
    w.resize(n);
    v.resize(n);
    y.resize(n);
    rep2(i, n) cin >> w[i] >> v[i];

    double lb = 0, ub = INT32_MAX;
    rep2(i, 100) {
        double mid = (lb + ub) / 2;
        
        if (isOK(mid)) lb = mid;
        else ub = mid;
    }

    printf("%.2f\n", ub);
    return 0;
}