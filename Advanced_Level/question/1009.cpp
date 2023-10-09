#include <bits/stdc++.h>

using namespace std;

struct poly{
	int n=0;
	float p=0;
};

int main()
{
	int k1;
	scanf("%d", &k1);
	poly a[k1];
	for (int i = 0; i < k1;i++){
		scanf("%d%f", &a[i].n, &a[i].p);
	}

	int k2;
	scanf("%d", &k2);
	poly b;

    map<int, poly,greater<int>> mp;
    
	for (int i = 0; i < k2; i++)
	{
		scanf("%d%f", &b.n, &b.p);
		for (int j = 0; j < k1;j++){
			int tn = a[j].n + b.n;
			float tp = a[j].p * b.p;
			if (tp != 0){
                mp[tn].n = tn;
                mp[tn].p += tp;
            }
		}
	}
    for(auto& m:mp){
        if(abs(m.second.p)<1e-6)
            mp.erase(m.first);
    }

    int cnt=mp.size();
	printf("%d", cnt);
	for (auto&m:mp)
	{
		printf(" %d %.1f", m.second.n, m.second.p);
	}
}