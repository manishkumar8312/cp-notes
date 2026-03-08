#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,a;
        cin >> n >> a;
        int c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x < a) c1++;
            if(x > a) c2++;
        }
        cout << ((c1 > c2)? (a-1) : (a+1)) << "\n";
    }
    return 0;
}