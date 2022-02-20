//Standard Knapsack problem solved using recursion

#include<iostream>
using namespace std;

int knapsack(int wt[], int val[], int w, int n){
    if(n == 0 || w == 0){
        return 0;
    }

    if(wt[n-1] <= w){
        return max((val[n-1] + knapsack(wt, val, w - wt[n-1], n-1)), knapsack(wt, val, w, n-1));
    }

    else{
        return knapsack(wt, val, w, n-1);
    }
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

    cout<<"THE MAX PROFIT THAT THE THIEF CAN MAKE IS:"<<knapsack(wt, val, W, n);

    return 0;
}