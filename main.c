//
//  main.c
//  12306
//
//  Created by Season Liew on 12/09/2018.
//  Copyright © 2018 Season Liew. All rights reserved.
//

#include <stdio.h>
#include <string.h>
 #include <time.h>
#define MAXSTA 10
#define ROW 20
#define COL 4
#define SEAT  ROW*COL
//printing funs
typedef struct station{
    char Name[4];
    int Begin;
    int End;
    char seat[SEAT];
} station ;

typedef struct train{
    char start[4];
    char dest[4];
    int Max;
}train;
int initialize(station * STA_list);
int booking_main(station * STA_list);
int driving(station  STA_list[]);
void Print_Seats(char arr[]);
void Print_Logo(void);
#include "Passanger.h"
int main(int argc, const char * argv[]) {
   //initialize
    int status=1;
    station STA_list[MAXSTA];
    initialize(STA_list);
    while(status){
        system("cls");
        Print_Logo();
        printf("*****INSERT YOUR OPTION CODE AND PRESS RETURN!******\n");
        printf("1.BOOKING TICKET\n");
        printf("2.VIEWING A SINGLE STATION\n");
        printf("3.VIEWING ALL STATIONS\n");
        printf("0.EXIT\n");// 3 options
        scanf("%d",&status);
        switch(status){
            case 1:
                booking_main(STA_list);
                break;
            case 2:
                driving(STA_list);
                break;
            case 3:
                for(int i=0;i<MAXSTA;i++){
                    printf("STATION #%d\n",i);
                    Print_Seats(STA_list[i].seat);}
                    break;
                
            case 0:
               return 0;
        }
        
    }
    return 0;
}

int initialize(station * STA_list){
    /*strcpy(STA_list[0]->Name, "PEK");
    strcpy(STA_list[1]->Name, "TJN");
    strcpy(STA_list[2]->Name, "JIN");
    strcpy(STA_list[3]->Name, "TAN");
    strcpy(STA_list[4]->Name, "QUZ");
    strcpy(STA_list[5]->Name, "NNK");
    strcpy(STA_list[6]->Name, "WUX");
    strcpy(STA_list[7]->Name, "SUZ");
    strcpy(STA_list[8]->Name, "KUN");
    strcpy(STA_list[9]->Name, "SHA");*/
    for(int i=0; i<MAXSTA;i++){
        STA_list[i].Begin= SEAT ;
        STA_list[i].End= SEAT;
        for(int j=0;j<SEAT;j++){
            STA_list[i].seat[j]='O';
        }
    }
    return 0;
}
int driving(station STA_list[]){
    int i;
    while(1){
        printf("WHICH STATION YOU WANT TO VIEW?\n");
        scanf("%d",&i);
        Print_Seats(STA_list[i].seat);
        return 0;
    }
    
    return 0;
}
int booking_main(station * STA_list){
    int i=0;
    while(1){
        system("CLS");
        Print_Logo();
    printf("*****INSERT YOUR OPTION CODE AND PRESS RETURN!******\n");
    printf("1.I'M HUMAN!\n");
    printf("2.POPULATION SIM\n");
    printf("3.RETURN TO THE MAIN MENU\n");
    scanf("%d",&i);
    
    switch(i){
        case 1:
           book_man(STA_list);
            break;
        case 2:
            srand((unsigned)time(NULL));
            for(int i=0;i<=70;i++)
            book_ran(STA_list);
            printf("SUCCESS!\n");
            break;
        case 3:
            return 0;
    }
        
    }
    return 0;
}
void Print_Logo(void){
    printf("                                               \n");
    printf("      ////////     ////////     //      // 2018(C)\n");
    printf("     //           //    //     //      // \n");
    printf("    //           ////////     //////////  \n");
    printf("   //           ////         //      //   \n");
    printf("  //           // ///       //      //    \n");
    printf(" ////////     //    ///    //      //    RAILWAY BOOKING SYSTEM \n");
    printf("                                         SEASON LIEW \n");
    printf("\n");
}
void Print_Seats(char arr[]){
    for(int i=0;i<=21;i++)
        printf("--");
    printf("\n");
    printf("|# ");
    for(int i='A';i<='T';i++)
        printf("%c ",i);
    printf("| ");
       printf("\n"); 
    printf("|0 ");
    for(int i=0;i<=19;i++)
        printf("%c ",arr[i]);
    printf("| ");
   printf("\n");
    printf("|1 ");
    for(int i=20;i<=39;i++)
        printf("%c ",arr[i]);
    printf("| ");
     printf("\n");
    printf("|2 ");
    for(int i=40;i<=59;i++)
        printf("%c ",arr[i]);
    printf("| ");
    printf("\n");
    printf("|3 ");
    for(int i=60;i<=79;i++)
        printf("%c ",arr[i]);
    printf("| ");
    printf("\n");
    for(int i=0;i<=21;i++)
        printf("--");
    printf("\n");
}

