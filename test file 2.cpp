#include <iostream>
#include<stdio.h>
#include<string.h>  
using namespace std;

class node
{
    public:
        
        int i;
        int a=1;
        string city;
        int pci;
        node* next;
        node* head=NULL;
        node(string city, int pci)
        {
            this->city=city;
            this->pci=pci;
            this->i=a++;
            next=NULL;
        }
};

class graph
{
    public:
    node* head=NULL;
    
	void dijkstra(int group[10][10], int n, int sc_node)
	{
    	int visited[n+1],distance[n+1];
    	int min,c,i,n_node;
    
    	for(i=1;i<=n;i++)
    	{
        	distance[i]=group[sc_node][i];
        	visited[i]=0;
    	}
    	
    	visited[sc_node]=1;
    	cout<<sc_node<<endl;
    	c=1;
    	
    	while(c<=n-1)
    	{
        	min=999;
        	for(i=1;i<=n;i++)
        	{
            	if(!visited[i] && distance[i]<min)
            	{
                	min=distance[i];
                	n_node=i;
            	}
        	}
        
        	if(!visited[n_node])
        	{
            	visited[n_node]=1;
            	cout<<n_node<<endl;
        	}
        	
        	for(i=1;i<=n;i++)
        	{
            	if(!visited[i])
            	{
                	distance[i]=group[n_node][i];
            	}
        	}
        	c++;
    }
}

void insert(string city, int n)
{
    node* nn=new node(city,n);
    
    if(head==NULL)
        head=nn;
    else
    {
        node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=nn;
    }
}

void count()
{
    node* temp=head;
    int c=0;
    
    while(temp!=NULL)
    {
        if(temp->pci<50000)
            c++;
        temp=temp->next;
    }
    cout<<c;
}
};

int main()
{
    graph g;
    int am[10][10];
    string c_name;
    int i,j,n,f=0,v,income,c=0;
    cin>>n;
    
	while(c++<n)
    {
        cin>>c_name;
        cin>>income;
        g.insert(c_name, income);
    }
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            am[i][j]=999;
    
    for(c=0;c<n*n;c++)
    {
        cin>>i>>j;
        if(i==0 && j==0)
            break;
        cin>>v;
        am[i][j]=v;
    }
    
    cin>>f;     
    g.dijkstra(am,n,f);
    g.count();
    
    return 0;
}  
