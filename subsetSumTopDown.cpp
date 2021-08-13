#include<bits/stdc++.h>
using namespace std;

bool t[100][100]; // make according to the constraints

bool targetSum(int arr[], int sum, int n){
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

    for(int i = 0; i <= n; i++){
        t[i][0] = true;
    }

    for(int i = 1; i<=sum; i++){
        t[0][i] = false;
    }

    if(targetSum(arr, sum, n)){
        cout<<"A SUBSET WITH A GIVEN TARGET SUM IS PRESENT";
    }
    else{
        cout<<"NO SUCH SUBSET IS PRESENT WITH THE TARGET SUM";
    }

    return 0;
}