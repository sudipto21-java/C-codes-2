#include<stdio.h>

int getPivot(int arr[], int n) {
	
	int i,p;
	
	for(i=0;i<n;i++) {
		
		if(arr[i]<arr[i+1])
			continue;
			
		else {
			return i+1;
		}
	}
	
	return -1;
}

int binarySearch(int arr[], int l, int r, int k) {
	
	int m;
	while(l<r) {
		
		m=(l+r)/2;
		
		if(arr[m]==k)
			return m;
			
		else if(arr[m]>k)
			r=m-1;
			
		else
			l=m+1;
	}
}

int search(int arr[], int n, int k) {
	
	int p=getPivot(arr,9);
	
	if(p==-1)
		binarySearch(arr,0,n-1,k);
	
	else if(arr[p]==k)
		printf("%d",p);
		
	else if(arr[0]<k)
		return binarySearch(arr,0,p-1,k);
		
	else
		return binarySearch(arr,p,n-1,k);
}

int main() {
	
	int arr[9]={5,6,7,8,9,10,1,2,3};
	int key=7;
	
	printf("%d",search(arr,9,key));
	
	return 0;
}
