#include <iostream>
using namespace std;
int main(){
    int a = 0, b = 0;
    cin >> a >> b;
    string num = to_string(a + b), res = "";
    for (int i = num.size() - 1; i >= 0;i--){
        int fix = num[0] == '-' ? 1 : 0;
        res = num[i] + res;
        if(i > fix&&(num.size() - i)%3 == 0){
            res = ',' + res;
        }
    }
    cout << res;
}
