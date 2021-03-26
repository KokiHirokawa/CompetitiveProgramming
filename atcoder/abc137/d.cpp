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

using P = pair<int, int>;

auto compare = [](P left, P right) {
    return left.second < right.second;
};

int main() {
    ll n, m;
    cin >> n >> m;

    vector<P> jobs(n);
    rep2(i, n) {
        int a, b;
        cin >> a >> b;
        jobs[i] = P{a, b};
    }

    sort(jobs.begin(), jobs.end());

    std::priority_queue<
      P,
      std::vector<P>,
      decltype(compare)
    > que {compare};

    ll res = 0, idx = 0;

    for (int i = m - 1; i >= 0; --i) {
        int diff = m - i;
        rep3(i, idx, n) {
            if (jobs[i].first != diff) {
                idx = i;
                break;
            }
            que.push(jobs[i]);
        }

        if (que.empty()) continue;

        P top = que.top();
        que.pop();
        res += top.second;
    }

    printf("%lld\n", res);
    return 0;
}