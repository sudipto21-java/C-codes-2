
/** Given an array arr[] of size N and two elements x and y, use counter variables to find which element 
appears most in the array, x or y. If both elements have the same frequency, then return the smaller element.
Note:  We need to return the element, not its count.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1) */

#include<stdio.h>
#include<math.h>

int majorityWins(int a[], int n, int x, int y)
{
	int i,cx=0,cy=0;
	
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
			cx++;
		if(a[i]==y)
			cy++;
	}
	
	if(cx==cy)
	{
		if(x<y)
			return x;
		else
			return y;
	}
	else
	{
		if(cx>cy)
			return x;
		else
			return y;
	}
}

int main()
{
	int n,i,x,y;
	
	printf("enter size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&a[i]);
	}
	
	printf("enter value of x and y\n");
	scanf("%d%d",&x,&y);
	
	printf("major element in array is:%d",majorityWins(a,n,x,y));
	return 0;
}
