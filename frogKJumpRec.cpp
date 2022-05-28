#include<iostream>
using namespace std;

int frogKJumpRec(int arr[], int k, int n){
    if(n == 0){
        return 0;
    }

    int minEnergy = INT_MAX;

    for(int i = 1; i <= k; i++){
        if(n - i >= 0){
            int energy = frogKJumpRec(arr, k, n - i) + abs(arr[n] - arr[n - i]);
            minEnergy = min(minEnergy, energy);
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