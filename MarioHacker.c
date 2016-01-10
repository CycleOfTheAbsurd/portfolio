#include "cs50.h"
#include <stdio.h>

int main(void)
{
printf("Give me a number between 1 and 23: ");
int h = GetInt();

for(int height = 0; height <= h; height++)
	{for(int spaces=0; spaces<h-height; spaces++)
		{printf(" ");}

	for(int blocks=0; blocks<height+1;blocks++)
		{printf("#");}
		
	printf("  ");
	for(int blocks=0; blocks<height+1;blocks++)
		{printf("#");}
	printf("\n");	
	}

return 0;
}
