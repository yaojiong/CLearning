#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMBER 10
#define SIZE 80


char * s_fgets(char *, int);
void basicPrint(char * [], int);
void ascPrint(char * [], int);
void lengthPrint(char * [], int);
void wordPrint(char * [], int);
int firstWordLen(char *);

int main(void) {
    char  array[NUMBER][SIZE];
    char * ptr[NUMBER];
    int i, select;
    
    for (i = 0; i < NUMBER; i++) {
        printf("请输入第%d组字符:", i + 1);
        ptr[i] = s_fgets(array[i], SIZE);
    }
    
    puts("请输入对应选项:");
    puts("1.打印源字符串列表:");
    puts("2.以ASCII中的顺序打印字符串:");
    puts("3.按长度递增顺序打印字符串:");
    puts("4.按字符串中第1个单词的长度打印字符串:");
    puts("5.退出:");
    
    while (scanf("%d", &select) == 1 && select != 5) {
        switch (select) {
            case 1:
                basicPrint(ptr, NUMBER);
                break;
            case 2:
                ascPrint(ptr, NUMBER);
                basicPrint(ptr, NUMBER);
                break;
            case 3:
                lengthPrint(ptr, NUMBER);
                basicPrint(ptr, NUMBER);
                break;
            case 4:
                wordPrint(ptr, NUMBER);
                basicPrint(ptr, NUMBER);

                break;
            default:
                puts("请输入正确的选项.");
                break;
        }
        while (getchar() != '\n') {
            continue;
        }
    }
    
    puts("Bye!");
    
    
    
    return 0;
}


char * s_fgets(char * str,int n) {
    char * rev;
    int i = 0;
    
    rev = fgets(str, n, stdin);
    
    if (rev) {
        while (str[i] != '\n' && str[i] != '\0' ) {
            i++;
        }
        if (str[i] == '\n') {
            str[i] = '\0';
        }
        else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    
    
    return rev;
}

void basicPrint(char * point[], int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        puts(point[i]);
    }
}


void ascPrint(char * point[], int n) {
    
    int i, j;
    char * temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(point[i], point[j]) > 0) {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
            }
        }
    }
}

void lengthPrint(char * point[], int n) {
    
    int i, j;
    char * temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strlen(point[i]) > strlen(point[j])) {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
            }
        }
    }
}

void wordPrint(char * point[], int n) {
    
    int i, j;
    char * temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (firstWordLen(point[i]) > firstWordLen(point[j])) {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
            }
        }
    }
}

int firstWordLen(char * ptr) {
    
    int i = 0,count = 0;
    
    while (!isspace(ptr[i]) && ptr[i] != '\0') {
        count++;
        i++;
    }
    return count;
}