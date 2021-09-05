#include<bits/stdc++.h>
using namespace std;

int t[100][100];

void printSCS(string s1, int x, string s2, int y){

    string ans = "";

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

    int i = x, j = y;
    while(i != 0 || j != 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }

        else if(t[i-1][j] > t[i][j-1]){
            ans += s1[i-1];
            i--;
        }

        else{
            ans += s2[j-1];
            j--;
        }
    }

    while(i > 0){
        ans += s1[i-1];
    }

    while(j > 0){
        ans += s2[j-1]; 
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.length(); i++){
        cout<<ans[i];
    }
}

int main(){

    string str1, str2;
    cout<<"ENTER THE TWO STRINGS:";
    cin>>str1>>str2;

    int len1 = str1.length();
    int len2 = str2.length();

    cout<<"THE SHORTEST COMMON SUPERSEQUENCE OF THE TWO STRINGS IS:";
    printSCS(str1, len1, str2, len2);

    return 0;
}