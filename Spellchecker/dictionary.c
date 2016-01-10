/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

//apostrophe ' and 26 letters of the alphabet: 'abcdefghijklmnopqrstuvwxyz
#define NUM_NODE 27

//define a root node that is the trie's start
	    
    node* root;
    //*root = {false, {NULL}};    
//number of words in dictionary
int numwords = 0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
	node* current = root;
	int value;
    for(int i = 0; word[i] != '\0'; i++)
    {
    	if(word[i] == '\'')
    		value = 0;
    	else
    	{
    		//ASCII value of a
			value = tolower(word[i]) - 96;	
		} 
    	if(current -> children[value] != NULL)
    		current = current -> children[value];
    		
    	else
    		return false;
    }
	return(current -> isWord);
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = malloc(sizeof(node));
    
    FILE* file = fopen(dictionary, "r");
    
    if(file == NULL)
    	return false;
    
    //pointer to the current node for traversing. Starts at the root
    node* current = root;

    for(char c = fgetc(file); c != EOF; c = fgetc(file))
    {
    	    	
    	if(c != '\n')
    	{
    		int cc;
    		
    		if(c == '\'')
    			cc = 0;
    		else
    		{
    			//ASCII value of a
				cc = c- 96;	
			}
			if(current -> children[cc] == NULL)
			{
				current -> children[cc] = malloc(sizeof(node));    		
				//*current -> children[c] = {false, {NULL}};
			}
			current = current -> children[cc];    
    	}
    	//when end of line is reached mark current position as a word's end and go back to the root for next word
    	else
    	{
    		current -> isWord = true;
    		numwords++;
    		current = root;
    	}
    }
    //in case last word in dictionary is not terminated by \n
    if(current != root && current -> isWord != true)
    {
    	current -> isWord = true;
    	numwords++;
    }
          
    fclose(file);  
    return true;
    	
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return numwords;
}

 void freenode(node* current)
{
	for(int i = 0; i < NUM_NODE; i++)
    {
    	if(current -> children[i] != NULL)
    	{
    		freenode(current -> children[i]); 	
    	}	
  	}
  	free(current);

}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
	node* current = root;
	freenode(current);
	    
    return true;
}


