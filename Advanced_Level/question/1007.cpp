#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> nums(k, 0);
    int cnt = 0;
    for (int i = 0; i < k;i++){
        cin >> nums[i];
        cnt += nums[i] < 0;
    }
    int left = 0, right = 0,retL=0,retR=0;
    int sum = 0,maxSum=-1;
    while(right<k){
        sum+=nums[right];
        if(sum<0){
            sum=0;
            left = right+1;
        }else if(sum>maxSum){
            maxSum =sum;
            retL = left;
            retR = right;
        }
        right++;
    }
        if (cnt == k)
        {
            cout << 0 << " " << nums[0] << " " << nums[k - 1] << endl;
        }
        else
            cout <<  maxSum << " " << nums[retL] << " " << nums[retR] << endl;
}