#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            count ++;
        }if(count > 4) break;
    }
    if(count <= 2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
