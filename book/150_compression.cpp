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

int W, H, N;
const int MAX_N = 500;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
vector<vector<bool>> field(MAX_N * 6, vector<bool>(MAX_N * 6, false));
vector<int> dx = { -1, 0, 0, 1 }, dy = { 0, -1, 1, 0 };

int compress(int *x1, int *x2, int w) {
    vector<int> xs;

    rep2(i, N) erep3(d, -1, 1) {
        int tx1 = x1[i] + d;
        int tx2 = x2[i] + d;
        if (1 <= tx1 && tx1 <= w) xs.push_back(tx1);
        if (1 <= tx2 && tx2 <= w) xs.push_back(tx2);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    rep2(i, N) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

int main() {
    cin >> W >> H >> N;
    rep2(i, N) cin >> X1[i];
    rep2(i, N) cin >> X2[i];
    rep2(i, N) cin >> Y1[i];
    rep2(i, N) cin >> Y2[i];

    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    rep2(i, N) erep3(y, Y1[i], Y2[i]) erep3(x, X1[i], X2[i]) field[y][x] = true;

    print(W); print(H);

    int ans = 0;
    rep2(y, H) rep2(x, W) {
        if (field[y][x]) continue;
        ans++;

        queue<pair<int, int>> que;
        que.push(make_pair(x, y));

        while (!que.empty()) {
            int sx = que.front().first, sy = que.front().second;
            que.pop();

            rep2(i, 4) {
                int tx = sx + dx[i], ty = sy + dy[i];
                if (tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
                if (field[ty][tx]) continue;
                que.push(make_pair(tx, ty));
                field[ty][tx] = true;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}