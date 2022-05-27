#include<iostream>
#include<limits.h>
using namespace std;

int frogJumpRec(int arr[], int n){
    int dp[n] = {0};

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int singleStep = dp[i-1] + abs(arr[i] - arr[i-1]);
        int doubleStep = INT_MAX;
        if(i > 1){
            doubleStep = dp[i-2] + abs(arr[i] - arr[i-2]);
        }

        dp[i] = min(singleStep, doubleStep);
    }

    return dp[n-1];
}

int main(){

    int n;
    cout<<"ENTER THE LENGTH OF THE STAIRCASE:";
    cin>>n;

    int arr[n];

    cout<<"ENTER THE ENERGY FOR EACH STAIR:";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int ans = frogJumpRec(arr, n-1);

    cout<<"MINIMUM ENERGY TO REACH THE LAST STAIR:"<<ans;

    return 0;
}