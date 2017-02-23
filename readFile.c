#include <stdio.h>
#include <stdlib.h>



int main(void) {
    
    FILE * p1, * p2;
    char c1, c2;
    int status = 0;
    int endOne = 0, endTwo = 0;
    
    p1 = fopen("/Users/jiadoggy/Downloads/learn/C/CLearning/theC/file1.strings", "r");
    p2 = fopen("/Users/jiadoggy/Downloads/learn/C/CLearning/theC/file2.strings", "r");
    
    if (p1 == NULL || p2 == NULL) {
        puts("打开文件失败！");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        while ((c1 = getc(p1)) != EOF) {
            if (c1 != '\n' && status == 0)
                putchar(c1);
            else if (p2 != NULL) {
                status = 1;
                putchar('\n');
                break;
            }
            else if (p2 == NULL)
                continue;
        }
        
        if (c1 == EOF) {
            status = 1;
            endOne = 1;
            fclose(p1);
        }
        
        while ((c2 = getc(p2)) != EOF) {
            if (c2 != '\n' && status == 1)
                putchar(c2);
            else  if (p1 != NULL) {
                status = 0;
                putchar('\n');
                break;
            }
            else if (p1 == NULL)
                continue;

        }
        
        if (c2 == EOF) {
            status = 0;
            endTwo = 1;
            fclose(p2);
        }
        
        if (endOne && endTwo) {
            break;
        }

    }
    
    
    return 0;
}