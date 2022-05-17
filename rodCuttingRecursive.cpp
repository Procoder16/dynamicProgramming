#include<iostream>
using namespace std;

int rodCutting(int len, int price[], int length[], int n){
    
    if(n == 0 || len == 0){
        return 0;
    }
    if(length[n-1] <= len){
        return max(price[n-1] + rodCutting(len - length[n-1], price, length, n), rodCutting(len, price, length, n-1));
    }
    else{
        return rodCutting(len, price, length, n-1);
    } 
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