#include<stdio.h>

void rearrange(int arr[], int n) {
	
	int i,j,t;
	
	for(i=0;i<n;i++) {
		
		if(arr[i]==-1 && i<n)
			arr[i]=-1;
		else if(arr[i]!=-1 && i<n) {
			t=arr[i];
			
		}
	}
}

int main() {
	int arr={-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n=sizeof(arr)/sizeof(int);
	rearrange(arr,n);
	return 0;
}
