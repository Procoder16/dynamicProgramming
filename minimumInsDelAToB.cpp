#include<iostream>
using namespace std;

int t[100][100];

void minInsDelAToB(string a, string b, int x, int y){
    for(int i = 0; i <= x; i++){
        t[i][0] = 0;
    }
    for(int i = 0; i <= y; i++){
        t[0][i] = 0;
    }

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    int lcs = t[x][y];

    int del = a.length() - lcs;
    int ins = b.length() - lcs;

    cout<<"NUMBER OF DELETIONS REQUIRED : "<<del<<endl;
    cout<<"NUMBER OF INSERTIONS REQUIRED: "<<ins;
}

int main(){

    string a, b;

    cout<<"ENTER THE TWO STRINGS:";
    cin>>a>>b;

    int len1 = a.length();
    int len2 = b.length();

    minInsDelAToB(a, b, len1, len2);

    return 0;
}