#include<bits/stdc++.h>
using namespace std;

bool subsetSumRecursion(int arr[], int sum, int n){
    if(n == 0 && sum == 0){
        return true;
    }
    if(n == 0 && sum > 0){
        return false;
    }
    if(n > 0 && sum == 0){
        return true;
    }

    if(arr[n-1] <= sum){
        return subsetSumRecursion(arr, sum - arr[n-1], n-1) || subsetSumRecursion(arr, sum, n-1);
    }
    else{
        return subsetSumRecursion(arr, sum, n-1);
    }
}

bool partitionSplit(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+=arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    else{
        return subsetSumRecursion(arr, sum/2, n);
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

    if(partitionSplit(arr, n)){
        cout<<"THE ARRAY CAN BE SPLIT EASILY WITH EQUAL SUM";
    }
    else{
        cout<<"THE ARRAY CANNOT BE SPLIT EASILY";
    }

    return 0;
}