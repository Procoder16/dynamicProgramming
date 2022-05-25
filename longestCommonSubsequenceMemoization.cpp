#include<iostream>
using namespace std;

int t[100][100];

int lcsMemoization(string x, string y, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }

    if(t[n][m] != -1){
        return t[n][m];
    }

    if(x[n-1] == y[m-1]){
        return t[n][m] = 1 + lcsMemoization(x, y, n - 1, m - 1);
    } 
    else{
        return t[n][m] = max(lcsMemoization(x, y, n - 1, m), lcsMemoization(x, y, n, m - 1)); 
    }
}

int main(){

    memset(t, -1, sizeof(t));

    string x;
    string y;

    cout<<"ENTER THE TWO STRINGS:";
    cin>>x>>y;

    int n = x.length();
    int m = y.length();

    cout<<"LENGTH OF THE LONGEST SUBSEQUENCE POSSIBLE:"<<lcsMemoization(x, y, n, m);

    return 0;
}