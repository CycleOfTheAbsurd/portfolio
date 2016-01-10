//Implement a simple caesar cipher and returns the encoded string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(int argc, string argv[])
{
	if(argc != 2)
	{
		printf("You must enter only one non-negative whole number");
		return 1;
	}
	
	else
	{	
		//convert input to number and make it roll aroud if bigger than length of alphabet
		int k = atoi(argv[1]) % 26;
		
		printf("Enter the message you wish to encrypt: \n");
		string message = GetString();
		int len = strlen(message);
		
		//create a char array to store encypted message
		char crypt[len];
		
			for (int i = 0; i < len; i++)
			{
				if (isupper(message[i]))
				{
					crypt[i] = (message[i] + k) % ('Z'+1);
					
					if(crypt[i] < 'A')
						crypt[i] += 'A';						
				}
				
				else if (islower(message[i]))
				{
					crypt[i] = (message[i] + k) % ('z'+1);
					
					if(crypt[i] < 'a')
						crypt[i] += 'a';
				}
				
				else
					crypt[i] = message[i];
			}
		
		printf("%s \n", crypt);
		return 0;

	}


}
