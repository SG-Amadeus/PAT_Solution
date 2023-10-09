#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
	float temp;
	char ch[3] = {'W', 'T', 'L'};
	float max = 0;
	int num[3]{0};
	float ans = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++){
			scanf("%f", &temp);
			if(temp>=max){
				max = temp;
				num[i] = j;
			}
		}
		
		ans *= max;
        max = 0;
	}
	ans = 2 * (ans * 0.65 - 1);
	printf("%c %c %c %.2f",ch[num[0]],ch[num[1]],ch[num[2]],ans);
}