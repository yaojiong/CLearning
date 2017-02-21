

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(void) {
    int num, i;
    char *  * wordsPointer;
    char temp[SIZE];
    
    puts("How many words do you wish to enter ? ");
    scanf("%d", &num);
    
    wordsPointer = (char * *) malloc(num * sizeof(char *)); // 给指向指针的指针分配动态内存
    
    printf("Enter %d words now:\n", num);
    
    for (i = 0; i < num; i++) {
        if (scanf("%s", temp) == 1) {
            wordsPointer[i] = (char *)malloc(strlen(temp) + 1);
            wordsPointer[i] = strcpy(wordsPointer[i], temp);
        }
    }
    
    puts("Here are your wors:");
    
    for (i = 0; i < num; i++) {
        puts(wordsPointer[i]);
    }
    


    for (int i = 0; i < num; ++i)
    {
        free(wordsPointer[i]);
    }

    free(wordsPointer);
    
    return 0;
}
