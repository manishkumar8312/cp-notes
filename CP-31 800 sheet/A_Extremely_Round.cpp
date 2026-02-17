#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        string s = to_string(n);
        int len = s.size();

        // count extremely round numbers
        int ans = 9 * (len - 1);

        // smallest number with 'len' digits
        long long base = 1;
        for (int i = 1; i < len; i++) {
            base *= 10;
        }

        for (int d = 1; d <= 9; d++) {
            if (d * base <= n) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}