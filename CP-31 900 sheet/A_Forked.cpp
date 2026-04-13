/* A. Forked! - Codeforces 1904A

    Problem Link - https://codeforces.com/problemset/problem/1904/A
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0);

void solve(){
    int a,b;
    cin >> a >> b;
    int xK,yK;
    cin >> xK >> yK;
    int xQ, yQ;
    cin >> xQ >> yQ;
    vector<pair<int,int>> moves{{a,b},{a,-b},{-a,b},{-a,-b},{b,a},{b,-a},{-b,a},{-b,-a}};
    set<pair<int,int>> king;
    for(int i=0;i<8;i++){
    	int jumpX = moves[i].first;
    	int jumpY = moves[i].second;
    	king.insert({xK+jumpX, yK+jumpY});
    }
    set<pair<int,int>> queen;
    for(int i=0;i<8;i++){
    	int jumpX = moves[i].first;
    	int jumpY = moves[i].second;
    	queen.insert({xQ+jumpX, yQ+jumpY});
    }
    int count = 0;
    for(auto pos: king){
    	if(queen.count(pos)){
    		count++;
    	}
    }
    cout << count <<"\n";
}

int32_t main(){
    fast;
    int t; cin >> t;
    while(t--) solve();
}
