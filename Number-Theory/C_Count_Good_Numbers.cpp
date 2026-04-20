/*

    C. Count Good Numbers - 2125/c
    Problem Link: https://codeforces.com/contest/2125/problem/C

*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
ll countBad(ll n) {

    ll primes[] = {2, 3, 5, 7};
    ll count = 0;
    for (ll i = 1; i < 16; i++) {
        ll lcm = 1;
        ll setBits = 0;
        
        for (ll j = 0; j < 4; j++) {
            if ((i >> j) & 1) {
                lcm *= primes[j];
                setBits++;
            }
        }
        
        if (setBits % 2 == 1) {
            count += n / lcm;
        } else {
            count -= n / lcm;
        }
    }
    return count;

}
ll countGood(ll x){
    return x - countBad(x);
}
void solve(){
    ll l,r; cin >> l >> r;
    cout << countGood(r) - countGood(l-1)<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }

}