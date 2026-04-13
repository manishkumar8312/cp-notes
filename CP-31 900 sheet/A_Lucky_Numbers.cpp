/*
    Codeforces: Lucky Numbers
    Problem Link: https://codeforces.com/problemset/problem/110/A

*/

#include <bits/stdc++.h>
using namespace std;

int getLuckiness(int x) {
    int mn = 9, mx = 0;
    while (x > 0) {
        int d = x % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        x /= 10;
    }
    return mx - mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int best = l;
        int maxLuck = -1;

        for (int i = l; i <= min(r, l + 100); i++) {
            int luck = getLuckiness(i);

            if (luck > maxLuck) {
                maxLuck = luck;
                best = i;
            }

            if (maxLuck == 9) break;
        }

        cout << best << "\n";
    }

    return 0;
}