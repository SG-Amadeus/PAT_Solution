#include <bits/stdc++.h>
#include <iostream>

using namespace std;


struct student
{
    string id;
    int grade[4];
	int rank[4];
};
const char str[4] = {'A', 'C', 'M', 'E'};
int num = 0;
unordered_map<string, student*> mp;

void query(string& id){
    if(!mp.count(id))
        cout << "N/A" << endl;
    else{
        int rank = mp[id]->rank[0];
        int cnt = 0;
        for (int i = 1; i < 4;i++){
            if(rank>mp[id]->rank[i]){
                rank = mp[id]->rank[i];
                cnt = i;
            }
        }
        cout << rank << " " << str[cnt] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<student> stu(m);
    for (int i = 0; i < m;i++){
        cin >> stu[i].id;

        cin >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
        stu[i].grade[0] = ((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3] )/ 3.0 + 0.5);
    }

    for (int i = 0; i < 4;i++){
        num = i;
        sort(stu.begin(), stu.end(), [](const auto &a, const auto &b)
             { return a.grade[num] > b.grade[num]; });
        for (int j = 0; j < m;j++){
            stu[j].rank[i] = j + 1;
            if(j>0&&stu[j].grade[i]==stu[j-1].grade[i]){
                stu[j].rank[i] = stu[j - 1].rank[i];
            }
        }
    }

    for (int i = 0; i < m;i++)
    {
        mp[stu[i].id] = &stu[i];
    }

    string queryId;
    while(n--){
        cin >> queryId;
        query(queryId);
    }
    return 0;
}