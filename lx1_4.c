#include<stdio.h>
main()
{
	float celsius,fahr;
	int lower,upper,step;
	lower = 0;
	upper = 300;
	step = 20;
	celsius = lower;
	while(celsius <= upper)
	{
		//c = (5/9)*(fahr-32)
		fahr = celsius*(9.0/5.0) + 32;
		printf("%3.0f %6.1f\n",celsius,fahr);
		celsius = celsius + step;
	}
}
