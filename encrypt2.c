#include<stdio.h>
#include<stdlib.h>

int main()
{
    char c;
    char ceaser1[25];
 //To open a file you need to use the fopen function, which   returns a FILE pointer.
   FILE *fp;
    int character[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int key;
    char calc[9999];
    int index = 0;
    

    printf("Enter name of the file you want to read \n");
    //reads the file name
    gets(ceaser1);
    //FILE *fopen(const char *filename, const char *mode)- "r" Opens a file for reading. The file must exist.
    fp = fopen(ceaser1, "r");

    if(fp == NULL) {
        perror("Error in opening  file");
        return(-1);
    }

    printf("Reading File: ",ceaser1);

 //fgetc - gets the next character (an unsigned char) from the specified stream and advances the position indicator for the stream.
//EOF = if something doesnt go wrong
    while((c = fgetc(fp))!= EOF){
        calc[index] = c;
        index++;
    }
    fclose(fp);

   
    int length = sizeof(calc);
    int i;
    for (i = 0; i < length; i++) {
//converts char to ASCII for the characters a to Z
        int a = calc[i] - 97; 
        character[a] += 1;
    }

    int j, maxIndex1, maxIndex2, Max1 = 0, Max2 = 0, characterLength = sizeof(character);

    for (j = 0; j < characterLength;j++) {
// check the characters for greater than the maxes 
        if(character[j] > Max1) {
            Max1 = character[j];
            maxIndex1 = j;
        }
        else if(character[j] < Max1 && character[j] > Max2) {
            Max2 = character[j];
            maxIndex2 = j;
        }
    }
	//key = the maxIndex and -4 the letter 'e' which is 4 spaces away from a 
    key = maxIndex1 - 4;
    key = maxIndex2 - 19;
	//if the key is less than 'e' so a,b,c,d 
    if (key < 0) {
        key += 26;
    }
    printf("The key is: %d\n", key);
    return 0;
}
