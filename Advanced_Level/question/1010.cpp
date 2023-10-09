#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int charTotNum(char c){
    return isdigit(c) ? c - '0' : c - 'a' + 10;
}

long long convertDec(string s,long long radix){
    long long sum = 0;
    long long  idx = 1;
    for (int i = s.size() - 1; i >= 0;i--){
        long long temp = charTotNum(s[i]);
        sum += temp*idx;
        idx *= radix;
    }
    return sum;
}

long long  binarySearch(string s,long long target){
    char c = *max_element(s.begin(), s.end());
    long long left = charTotNum(c)+1;
    long long right = max(left, target);
    while(left<=right){
        long long mid = left + (right - left) / 2;
        long long temp = convertDec(s, mid);
        if(temp<0||temp>target)
            right = mid - 1;
        else if(temp==target)
            return mid;
        else
            left = mid + 1;
    }
    return -1;
}

int main(){
    string n1, n2;
    long long tag, radix;
    cin >> n1 >> n2 >> tag >> radix;

    long long res =tag==1?binarySearch(n2,convertDec(n1,radix)):binarySearch(n1,convertDec(n2,radix));

    if(res==-1){
        printf("Impossible");
    }else
        printf("%lld", res);

    return 0;
}