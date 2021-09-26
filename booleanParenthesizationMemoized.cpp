// ALSO CALLED "EVALUATE EXPRESSION TO TRUE"

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

int booleanParenthesization(string s, int i, int j, bool isTrue){
    if(i > j){
        return false;
    }

    if(i == j){
        if(isTrue){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    string temp = to_string(i);
    temp += " ";
    temp += to_string(j);
    temp += " ";
    temp += to_string(isTrue);

    if(m.count(temp)){
        return m[temp];
    }

    int ans = 0;

    for(int k = i + 1; k <= j-1; k += 2){
        int lT = booleanParenthesization(s, i, k-1, true);
        int lF = booleanParenthesization(s, i, k-1, false);
        int rT = booleanParenthesization(s, k + 1, j, true);
        int rF = booleanParenthesization(s, k + 1, j, false);

        if(s[k] == '&'){
            if(isTrue){
                ans += (lT * rT);
            }
            else{
                ans += (lT * rF) + (lF * rT) + (lF * rF);
            }
        }
        else if(s[k] == '|'){
            if(isTrue){
                ans += (lT * rF) + (lF * rT) + (lT * rT);
            }
            else{
                ans += (lF * rF);
            }
        }
        else{
            if(isTrue){
                ans += (lT * rF) + (lF * rT);
            }
            else{
                ans += (lF * rF) + (lT * rT);
            }
        }
    }

    return m[temp] = ans;
}

int main(){

    m.clear();

    string s;
    cout<<"ENTER THE EXPRESSION TO EVALUATE:";
    cin>>s;

    cout<<"NUMBER OF WAYS TO EVALUATE TO TRUE:"<<booleanParenthesization(s, 0, s.length() - 1, true);

    return 0;
}