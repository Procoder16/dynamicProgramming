#include<bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2, int len1, int len2){
    if(len1 == 0 || len2 == 0){
        return 0;
    }

    if(str1[len1 - 1] == str2[len2 - 1]){
        return 1 + lcs(str1, str2, len1 - 1, len2 - 1);
    }
    else{
        return max(lcs(str1, str2, len1 - 1, len2), lcs(str1, str2, len1, len2 - 1));
    }
}

int main(){

    string a;
    string b;

    cout<<"ENTER THE TWO STRINGS RESPECTIVELY:";
    cin>>a>>b;

    int len1 = a.length();
    int len2 = b.length();

    cout<<"LONGEST COMMON SUBSEQUENCE THAT CAN BE MADE IS OF LENGTH "<<lcs(a, b, len1, len2);

    return 0;
}