//Matrix chain multiplication format

#include<iostream>
using namespace std;

int solve(int arr[], int i, int j){
    //base condition
    if(i > j){  // still depends on the solution
        return 0;
    }

    int ans = 0;

    for(int k = i; k < j; k++){
        int temp = solve(arr, i, k) + solve(arr, k + 1, j);
        ans = max(temp, ans);
    }
    
    return ans;
}

int main(){

    return 0;
}