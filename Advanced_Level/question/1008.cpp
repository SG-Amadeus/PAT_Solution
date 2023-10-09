#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    int total =0;
    for(int i = 0;i<n;i++){
        int sub = a[i+1]-a[i];
        if(sub<0){
            total += 5-sub*4;
        }else{
            total +=5+sub*6;
        }
    }
    cout<<total<<endl;
    return 0;
}