#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

/*
* IMplements a vigener cipher
*/

int main(int argc, string argv[])
{	
	int keylen = strlen(argv[1]);
	
	//check if only one keyword has been entered
	if(argc != 2)
	{
		printf("You must enter only one keyword\n");
		return 1;
	}
	
	//check if keywords contains only letters
	for (int i = 0; i < keylen; i++)
	{
		if(! isalpha(argv[1][i]))
		{
			printf("You must enter a keyword that contains letters only\n");
			return 1;
		}
	
	}
		

	{	
		printf("Enter the message you wish to encrypt: \n");
		string message = GetString();
		int len = strlen(message);
		int k[len];
		//Transform entered key into an array of the correct length with numbers from 0 to 25
		for (int i = 0; i < len; i++)
			{
				if (isupper(argv[1][i%keylen]))
				{
					k[i] = 	argv[1][i%keylen] - 'A';
				}
				
				else if (islower(argv[1][i%keylen]))
				{
					k[i] = 	argv[1][i%keylen] - 'a';
				}
				
			}
		
		//create a char array to store encypted message
		char crypt[len+1];
		
			for (int i = 0, j = 0; i < len; i++)
			{
				if (isupper(message[i]))
				{
					crypt[i] = (message[i] + k[j]) % ('Z'+1);
					j++;
					if(crypt[i] < 'A')
						crypt[i] += 'A';						
				}
				
				else if (islower(message[i]))
				{
					crypt[i] = (message[i] + k[j]) % ('z'+1);
					j++;
					if(crypt[i] < 'a')
						crypt[i] += 'a';
				}
				
				else
				{
					crypt[i] = message[i];

				}
			}
		crypt[len+1] = '\0';		
		puts(crypt);
		return 0;
	}
	
}
		

