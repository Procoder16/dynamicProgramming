#include<bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int mcmRecursive(int arr[], int i, int j){

    if(i >= j){
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }
    
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int tempAns = mcmRecursive(arr, i, k) + mcmRecursive(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);

        ans = min(ans, tempAns);
    }

    return t[i][j] = ans;
}

int main(){

    memset(t, -1, sizeof(t));

    int n;
    cout<<"ENTER THE LENGTH OF THE ARRAY:";
    cin>>n;

    int arr[n];
    cout<<"ENTER THE DIMENSIONS OF THE MATRIX IN THE ARRAY:\n";
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }

    cout<<"MINIMUM COST TO MULTIPLY THE MATRICES:"<<mcmRecursive(arr, 1, n-1);

    return 0;
}