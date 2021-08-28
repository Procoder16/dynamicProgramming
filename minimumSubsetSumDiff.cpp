#include<bits/stdc++.h>
using namespace std;

static bool t[100][100];

vector<int> subsetSum(int n, int range, int arr[]){
    for(int i = 0; i <= n; i++){
        t[i][0] = true;
    }
    for(int i = 1; i <= range; i++){
        t[0][i] = false;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= range; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> lstRow;
    for(int i = 0; i <= range/2; i++){
        if(t[n][i] == true){
            lstRow.push_back(i);
        }
    }

    return lstRow;
}

int minimumSubsetSumDiff(int n, int arr[]){
    int range = 0;
    for(int i = 0; i < n; i++){
        range+=arr[i];
    }

    vector<int> check = subsetSum(n, range, arr);

    int minDiff = INT_MAX;
    for(int i = 0; i < check.size(); i++){
        minDiff = min(minDiff, range - 2*check[i]);
    }

    return minDiff;
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

    cout<<"MINIMUM SUBSET SUM DIFFERENCE IS:"<<minimumSubsetSumDiff(n, arr);
    
    return 0;
}