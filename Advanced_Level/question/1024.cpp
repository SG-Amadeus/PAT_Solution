#include<bits/stdc++.h>
using namespace std;

string add(string &s){
    int n = s.size();
    string ret;
    int carry = 0;
    for (int i = 0; i < n;i++){
        int  tmp = s[i] + s[n - 1 - i] + carry - '0' - '0';
        char c = (tmp % 10 + '0');
        ret = c+ret;
        carry = tmp / 10;
    }
    if(carry)
        ret = '1'+ret;
    return ret;
}

bool isPalindromic(string &s){
    int n = s.size();
    for (int i = 0; i <= n / 2;i++){
        if(s[i]!=s[n-1-i])
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int k;
    cin >> s>>k;
    int ops = 0;
    if(isPalindromic(s)){
        cout << s << endl << ops <<endl;
        return 0;
    }
    while(ops<k){
        s = add(s);
        ops++;
        if(isPalindromic(s)){
            cout << s << endl << ops << endl;
            return 0;
        }
    }
    if(ops==k){
        cout << s << endl << k << endl;
    }
}