#include <bits/stdc++.h>
using namespace std;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> sieve(1e7+1,true);
    if(n==1){
        cout << 2 << "\n";
        return 0;
    }
    // Marked all even numbers false
    for(int i=4;i<=sieve.size();i+=2){
        sieve[i] = false;
    }
    for(int i=3;i*i<=sieve.size();i+=2){
        if(sieve[i]){
            for(int j=i*i;j<=sieve.size();j+=2*i){
                sieve[j] = false;
            }
        }
    }
    int count = 1;
    for(int i=3;i<=sieve.size();i++){
        if(sieve[i]) count++;
        if(count==n){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}