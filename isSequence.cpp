#include<iostream>
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

bool isSequence(string s1, string s2){
    if(lcsTopDown(s1, s1.length(), s2, s2.length()) == s1.length()){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string s1, s2;
    cout<<"ENTER THE TWO STRINGS TO CHECK:";
    cin>>s1>>s2;

    cout<<"IS STRING S1 A SEQUENCE OF S2:";
    if(isSequence(s1, s2)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}