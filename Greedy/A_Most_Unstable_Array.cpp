/*
    CodeForces: Most Unstable Array
    Problem Link: https://codeforces.com/contest/1353/problem/A
    
    Observation:
        - If n == 1 → answer = 0
        - If n == 2 → answer = m
        - Else → maximize instability → answer = 2*m

        Greedy Idea:
        - Maximize difference by placing extremes

        Why Greedy Works:
        - We want maximum adjacent difference → always push values to extremes

        Mistake I could make:
        - Overthinking with array construction (not needed)
*/


#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m; cin >> n >> m;
    if(n==1) cout << 0 <<"\n";
    else if(n==2) cout << m <<"\n";
    else cout << (m+m)<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
}