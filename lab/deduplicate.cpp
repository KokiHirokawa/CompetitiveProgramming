#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j < i; ++j) v.push_back(i);
    }

    for (int i : v) printf("%d ", i);
    cout << "" << endl;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i : v) printf("%d ", i);
    cout << "" << endl;

    return 0;
}