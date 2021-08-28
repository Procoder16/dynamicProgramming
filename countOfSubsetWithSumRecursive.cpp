#include<bits/stdc++.h>
using namespace std;

int countSubsetsWithSum(int arr[], int n, int sum){

    if(n == 0 && sum == 0){
        return 1;
    }
    if(sum == 0 && n > 0){
        return 1;
    }
    if(n == 0 && sum > 0){
        return 0;
    }

    if(arr[n-1] <= sum){
        return countSubsetsWithSum(arr, n-1, sum-arr[n-1]) + countSubsetsWithSum(arr, n-1, sum);  
        // adding both the components because there can be a case that if you include an item and getting the sum... and there can also be a case that u don't add but then also get a sum later on
    }
    else{
        return countSubsetsWithSum(arr, n-1, sum);
    }  
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