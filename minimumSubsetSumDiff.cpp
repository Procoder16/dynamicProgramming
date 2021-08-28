#include<bits/stdc++.h>
using namespace std;

static bool t[100][100]; // dynamic programming actual matrix; size according to the contraints 

vector<int> subsetSum(int n, int range, int arr[]){  // function to check for the subset sum
    for(int i = 0; i <= n; i++){ // initialising
        t[i][0] = true;
    }
    for(int i = 1; i <= range; i++){ // initialising
        t[0][i] = false;
    }

    for(int i = 1; i <= n; i++){ // filling the dp matrix according to the subset sum algorithm
        for(int j = 1; j <= range; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<int> lstRow; // vector to store those indices of the last row that has true stored in it
    // This account of last row must be kept because all the indices of the last row will not give us a subset sum

    for(int i = 0; i <= range/2; i++){  // we are just taking the reading till the half way, because the other half contains the S2
        if(t[n][i] == true){
            lstRow.push_back(i);  // pushing the column number as the subset sum possibility
        }
    }

    return lstRow;
}

int minimumSubsetSumDiff(int n, int arr[]){  // function to calculate the minimum subset sum difference
    int range = 0;
    for(int i = 0; i < n; i++){  // here range means the sum of all the elements of the array
        range+=arr[i];
    }

    vector<int> check = subsetSum(n, range, arr);  // the check vector would store the returned vector from the function

    int minDiff = INT_MAX;  
    for(int i = 0; i < check.size(); i++){
        minDiff = min(minDiff, range - 2*check[i]); // the formula was discussed, i.e., (range - 2S1) would be minimised
    }

    return minDiff;
}

int main(){ // main function

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