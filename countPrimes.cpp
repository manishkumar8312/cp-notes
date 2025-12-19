// LeetCode 204

#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n){
    if(n<=2) return 0;
    vector<bool> sieve(n+1,true);
    sieve[0]= sieve[1] = false;
    int count =1;
    for(int i=3;i*i<n;i+=2){
        if(sieve[i]){
            for(int j=i*i;j<n;j+=2*i){
                sieve[i] = false;
            }
        }
    }
    for(int i=3;i<n;i+=2){
        if(sieve[i]) count++;
    }

    return count;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << countPrimes(n)<<"\n";
}

// 1 2 3 4 5 6 7 8 9 10 -> 2 3 5 7 -> o/p: 4