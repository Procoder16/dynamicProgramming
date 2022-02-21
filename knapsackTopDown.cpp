//knapsack using top down method

#include<bits/stdc++.h>
using namespace std;
int t[100][100]; // make according to the constraints

int knapsack(int wt[], int val[], int n, int W){
    for(int i = 0; i < n+1; i++){  // initialisation
        t[i][0] = 0;
    }

    for(int i = 0; i < W+1; i++){   // initialisation
        t[0][i] = 0;
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < W+1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max((val[i-1] + t[i-1][j - wt[i-1]]), t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];
}

int main(){

    int n;
    cout<<"ENTER THE NUMBER OF ITEMS:";
    cin>>n;

    int wt[n];
    int val[n];

    cout<<"ENTER THE WEIGHT OF THE ITEM AND THE VALUE RESPECTIVELY:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>wt[i];
        cin>>val[i];
    }

    int W;
    cout<<"ENTER THE CAPACITY OF THE KNAPSACK:";
    cin>>W;

    
    cout<<"THE MAX PROFIT THAT THE THIEF CAN MAKE IS:"<<knapsack(wt, val, n, W);

    return 0;
}