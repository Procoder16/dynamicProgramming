#include<iostream>
using namespace std;

int countStairWays(int n){
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){

    int n;
    cout<<"ENTER THE NUMBER OF STEPS YOU HAVE:";
    cin>>n;

    cout<<"NUMBER OF WAYS TO REACH THE "<<n<<"th STAIR IS:"<<countStairWays(n);

    return 0;
}