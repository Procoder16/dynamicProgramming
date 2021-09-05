#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int lcsTopDown(string s1, int x, string s2, int y){
    for(int i = 0; i <= x; i++){
        t[i][0] = 0;
    }

    for(int i = 0; i <= y; i++){
        t[0][i] = 0;
    }  

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[x][y];
}

int minDelToPalindrome(string s, int n){

    string rev = s;
    reverse(rev.begin(), rev.end());

    int lcs = lcsTopDown(s, n, rev, n);

    return n - lcs;
}

int main(){

    string str;
    cout<<"ENTER THE STRING:";
    cin>>str;

    cout<<"MINIMUM NUMBER OF DELETIONS NEEDED:"<<minDelToPalindrome(str, str.length());

    return 0;
}