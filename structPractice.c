#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10
#define SEAT 12

struct seat {
    int number;
    bool isOrder;
    char secondName[SIZE];
    char firstName[SIZE];
};

void printMenu(void);
void clearBuffer(void);
int showEmptyNumber(struct seat []);
void showEmptySeats(struct seat []);
void showAlphabeticalList(struct seat []);
char * s_gets(char [], int);


int main(void) {
    int i, seatNumber;
    char selection;
    struct seat airLineSeat[SEAT];
    char firstTemp[SIZE],  secondTemp[SIZE];
    
    for (i = 0; i < SEAT; i++) {
        airLineSeat[i].number = i + 1;
        airLineSeat[i].isOrder = false;
        airLineSeat[i].firstName[0] = '\0';
        airLineSeat[i].secondName[0] = '\0';
    }
    
    while (true) {
        printMenu();
        
        if (strchr("abcde", selection = getchar()) != NULL && selection != '\0') {
            clearBuffer();
            switch (selection) {
                case 'a':
                    printf("The number of empty seats is: %d\n", showEmptyNumber(airLineSeat));
                    break;
                case 'b':
                    puts("The list of empty seats are:");
                    showEmptySeats(airLineSeat);
                    break;
                case 'c':
                    puts("The alphabetical list of seats are:");
                    showAlphabeticalList(airLineSeat);
                    break;
                case 'd':
                    printf("Please enter the number:");
                    while (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > SEAT || airLineSeat[seatNumber - 1].isOrder != false) {
                        clearBuffer();
                        printf("Please enter the corret number:");
                    }
                    clearBuffer();
                    printf("Please enter firstname:");
                    s_gets(airLineSeat[seatNumber - 1].firstName, SIZE);
                    printf("Please enter secondname:");
                    s_gets(airLineSeat[seatNumber -1].secondName, SIZE);
                    airLineSeat[seatNumber - 1].isOrder = true;
                    break;
                case 'e':
                    printf("Please enter the ordered number:");
                    while (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > SEAT || airLineSeat[seatNumber - 1].isOrder != true) {
                        clearBuffer();
                        printf("Please enter the correct number:");
                    }
                    airLineSeat[seatNumber - 1].firstName[0] = '\0';
                    airLineSeat[seatNumber - 1].secondName[0] = '\0';
                    airLineSeat[seatNumber - 1].isOrder = false;
                    break;
            }
            continue;
        } else if ('f' == selection) {
            break;
        } else {
            puts("Please choose the right choice.");
            continue;
        }
    }
      
    
    puts("Bye!");
    
    
    
    return  0;
}

void printMenu(void) {
    
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    
    
}

void clearBuffer(void) {
    while (getchar() != '\n')
        continue;
}

int showEmptyNumber(struct seat airSeat[SEAT]) {
    int i, count = 0;
    
    for (i = 0; i < SEAT; i++)
        if (airSeat[i].isOrder == false)
            count++;
    
    return count;
}

void showEmptySeats(struct seat airSeat[SEAT]) {
    int i;
    for (i = 0; i < SEAT; i++)
        if (airSeat[i].isOrder == false)
            printf("%d\n", airSeat[i].number);
}

void showAlphabeticalList(struct seat airSeat[SEAT]) {
    int i, j;
    struct seat swapTemp, temp[SEAT];
    
    for (i = 0; i < SEAT; i++)
        temp[i] = airSeat[i];

    for (i = 0; i < SEAT; i++) {
        for (j = i + 1; j < SEAT; j++) {
            if (strcmp(temp[j].firstName, temp[i].firstName) < 0) {
                swapTemp = temp[j];
                temp[j] = temp[i];
                temp[i] = swapTemp;
            } else if (!strcmp(temp[j].firstName, temp[i].firstName) && strcmp(temp[j].secondName, temp[i].secondName) < 0) {
                swapTemp = temp[j];
                temp[j] = temp[i];
                temp[i] = swapTemp;
            }
        }
    }
    
    for (i = 0; i < SEAT; i++)
        printf("%d, %s %s\n", temp[i].number, temp[i].firstName, temp[i].secondName);
    
    
}

char * s_gets(char * sp, int n) {
    
    char * rev, * find;
    
    rev = fgets(sp, n, stdin);
    
    if (rev) {
        find = strchr(sp, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
        
            
    }
    return rev;
}


