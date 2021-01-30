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

int n, s;
vector<int> a, sum;

// 二分探索 - O(n log n)
void solve() {
    if (sum[n] < s) {
        printf("0\n");
        return;
    }

    int res = n;
    for (int i = 0; sum[i] + s <= sum[n]; i++) {
        int t = lower_bound(sum.begin() + i, sum.begin() + n, sum[i] + s) - (sum.begin() + i);
        res = min(res, t);
    }

    printf("%d\n", res);
}

// しゃくとり法 - O(n)
void solve2() {
    int res = n + 1;
    int l = 0, r = 0, sum = 0;

    for (;;) {
        while (r < n && sum < s) {
            sum += a[r++];
        }
        if (sum < s) break;
        res = min(res, r - l);
        sum -= a[l++];
    }

    if (res > n) {
        res = 0;
    }

    printf("%d\n", res);
}

int main() {
    cin >> n >> s;
    
    a.resize(n);
    rep2(i, n) cin >> a[i];

    sum.resize(n + 1);
    rep2(i, n) sum[i + 1] = sum[i] + a[i];

    solve2();
    return 0;
}