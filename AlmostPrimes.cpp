// Codeforces - 26A

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> sieve(n+1,0);
    for(int i=2;i<=n;i++){
        if(sieve[i]==0){
            for(int j=i;j<=n;j+=i){
                sieve[j]++;
            }
        }
    }
    int count = 0;
    for(int i=2;i<=n;i++){
        if(sieve[i]==2) count++;
    }
    cout << count <<"\n";
    return 0;
}


