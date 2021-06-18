#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    int* dp = new int[n+1];
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    dp[3] = a[1] + a[3];
    for(int i = 4; i <= n; i++)
        dp[i] = min({dp[i-1], dp[i-2], dp[i-3]}) + a[i];
    cout << dp[n] << '\n';
    int sum = dp[n];
    int i = n;
    string res = "";

    while(i != 1) {
        if(sum - a[i] == dp[i-1]) {
            sum -= a[i];
            res = "+1" + res;
            i -= 1;
        } else if(sum - a[i] == dp[i-2]) {
            sum -= a[i];
            res = "+2" + res;
            i -= 2;
        } else {
            sum -= a[i];
            res = "+3" + res;
            i -= 3;
        }
    }
    cout << res << '\n';
}