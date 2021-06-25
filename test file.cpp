#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=1;
	
	// first question
	if(i)
		printf("1.%d",i);
	else
		printf("1.else");
		
	// second question	
	if(++i)
		printf("\n2.%d",i);
	else
		printf("2.else");
	
	printf("\n%d",i);
		
	// third question	
	if(i=4)
		printf("\n3.%d",i);
	else
		printf("3.else");
	
	printf("\n%d",i);
	
	// fourth question
	const int a=1;
//	a+=1;	uncommenting this line will give compile time error as a constant is a read only variable ie once declared can not be changed
	printf("4.a=%d\n",a);
	
	// fifth question	
	if(i==0)
		printf("\n5.inside if");
	else
		printf("\n5.out of if\n");
		
	// sixth question
	if(i!=4)
		printf("6.inside if\n");
		printf("6.enjoy coding\n");
		printf("6.hello world\n");
	printf("6.out of if\n");
	
	// seventh question
	int c=(1,0,-1);
	int b=c++;
	printf("7.b=%d\tc=%d\n",b,c);
	
	// eightth question
	int p=1,q=2,r;
//	    1   2   1*    2       3     4 	*used value will be 1 but it will be incremented and new value will be used later
	r = p + q + p++ + q++ + ++p + ++q;
	printf("8.value of r is:%d\n",r);
	
	int x=1,y=2,z=3,s;
	s=x-- - y-- - z--;
	printf("8.x:%d, y:%d, z:%d, s:%d\n",x,y,z,s);
	
	// nineth question
	printf("9.%d, %d, %d\n",!(0),!(1),!(5));  //not of 1 is 0 and vice versa but not of any number other then 1,0 is treated as true value
	
	// tenth question
	char *name[]={"abc", "def", "ghi", "ijk"};
	printf("10.%c\n",*name[2]+2);
	
	// eleventh question
	printf("11. ");
	for(i=0;i<5;i++)
	{
		printf("%d ",i&&1);
		i++;
	}
	printf("\n");
	
	//twelfth question
	if(printf("12. hello world\n")) {
		
	}
	
	return 0;
}
