#include<stdio.h>

void swap(int *p1, int *p2) {
	
	int t=*p1;
	*p1=*p2;
	*p2=t;
}

int partition(int arr[], int l, int r) {
	
	int pivot=arr[r];
	int i=l-1,j;
	
	for(j=l;j<=r-1;j++) {
		
		if(arr[j]<pivot) {
			
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	
	swap(&arr[i+1],&arr[r]);
	return (i+1);
}

void QuickSort(int arr[], int l, int r) {
	
	int pi;
	
	if(l<r) {
		
		pi=partition(arr,l,r);
		QuickSort(arr,l,pi-1);
		QuickSort(arr,pi+1,r);
	}
}

void checkAp1(int arr[], int sum, int n) {		// time complexity is O(n^2)
	
	int i,j;
	
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			
			if(arr[i]+arr[j]==sum)
				printf("%d %d",arr[i],arr[j]);
		}
	}
}

void checkAp2(int arr[], int sum, int n) {		// time and space complexity depends upon sorting algo being used
	
	QuickSort(arr,0,n-1);
	int l=0,r=n-1;

	while(l<r) {

		if(arr[l]+arr[r]==sum) {
			printf("%d %d",arr[l],arr[r]);
			break;
		}
		
		else if(arr[l]+arr[r]<sum)
			l++;
		else
			r--;
	}
}

int main() {
	
	int arr[]={0, -1, 2, -3, 1};
	int sum=-2;
	checkAp1(arr,sum,5);
	printf("\n");
	checkAp2(arr,sum,5);
	return 0;
}
