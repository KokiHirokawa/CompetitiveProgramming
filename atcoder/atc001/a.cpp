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

typedef pair<ll, ll> P;

int main() {
    ll h, w;
    cin >> h >> w;

    ll sy, sx, gy, gx;
    vector<vector<char>> map(h, vector<char>(w));
    rep2(i, h) rep2(j, w) {
        char temp; cin >> temp;
        map[i][j] = temp;
        if (temp == 's') {
            sy = i;
            sx = j;
        } else if (temp == 'g') {
            gy = i;
            gx = j;
        }
    }

    vector<vector<bool>> reached(h, vector<bool>(w, false));
    queue<P> q;

    q.push(P(sy, sx)); // (y, x)
    reached[sy][sx] = true;

    bool flag = false;
    vector<ll> dy = {0, -1 ,1, 0}, dx = {-1, 0, 0, 1};

    while (!q.empty()) {
        P top = q.front(); q.pop();

        if (top.first == gy && top.second == gx) {
            flag = true;
            break;
        }

        rep2(i, 4) {
            ll ny = top.first + dy[i], nx = top.second + dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w) {
                if (!reached[ny][nx]) {
                    reached[ny][nx] = true;
                    if (map[ny][nx] != '#') q.push(P(ny, nx));
                }
            }
        }
    }

    if (flag) printf("Yes");
    else printf("No");
    return 0;
}