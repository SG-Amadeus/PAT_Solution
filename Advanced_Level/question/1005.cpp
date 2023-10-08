#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    string s;
    cin>>s;
    long long  sum = 0;
    for(auto& c:s){
        sum+=c-'0';
    }
    string strSum = to_string(sum);
    for(int i=0;i<strSum.size();i++){
        cout<<arr[strSum[i]-'0'];
        if(i!=strSum.size()-1)cout<<' ';
    }
    return 0;
}