#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct student{
    char id[30];
    int hh,mm,ss;
    bool operator > (const student &rhs){
        if(hh!=rhs.hh)return hh>rhs.hh;
        if(mm!=rhs.mm)return mm>rhs.mm;
        return ss>rhs.ss;
    }
}minStu,maxStu,stu;


void init(){
    minStu.hh=24;
    minStu.mm=60;
    minStu.ss=60;


    maxStu.hh=0;
    maxStu.mm=0;
    maxStu.ss=0;
}

int main(){
    int m;
    cin>>m;
    init();
    while(m--){
        scanf("%s %d:%d:%d",&stu.id,&stu.hh,&stu.mm,&stu.ss);
        minStu=minStu>stu?stu:minStu;
         scanf("%d:%d:%d",&stu.hh,&stu.mm,&stu.ss);
        maxStu=stu>maxStu?stu:maxStu;
    }
    printf("%s %s",minStu.id,maxStu.id);
}