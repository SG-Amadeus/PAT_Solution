#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n<=1)
        return false;
    for (int i = 2; i <= sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

bool reversePrime(int num,int radix){
    int sum = 0;
    while(num){
        sum = sum * radix + num % radix;
        num /= radix;
    }
    return isprime(sum);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num, radix;
    while(cin>>num){
        if(num<0)
            return 0;
        cin >> radix;
        if(!isprime(num))
            cout << "No" << endl;
        else if(reversePrime(num,radix))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}