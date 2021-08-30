#include<bits/stdc++.h>
using namespace std;

int t[101][101];

int coinChangeCoins(int n, int target, int coins[]){
    for(int i = 0; i <= target; i++){
        t[0][i] = INT_MAX - 1;
    }
    for(int i = 1; i <= n; i++){
        t[i][0] = 0;
    }
    for(int i = 1; i <= target; i++){
        if(i % coins[0] == 0){
            t[1][i] = i/coins[0];
        }
        else{
            t[1][i] = INT_MAX - 1;
        }
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= target; j++){
            if(coins[i-1] <= j){
                t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][target];
}

int main(){

    int targetAmt;
    cout<<"ENTER THE TARGET AMOUNT:";
    cin>>targetAmt;

    int n;
    cout<<"ENTER THE NUMBER OF DENOMINATIONS:";
    cin>>n;

    int coins[n];

    cout<<"ENTER THE DENOMINATINS:";
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    cout<<"MINIMUM NUMBER OF COINS TO GET THE TARGET SUM:"<<coinChangeCoins(n, targetAmt, coins);

    return 0;
}