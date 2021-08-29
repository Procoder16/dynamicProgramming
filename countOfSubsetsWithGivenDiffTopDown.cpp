#include<bits/stdc++.h>
using namespace std;

static int t[100][100];

int countOfSubsetWithSumTopDown(int n, int arr[], int sum){ // count of subset with given sum algorithm function
    for(int i = 0; i <= n; i++){ //initialisation
        t[i][0] = 1;
    }
    for(int i = 1; i <= sum; i++){ //initialisation
        t[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int countOfSubsetsWithDiff(int n, int arr[], int diff){

    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum+=arr[i];
    }

    int reqdSum = (diff + totalSum)/2; // formula according to the algorithm discussed

    int count = countOfSubsetWithSumTopDown(n, arr, reqdSum);  // count of subset with given sum algorithm function calling

    return count;
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

    int diff;
    cout<<"ENTER THE DIFFERENCE THAT YOU YOU WANT TO FIND:";
    cin>>diff;

    cout<<"\nTHE COUNT OF SUBSETS WITH THE GIVEN DIFFERENCE IS:"<<countOfSubsetsWithDiff(n, arr, diff);

    return 0;
}
