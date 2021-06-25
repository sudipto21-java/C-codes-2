#include<stdio.h>
#include<string.h>

void merge_len(char w[][10], int l, int m, int r)
{
	printf("\nmerge_len\n");
	int sl,sr,i,j,k,ii;
	sl=m-l+1;
	sr=r-m;
	char L[sl][10];
	char R[sr][10];
	
	for(i=0;i<sl;i++)
	{
		for(ii=0;w[i][ii]!='\0';ii++)
		{
			L[i][ii]=w[l+i][ii];
		}
		L[i][ii]='\0';
	}
	
	for(j=0;j<sr;j++)
	{
		for(ii=0;w[j][ii]!='\0';ii++)
		{
			R[j][ii]=w[m+1+j][ii];
		}
		R[j][ii]='\0';	
	}
	
	i=j=0;
	k=l;
	
	while(i<sl && j<sr)
	{
		if(strlen(L[i])<=strlen(R[j]))
		{
			for(ii=0;L[i][ii]!='\0';ii++)
			{
				w[k][ii]=L[i][ii];
			}
			w[k][ii]='\0';
			i++;
		}
		
		else
		{
			for(ii=0;R[j][ii]!='\0';ii++)
			{
				w[k][ii]=R[j][ii];
			}
			w[k][ii]='\0';
			j++;
		}
		k++;
	}
	
	for(;i<sl;i++,k++)
	{
		for(ii=0;L[i][ii]!='\0';ii++)
		{
			w[k][ii]=L[i][ii];
		}
		w[k][ii]='\0';
	}
	
	for(;j<sr;j++,k++)
	{
		for(ii=0;R[j][ii]!='\0';ii++)
		{
			w[k][ii]=R[j][ii];
		}
		w[k][ii]='\0';
	}
}

void merge_sort_len(char w[][10], int l, int r)
{
	printf("\nmerge_sort_len\n l:%d,r:%d is:\n",l,r);
	if(l<r)
	{
		printf("\nl<r\n");
		int m=l+(r-l)/2;
		
		merge_sort_len(w,l,m);
		merge_sort_len(w,m+1,r);
		merge_len(w,l,m,r);
	}
}

void merge(char w[], int l, int m, int r)
{
	int i,j,k,i2,j2,n1,n2;
	n1=m-l+1;
	n2=r-m;
	
	char L[n1], R[n2];
	
	for(i=0;i<n1;i++)
	{
		L[i]=w[l+i];
	}
	
	for(j=0;j<n2;j++)
	{
		R[j]=w[m+j+1];
	}
	
	i=j=0;
	k=l;
	
	while(i<n1 && j<n2)
	{
		if((int)(L[i]) <= (int)(R[j]))
		{
			w[k]=L[i];
			i++;
		}
		
		else
		{
			w[k]=R[j];
			j++;
		}
		k++;
	}
	
	for(;i<n1;i++,k++)
	{
		w[k]=L[i];
	}
	
	for(;j<n2;j++,k++)
	{
		w[k]=R[j];
	}	
}

void merge_sort(char w[], int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		
		merge_sort(w,l,m);
		merge_sort(w,m+1,r);
		
		merge(w,l,m,r);
	}
}

void print(char w[][10], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s ",w[i]);
	} 
	
	printf("\n");
}

int main()
{
	int n,i;
	printf("enter number of words:");
	scanf("%d",&n);
	char word[n][10];
	
	for(i=0;i<n;i++)
	{
		printf("enter word:");
		scanf("%s",word[i]);
		word[i][strlen(word[i])]='\0';
	}
	
	printf("\nwords are\n");
	print(word,n);

	merge_sort_len(word,0,n-1);
	printf("\nwords after sorting according to lenght\n");
	print(word,n);
	
	for(i=0;i<n;i++)
	{
		merge_sort(word[i], 0, strlen(word[i])-1);
	}
	printf("\nwords after sorting individualy\n");
	print(word,n);
	
	return 0;
}
