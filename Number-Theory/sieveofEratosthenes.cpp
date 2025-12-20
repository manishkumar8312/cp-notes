#include <bits/stdc++.h>
using namespace std;
vector<bool> Prime;
vector<int> spf;
void sieve(int s) {
    Prime.resize(s + 1, 1);
    spf.resize(s + 1, s + 1);
    if (s >= 0) Prime[0] = 0;
    if (s >= 1) Prime[1] = 0;
    for(int i = 2 ; i <= s ; i++) if(Prime[i]) {
        spf[i] = min(spf[i], i);
        for(long long j = i ; j * i <= s ; j++) {
            Prime[j * i] = 0;
            spf[j * i] = min(i, spf[j * i]);
        }
    }
}

vector<int> primes_list(int n) {
    vector<int> res;
    for(int i = 2; i <= n; ++i) if (Prime[i]) res.push_back(i);
    return res;
}

vector<pair<int,int>> factorize(int x) {
    vector<pair<int,int>> f;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) { x /= p; ++cnt; }
        f.emplace_back(p, cnt);
    }
    return f;
}

int32_t main(){
    int n;
    if(!(cin >> n)) return 0;
    sieve(n);

    // print primes up to n
    auto primes = primes_list(n);
    for(int p : primes) cout << p << ' ';
    cout << '\n';

    // example: factorize some numbers (demo)
    for (int i = 2; i <= min(n, 20); ++i) {
        auto f = factorize(i);
        //cout << i << " = ";
        bool first = true;
        for (auto &pr : f) {
            if (!first) cout << " * ";
            cout << pr.first << "^" << pr.second;
            first = false;
        }
        cout << '\n';
    }
}