#include<bits/stdc++.h>
using namespace std;

int targetSum(int n, int arr[], int sum){
    if(n == 0 && sum == 0){
        return 1;
    }
    if(n == 0 && sum != 0){
        return 0;
    }

    return targetSum(n-1, arr, sum - arr[n-1]) + targetSum(n-1, arr, sum + arr[n-1]);
}

int main(){

    int n;
    cout<<"ENTER THE SIZE OF THE ARRAY:";
    cin>>n;

    int arr[n];

    cout<<"ENTER THE ELEMENTS OF THE ARRAY:";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int sum;
    cout<<"ENTER THE TOTAL SUM THAT YOU YOU WANT TO GET:";
    cin>>sum;

    cout<<"\nTHE COUNT OF ARRANGEMENTS WITH THE GIVEN SUM IS:"<<targetSum(n, arr, sum); // 0 is sent as the default current sum

    return 0;
}
