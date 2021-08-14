#include<bits/stdc++.h>
using namespace std;

int t[100][100]; //make the dimension according to the constraints

int countSubsetsWithSum(int arr[], int n, int sum){

    //INITIALISATION
    for(int i = 0; i <= n; i++){
        t[i][0] = 1;
    }
    for(int i = 0; i <= sum; i++){
        t[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }    
    return t[n][sum];
}

int main(){

    int n;
    cout<<"ENTER THE SIZE OF THE ARRAY:";
    cin>>n;

    int arr[n];
    cout<<"ENTER THE ELEMENTS OF THE ARRAY:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int sum;
    cout<<"ENTER THE SUM TO CHECK FOR THE SUBSETS:";
    cin>>sum;

    cout<<"THE NUMBER OF SUBSETS WITH GIVEN SUM IS:"<<countSubsetsWithSum(arr, n, sum);

    return 0;
}