#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    if(count(v.begin(),v.end(),1) == n){
        cout << "Alice\n";
    }else if(v[0]==0 && v.back()==0){
        cout << "Bob\n";
    }else{
        cout << "Alice\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
