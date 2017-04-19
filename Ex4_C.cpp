#include<bits/stdc++.h>  
using namespace std;  
struct node  
{  
    int x;  
    int y;  
    int data;  
}a[100100];  
bool cmp(node a,node b)  
{  
    if(a.x==b.x)  
        return a.y<b.y;  
    else  
        return a.x<b.x;  
}  
int main()  
{  
    int mu,tu,du;  
    while(cin>>mu>>tu>>du)  
    {  
        for(int i=0;i<du;i++)  
        {  
            cin>>a[i].y>>a[i].x>>a[i].data;  
        }  
        sort(a,a+du,cmp);  
        for(int i=0;i<du;i++)  
            cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].data<<endl;  
    }  
}