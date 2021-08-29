#include<bits/stdc++.h>
using namespace std;

int countOfSubsetWithSum(int n, int arr[], int sum){ // count of subset with given sum algorithm function
    if(n == 0 && sum > 0){
        return 0;
    }
    if(n > 0 && sum == 0){
        return 1;
    }
    if(sum == 0 && n == 0){
        return 1;
    }

    if(arr[n-1] <= sum){
        return countOfSubsetWithSum(n-1, arr, sum - arr[n-1]) + countOfSubsetWithSum(n-1, arr, sum);
    }
    else{
        return countOfSubsetWithSum(n-1, arr, sum);
    }
}

int countOfSubsetsWithDiff(int n, int arr[], int diff){

    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum+=arr[i];
    }

    int reqdSum = (diff + totalSum)/2; // formula according to the algorithm discussed

    int count = countOfSubsetWithSum(n, arr, reqdSum);  // count of subset with given sum algorithm function calling

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
