#include<iostream>
using namespace std;

int frogKJumpRec(int arr[], int k, int n){
    int dp[n];
    dp[0] = 0;

    int minEnergy = INT_MAX;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                int energy = dp[i - j] + abs(arr[i] - arr[i - j]);
                minEnergy = min(minEnergy, energy);
            }
        }
    }

    return minEnergy;
}

int main(){

    int n;
    cout<<"ENTER THE NUMBER OF STEPS:";
    cin>>n;

    int arr[n];

    int k;
    cout<<"ENTER THE MAX STEPS THAT THE FROG CAN TAKE:";
    cin>>k;

    int minEnergy = frogKJumpRec(arr, k, n - 1);

    cout<<"THE MINIMUM ENERGY REQUIRED BY THE FROG WOULD BE:"<<minEnergy;

    return 0;
}