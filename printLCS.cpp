#include<bits/stdc++.h>
using namespace std;

int t[100][100];

string printLCS(string a, string b, int x, int y){

    string ans = "";

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

    int i = x, j = y;

    while(i != 0 || j != 0){
        if(a[i-1] == b[j-1]){
            ans+=a[i-1];
            i--;
            j--;
        }
        else if(t[i-1][j] > t[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;    
}

int main(){

    string str1;
    string str2;

    cout<<"ENTER THE TWO STRINGS:";
    cin>>str1>>str2;

    int len1 = str1.length();
    int len2 = str2.length();

    cout<<"THE LONGEST POSSIBLE SUBSEQUENCE IS:"<<printLCS(str1, str2, len1, len2);

    return 0;
}