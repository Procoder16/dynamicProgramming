#include<bits/stdc++.h>
using namespace std;
int t[100][100]; // make according to the constraints

int rodCutting(int len, int price[], int length[], int n){
    for(int i = 0; i < n+1; i++){  // initialisation
        t[i][0] = 0;
    }

    for(int i = 0; i < len+1; i++){   // initialisation
        t[0][i] = 0;
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < len+1; j++){
            if(length[i-1] <= j){
                t[i][j] = max((price[i-1] + t[i-1][j - length[i-1]]), t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][len];
}

int main(){

    int len;
    cout<<"ENTER THE LENGTH OF THE ROD:";
    cin>>len;

    int n = len;
    int price[n];

    cout<<"ENTER THE PRICES FOR THE "<<n<<" PIECES INDIVIDUALLY:";
    for(int i = 0; i < n; i++){
        cin>>price[i];
    }

    int length[n];
    for(int i = 0; i < n; i++){
        length[i] = i+1;
    }

    cout<<"THE MAX PROFIT THAT CAN BE MADE:"<<rodCutting(len, price, length, n);

    return 0;
}