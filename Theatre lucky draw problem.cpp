#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int seat_no;
	char fwd_pass, rev_pass;
	struct node *fwd,*bwd;
};

struct node *head=NULL;

void create_node_and_front_pass(char ch, int s_no)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	struct node *temp;
	
	nn->fwd_pass=ch;
	nn->seat_no=s_no;
	nn->fwd=NULL;
	nn->bwd=NULL;
	
	if(head==NULL)
		head=nn;
	else
	{
		temp=head;
		while(temp->fwd!=NULL)
		{
			temp=temp->fwd;
		}
		temp->fwd=nn;
		nn->bwd=temp;
	}
}

void back_pass(struct node *strt, char str[], int cap)
{
	struct node *last;
	int i=0,j,temp=0,count=1;
	
	if(strt==NULL)
		printf("list is empty\n");
		
	else
	{
		while(strt->fwd!=NULL)
		{
			strt=strt->fwd;
		}
		last=strt;
	}
	
	while(last->fwd_pass!=str[i])
	{
		i++;
	}
	
	for(; i<strlen(str) ;i++,temp++)
	{
		if(temp<strlen(str))
		{
			temp=i;
			last->rev_pass=str[++temp];
			last=last->bwd;
			++count;
		}
		else
			break;
	}
	
	i=0,temp=0;
	
	while(count<=cap)
	{
		last->rev_pass=str[i];
		last=last->bwd;
		++i;
		++count;
	}	
}

void print_list(struct node *strt)
{
	if(strt==NULL)
		printf("list is empty\n");
	else
	{
		while(strt!=NULL)
		{
			printf("%d-%c%c\n",strt->seat_no,strt->fwd_pass,strt->rev_pass);
			strt=strt->fwd;
		}
	}
}

void lucky_win(struct node *strt)
{
	if(strt==NULL)
		printf("no lucky winner available");
	else
	{
		while(strt->fwd_pass!=strt->rev_pass)
		{
			strt=strt->fwd;
		}
		
		printf("\ncongrates!!\nseat number:%d you've won the contest",strt->seat_no);
	}
}

int main()
{
	int i,seat_no=1,seat_cap,temp=0;
	char th_name[20];
	
	printf("enter name of the theatre:");
	scanf("%s",th_name);
	printf("enter number of seats:");
	scanf("%d",&seat_cap);
	
	for(i=0;i<strlen(th_name);i++)
	{
		create_node_and_front_pass(th_name[i],seat_no++);
	}
	
	while(i<seat_cap)
	{
		create_node_and_front_pass(th_name[temp],seat_no++);
		++i;
		++temp;
	}
	
	back_pass(head,th_name,seat_cap);
	print_list(head);
	lucky_win(head);
	
	return 0;
}
