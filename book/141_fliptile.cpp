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

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

int M, N;
const int MAX_M = 15;
const int MAX_N = 15;
int tile[MAX_M][MAX_N], opt[MAX_M][MAX_N], flip[MAX_M][MAX_N];

// (x, y)の色を調べる
int get(int x, int y) {
    int c = tile[x][y];
    rep2(i, 5) {
        int x2 = x + dx[i], y2 = y + dy[i];
        if (0 <= x2 && x2 < M && 0 <= y2 && y2 < N) {
            c += flip[x2][y2];
        }
    }
    return c % 2;
}

// 1行目を決めた場合の最小操作回数を求める
// 解が存在しないならば-1
int calc() {
    // 2行目からのひっくり返し方を求める
    rep3(i, 1, M) rep2(j, N) {
        if (get(i - 1, j) != 0) {
            // (i - 1, j) が黒の場合、ひっくり返す
            flip[i][j] = 1;
        }
    }

    // 最後の行が全部白かチェック
    rep2(i, N) {
        if (get(M - 1, i) != 0) return -1;
    }

    int res = 0;
    // 反転回数をカウント
    rep2(i, M) rep2(j, N) res += flip[i][j];
    return res;
}

int main() {
    cin >> M >> N;
    rep2(i, M) rep2(j, N) cin >> tile[i][j];

    int res = -1;

    rep2(i, 1 << N) {
        memset(flip, 0, sizeof(flip));
        rep2(j, N) flip[0][N - j - 1] = i >> j & 1;
        int num = calc();
        if (num >= 0 && (res < 0 || num < res)) {
            res = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if (res < 0) {
        // 解なし
        printf("IMPOSSIBLE\n");
    } else {
        rep2(i, M) rep2(j, N) printf("%d%c", opt[i][j], j + 1 == N ? '\n' : ' ');
    }
    return 0;
}