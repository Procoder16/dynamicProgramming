#include<iostream>
using namespace std;

int coinChangeWays(int amt, int n, int coins[]){

    if(n == 0 && amt == 0){
        return 1;
    }

    if(n == 0 && amt > 0){
        return 0;
    }

    if(n > 0 && amt == 0){
        return 1;
    }

    if(coins[n-1] <= amt){
        return coinChangeWays(amt - coins[n-1], n, coins) + coinChangeWays(amt, n-1, coins);
    }
    else{
        return coinChangeWays(amt, n-1, coins);
    }
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