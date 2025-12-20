// #include <bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     cin >> n;
//     long long sum = 0;
//     for(int d=1;d*d<=n;d++){
//         if(n%d==0){
//             sum+=d;
//             if(d!=n/d){
//                 sum+=n/d;
//             }
//         }
//     }
//     sum-=n;
//     cout << sum <<"\n";
// }

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }


//T.C = O(sqrt(n))  
// S.C = O(1)


//Optimized Approach

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
vector<int> sieve(MAX+1, 0);

void precompute() {
    for (int i = 2; i <= MAX; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                if (sieve[j] == 0) sieve[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    int N = n;
    long long res = 1;

    while (n > 1) {
        int spf = sieve[n];
        int alpha = 0;

        while (n % spf == 0) {
            n /= spf;
            alpha++;
        }

        long long p_power = 1;
        long long sum = 1;

        for (int i = 0; i < alpha; i++) {
            p_power *= spf;
            sum += p_power;
        }

        res *= sum;
    }

    cout << res - N << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
