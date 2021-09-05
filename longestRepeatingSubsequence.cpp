#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int lcsTopDown(string x, string y, int n){
    
    for(int i = 0; i <= n; i++){
        t[i][0] = 0;
    }

    for(int i = 0; i <= n; i++){
        t[0][i] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(x[i-1] == y[j-1] && i != j){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    return t[n][n];
}

int lrs(string s, int n){

    string s2 = s;

    return lcsTopDown(s, s2, n);
}

int main(){

    string x;

    cout<<"ENTER THE TWO STRINGS:";
    cin>>x;

    int n = x.length();

    cout<<"LENGTH OF THE LONGEST SUBSEQUENCE POSSIBLE:"<<lrs(x, n);

    return 0;
}