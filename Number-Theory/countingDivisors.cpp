// Count the Number of Divisors

// You are given an integer n.
// Your task is to compute the total number of positive divisors of n.

// Input Format

// The first line contains an integer t — the number of test cases.

// Each test case contains a single integer n.

// Output Format

// For each test case, print a single integer — the count of all positive divisors of n.

// Constraints
// 1 ≤ t ≤ 10^5
// 1 ≤ n ≤ 10^12

// Example

// Input

// 3
// 6
// 10
// 25


// Output

// 4
// 4
// 3

// Explanation

// For 6, divisors are {1, 2, 3, 6} → 4 divisors

// For 10, divisors are {1, 2, 5, 10} → 4 divisors

// For 25, divisors are {1, 5, 25} → 3 divisors



//Code
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int count=0;
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            count++;
            if(i!=n/i){
                count++;
            }
        }
    }
    cout << count<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}