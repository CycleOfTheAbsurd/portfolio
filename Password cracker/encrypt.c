/*Encrypts a string with DES and returns it
* Takes the string to encrypt and a 2 character salt as arguments
*/
#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>



int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		puts("Usage: encrypt string salt\n");
		return 1;
	}	
	
	//checks if salt is composed of 2 alphanumeric characters
	if(!isalnum(argv[2]) || strlen(argv[2]))
	{
		puts("Salt must be a 2 character alphanumeric string\n");
		return 1;
	}
	
	char *salt; 
	salt = argv[2];
	char* passwd = crypt(argv[1], salt);
	puts(passwd);
	puts(argv[1]);



}
