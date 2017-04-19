#include <iostream>  
using namespace std;  
struct node  
{  
    int row;  
    int col;  
    int data;  
}mp[1005];  
void func(int n,int key)  
{  
    int i,flag=0;  
    for(i=0;i<n;i++)  
    {  
        if(mp[i].data==key)  
            flag=1;  
    }  
    if(flag)  
        cout<<"OK"<<endl;  
    else  
        cout<<"ERROR"<<endl;  
}  
int main()  
{  
    int mu,nu,tu;  
    int i,k;  
    while(cin>>mu>>nu>>tu)  
    {  
        for(i=0;i<tu;i++)  
            cin>>mp[i].row>>mp[i].col>>mp[i].data;  
        cin>>k;  
        func(tu,k);  
    }  
    return 0;  
}