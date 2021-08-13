#include<bits/stdc++.h>
using namespace std;

bool t[100][100]; // make the dimension according to the constraints 

bool subsetSumTopDown(int arr[], int sum, int n){
    for(int i = 0; i <= n; i++){
        t[i][0] = true;
    }
    for(int i = 1; i <= sum; i++){
        t[0][i] = false; 
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
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
        return subsetSumTopDown(arr, sum/2, n);
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
        cout<<"THE ARRAY CANNOT BE SPLIT EQUALLY";
    }

    return 0;
}