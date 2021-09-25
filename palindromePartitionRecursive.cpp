#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int j){
    while(i <= j){
        if(str[i++] != str[j--]){
            return false;
        }
    }

    return true;
}

int palindromePartitionRecursive(string s, int i, int j){

    if(i >= j){
        return 0;
    }

    if(isPalindrome(s, i, j)){
        return 0;
    }

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int tempAns = palindromePartitionRecursive(s, i, k) + palindromePartitionRecursive(s, k + 1, j) + 1;
        ans = min(tempAns, ans); 
    }

    return ans;    
}

int main(){

    string str;
    cout<<"ENTER THE STRING TO COUNT THE NUMBER OF PARTITIONS:";
    cin>>str;

    cout<<"NUMBER OF PARTITIONS REQUIRED TO MAKE IT A PALINDROME:"<<palindromePartitionRecursive(str, 0, str.length()-1);

    return 0;
}