#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define nl cout << "\n";
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    const int MAX = *max_element(a.begin(),a.end());
    vi freq(MAX+1,0);
    for(int num : a){
        freq[num]++;
    }
    for(int d=MAX;d>=1;d--){
        int count = 0;
        for(int mul = d; mul<=MAX;mul+=d){
            count+=freq[mul];
            if(count>=2){
                cout << d;
                nl;
                return 0;
            }
        }
    }
    cout << 1 ;
    nl;
    return 0;
}