#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int lps(string a, int len1){
    
    string b = a;

    reverse(b.begin(), b.end());

    for(int i = 0; i <= len1; i++){
        t[i][0] = 0;
    }

    for(int i = 0; i <= len1; i++){
        t[0][i] = 0;
    }

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len1; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[len1][len1];
}

int main(){

    string a;
    cout<<"ENTER THE STRING TO FIND THE LONGEST PALINDROMIC SUBSEQUENCE:";
    cin>>a;

    int len1 = a.length();

    cout<<"LENGTH OF THE LONGEST PALINDROMIC SUBSEQUENCE : "<<lps(a, len1); 

    return 0;
}