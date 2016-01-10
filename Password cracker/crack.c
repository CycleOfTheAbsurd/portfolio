#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//!! see bug at line 63 !!

char salt[2];
char* argv[2];

//buffer for generated passwords
char buf[512];

//all characters we want to use (80 of them)
char chars[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789"
".,:;!/$%?&*()_-=@+";

int recurse();
int checker();

int main(int argc, char* argv[])
{	
	//returns an error and exit if no or more than 1 hash was entered
	if(argc != 2)
	{
		printf("You must enter one password\n");
		return 1;
	}
	
	//Extracts the salt from the entered hashed password
	strncpy(salt, argv[1], 3);
	salt[2] = '\0';
	

	//opens the dictionnary file and gets it line by line
	FILE *dictionnary = fopen ("~/Dic/CustomDic.txt", "rt");
	if (dictionnary != NULL)
	{
		
		printf("Using Dictionnary\n");
		fflush(stdout);
		//gets each line and send them to the checker
	  	while (fgets (buf, sizeof(buf), dictionnary)) 
	  	{	
			if(checker(argv[1], buf) == 0)
				return 0;
		}
		fclose(dictionnary);
		printf("Not found in dictionnary, using bruteforce\n");
	}
	
	
	for(int i = 0; i < 8; i++)
	{
		if(recurse(i, 0, argv[1]) == 0);
		{
			return 0;
		}
	}
	printf("password not found\n");
	return 1;
}

//takes the value of the password, hashes it and compares it to the entered hash. Prints the unhashed password if they're the same
int checker(char hash[], char* tocheck)
{	
	
	//replaces newline character with null terminator
	tocheck[strcspn( tocheck, "\n" )] = "\0";
	
	char* passwd = crypt(tocheck, salt);
	
	//sanity check
	if (hash != NULL && passwd != NULL)
	{
		
		if (strcmp(hash, passwd) == 0)
		{		
			printf("The password is %s\n", tocheck);
			return 0;		
		}
	}	

	else
		return 1;
}

/*Brute force attack
**Tries all passwords of lengths 0 to 8 with all of the characters from chars in every position
*/
int recurse(int width, int position, char* hashh) 
{
	buf[width+1] = '\n';
	for(int k = 0; k < 80; k++) 
	{
		if (position < width) 
		{
 
			recurse(width, position + 1, hashh);
 
      		}
      		buf[position] = chars[k];
      		
		if(checker(hashh, buf) != 1)
		{
			return 0;
  		
      	   	}
      	}
      	return -1;

	
}








