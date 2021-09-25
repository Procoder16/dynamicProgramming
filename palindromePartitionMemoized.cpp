#include<bits/stdc++.h>
using namespace std;

static int t[1001][1001];

bool isPalindrome(string str, int i, int j){
    while(i <= j){
        if(str[i++] != str[j--]){
            return false;
        }
    }

    return true;
}

int palindromePartitionMemoized(string s, int i, int j){

    if(i >= j){
        return 0;
    }

    if(isPalindrome(s, i, j)){
        return 0;
    }

    if(t[i][j] != -1){
        return t[i][j]; 
    }

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int tempAns = palindromePartitionMemoized(s, i, k) + palindromePartitionMemoized(s, k + 1, j) + 1;
        ans = min(tempAns, ans); 
    }

    return t[i][j] = ans;    
}

int main(){

    string str;
    cout<<"ENTER THE STRING TO COUNT THE NUMBER OF PARTITIONS:";
    cin>>str;

    memset(t, -1, sizeof(t));

    cout<<"NUMBER OF PARTITIONS REQUIRED TO MAKE IT A PALINDROME:"<<palindromePartitionMemoized(str, 0, str.length()-1);

    return 0;
}