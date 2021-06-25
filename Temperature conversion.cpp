#include<stdio.h>

double C2F(double c)
{
	double f=(c*9/5)+32;
	return f;
}

double F2C(double f)
{
	double c=(f-32)*5/9;
	return c;
}

int main()
{
	double temp;
	int choice;
	
	printf("1. celcius->fahrenhite\n2. fahrenhite->celcius\nenter your choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("enter temperature in celcius:");
			scanf("%lf",&temp);
			printf("temperature in fahrehite is:%.2lf",C2F(temp));
			break;
			
		case 2:
			printf("enter temperature in fahrenhite:");
			scanf("%lf",&temp);
			printf("temperature in celcius is:%.2lf",F2C(temp));
			break;
			
		default:
			printf("please enter valid choice");
	}
	
	return 0;
}
