#include<iostream>
#include<limits.h>
using namespace std;

int frogJumpRec(int arr[], int n){
    if(n == 0){
        return 0;
    }

    int oneStep, twoSteps = INT_MAX;
    oneStep = abs(arr[n] - arr[n-1]) + frogJumpRec(arr, n-1);
    if(n > 1){
        twoSteps = abs(arr[n] - arr[n-2]) + frogJumpRec(arr, n-2);
    }
    
    return min(oneStep, twoSteps);
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