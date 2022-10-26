//Longest Common subsequence using top down method

#include<iostream>
using namespace std;

int t[100][100];

int lcsTopDown(string x, string y, int n, int m){
    
    for(int i = 0; i <= n; i++){
        t[i][0] = 0;
    }

    for(int i = 0; i <= m; i++){
        t[0][i] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    return t[n][m];
}

int main(){

    string x;
    string y;

    cout<<"ENTER THE TWO STRINGS:";
    cin>>x>>y;

    int n = x.length();
    int m = y.length();

    cout<<"LENGTH OF THE LONGEST SUBSEQUENCE POSSIBLE:"<<lcsTopDown(x, y, n, m);

    return 0;
}