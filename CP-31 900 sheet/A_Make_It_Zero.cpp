/* 
Make It Zero 1869-A
Problem Link: https://codeforces.com/problemset/problem/1869/A
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    long long v[n];
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    if(n%2==0){
        cout << 2 <<"\n";
        cout << 1 << " " << n<<"\n";
        cout << 1 << " " << n << "\n";
    }else{
        cout << 4 << "\n";
        cout << 1 << " " << n-1 <<"\n";
        cout << 1 << " " << n-1 <<"\n";
        cout << n-1 << " " << n <<"\n";
        cout << n-1 << " " << n <<"\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

}