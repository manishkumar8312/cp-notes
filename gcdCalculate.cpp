#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define nl cout << "\n";
// int calculateGCD(int a,int b){
//     while(b!=0){
//         int temp = b;
//         b=a%b;
//         a = temp;
//     }
//     return a;
// }
// int findGCD(vector<int> &nums){
//     int mn = *min_element(nums.begin(),nums.end());
//     int mx = *max_element(nums.begin(),nums.end());
//     return calculateGCD(mn,mx);
// }


int findGCD(vi &nums){
    int mn = *min_element(nums.begin(),nums.end());
    int mx = *max_element(nums.begin(),nums.end());
    return __gcd(mn,mx);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << findGCD(a);

}