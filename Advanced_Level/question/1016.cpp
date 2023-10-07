#include<bits/stdc++.h>
using namespace std;

int timepay[24];

struct Time{
    int MM, dd, hh, mm;
    bool operator == (const Time & rhs){
        return dd == rhs.dd && hh == rhs.hh && mm == rhs.mm;
    }
    bool operator !=(const Time & rhs){
        return dd != rhs.dd || hh != rhs.hh || mm != rhs.mm;
    }
};

struct Record{
    string id;
    Time callTime;
    int  online;
};


bool cmp(const Record& a ,const Record& b){
    if(a.id!=b.id)
        return a.id < b.id;
    if(a.callTime.dd!=b.callTime.dd)
        return a.callTime.dd < b.callTime.dd;
    if(a.callTime.hh!=b.callTime.hh)
        return a.callTime.hh < b.callTime.hh;
    return a.callTime.mm < b.callTime.mm;    
}

int TimeSub(Time a,Time b){
    int min1, min2;
    min1 = a.dd * 24 * 60 + a.hh * 60 + a.mm;
    min2 = b.dd * 24 * 60 + b.hh * 60 + b.mm;
    return abs(min1 - min2);
}



int countCost(Time on,Time off){
    int sum = 0;
    while(on!=off){
        if(on.dd==off.dd&&on.hh==off.hh){
            sum += timepay[on.hh] * (off.mm-on.mm);
            on.mm = off.mm;
        }else{
            sum += timepay[on.hh] * (60 - on.mm);
            on.mm = 0;
            on.hh++;
            on.dd += on.hh / 24;
            on.hh %= 24;
        }
    }
    return sum;
}

int main(){
        ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    for (int i = 0; i < 24;i++){
        cin >> timepay[i];
    }
    cin >> n;
    vector<Record> record(n);
    string online;
    char c;
    for (int i = 0; i < n; i++){
        cin >> record[i].id;
        cin>> record[i].callTime.MM>>c>>record[i].callTime.dd>>c>>record[i].callTime.hh>>c>>record[i].callTime.mm;
        cin >> online;
        if(online=="on-line")
            record[i].online = 1;
    }
    sort(record.begin(), record.end(), cmp);
    
    int sum = 0;
    bool last_online = false;
    Time begin, end;
    unordered_map<string, int> mp;

    for (int i = 0; i < n;i++){
        Record rec = record[i];
        if(rec.online){
            begin = rec.callTime;
            last_online = true;
        }else if(last_online&&!rec.online){
            end = rec.callTime;
            last_online = false;

            int minutes = TimeSub(begin, end);
            int recCost = countCost(begin, end);
            sum += recCost;

            if(!mp.count(rec.id)){
                mp[rec.id]++;
                printf("%s %02d\n", rec.id.data(),rec.callTime.MM);
            }
            printf("%02d:%02d:%02d ", begin.dd, begin.hh, begin.mm);
            printf("%02d:%02d:%02d ",end.dd, end.hh, end.mm);
            printf("%d $%.2lf\n", minutes, 1.0*recCost/100);
        }
        if(i == n-1||rec.id!=record[i+1].id){
            if (sum != 0) 
                printf("Total amount: $%.2lf\n", 1.0*sum/100);
            
            sum = 0;
            last_online = false;
        }
    }
}