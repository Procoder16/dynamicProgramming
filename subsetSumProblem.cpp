#include<bits/stdc++.h>
using namespace std;

bool targetSum(int arr[], int sum, int n){
    if(n==0 && sum == 0){
        return true;
    }
    if(sum == 0 && n > 0){
        return true;
    }

    if(n==0 && sum > 0){
        return false;
    }


    if(arr[n-1] <= sum){
        return targetSum(arr, sum-arr[n-1], n-1) || targetSum(arr, sum, n-1);
    }
    else{
        return targetSum(arr, sum, n-1);
    }
} 

int main(){

    int n;
    cout<<"ENTER THE LENGTH OF THE OF THE ARRAY:";
    cin>>n;

    int arr[n];

    cout<<"ENTER THE ELEMENTS OF THE ARRAY:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int sum;
    cout<<"ENTER THE TARGET SUM:";
    cin>>sum;

    if(targetSum(arr, sum, n)){
        cout<<"A SUBSET WITH A GIVEN TARGET SUM IS PRESENT";
    }
    else{
        cout<<"NO SUCH SUBSET IS PRESENT WITH THE TARGET SUM";
    }

    return 0;
}