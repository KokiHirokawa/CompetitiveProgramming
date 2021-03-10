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

struct Restaurant {
    string name;
    int point;
    int number;
};

bool operator<(const Restaurant& a, const Restaurant& b) noexcept {
    if (a.name == b.name) {
        return a.point > b.point;
    } else {
        return a.name < b.name;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Restaurant> r(n);

    for (int i = 0; i < n; ++i) {
        string s;
        int p;
        cin >> s >> p;

        r[i] = Restaurant { s, p, i + 1 };
    }

    sort(r.begin(), r.end());

    rep2(i, n) {
        printf("%d\n", r[i].number);
    }
    return 0;
}