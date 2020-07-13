#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char c;
    char message[25];
   //To open a file you need to use the fopen function, which   returns a FILE pointer.
    FILE *fp;
    int key;
    //char letter[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char calc[9999];
    int index = 0;

    printf("Enter name of the file you want to read: \n");
    //read the file name
    gets(message);
    //the key is 9
    printf("Enter the key: \n");
    scanf("%d", &key);
   
    //FILE *fopen(const char *filename, const char *mode)- "r" Opens a file for reading. The file must exist.
    fp = fopen(message, "r");
    if(fp == NULL) {
    perror("Error in opening file");
    return(-1);
    }
    printf("Reading File: ",message);
    
    //fgetc - gets the next character (an unsigned char) from the specified stream and advances the position indicator for the stream.
    //EOF = if something doesnt go wrong
     while((c=fgetc(fp)) != EOF) {
        calc[index] = c;
        index++;
    }
    fclose(fp);
 
   int length = strlen(calc);
   int i,j;

   for (i = 0; i < length; i++) {
    //if word is within the range of a-z and A-Z
   if((calc[i] >= 'a' && calc[i] <= 'z') || (calc[i] >= 'A' && calc[i] <= 'Z')) {
     // if the index exceed the range of a-z and A-Z
   if ((calc[i]>= 'z' -key && calc[i] <= 'z') || (calc[i] >= 'Z' - key && calc[i] <= 'Z')) {
                //then swap the index
    	calc[i] = calc[i] - 26 + key;
            }
            else {
                //else if its within the range just calc
                calc[i] = calc[i] + key;
            }
       }
   }

   for (j = 0; j < length; j++) {
       calc[j] = tolower(calc[j]);
   }
   printf("%s", calc);
   printf("\n");
   return 0;
}

