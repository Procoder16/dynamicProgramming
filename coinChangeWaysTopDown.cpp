#include<iostream>
using namespace std;

int t[101][101];

int coinChangeWays(int amt, int n, int coins[]){

    for(int i = 0; i <= n; i++){
        t[i][0] = 1;
    }
    for(int i = 1; i <= amt; i++){
        t[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amt; j++){
            if(coins[i-1] <= j){
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][amt];
}

int main(){

    int amt;
    cout<<"ENTER THE TARGET AMOUNT:";
    cin>>amt;

    int n;
    cout<<"ENTER THE NUMBERS OF DENOMINATIONS:";
    cin>>n;

    int coins[n];

    cout<<"ENTER THE VALUES OF THE DENIMINATIONS:";
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    cout<<"THE MAXIMUM NUMBER OF WAYS ARE:"<<coinChangeWays(amt, n, coins);

    return 0;
}