//
//  Passanger.h
//  12306
//
//  Created by Season Liew on 12/09/2018.
//  Copyright © 2018 Season Liew. All rights reserved.
//

#ifndef Passanger_h
#define Passanger_h
#include <stdlib.h>
//prototype zone
int book_man(station * STA_list);
int book_ran(station * STA_list);
int Name2Index(char key[],station * STA_list);
int STA_OP(int a,int b, station * STA_list);
int SEAT_ALL_SQ(int a,int b,char iden ,station * STA_list);
int SEAT_ALL_RAN(int a,int b,char iden ,station * STA_list);
int SEAT_SELECT(int a, int b,int pos, char iden, station * STA_list);
int ALP2NUM(char a);
int rowtonum(char a, int b);
int get_min_ava(int a, int b,int* min_index ,station * STA_list);
//prototype zone
//implementation zone
int book_man(station * STA_list){
    char A [4]; char B [4]; int a = 0; int b = 0;
    int sta=0;  //0 表示还未完成订票
    while(sta==0){
        //print logo
        printf("Please specify the Station A to B\n");
        scanf("%d to %d",&a,&b);
       /* a=Name2Index(A,STA_list);
        b=Name2Index(B,STA_list);*/
        if(a!=b&&a!=-1&&b!=-1)
            sta=1;
         //A&B->INDEX
        else
        printf("WRONG FORMAT!\n");
    }
    printf("%d TICKETS LEFT!\n",get_min_ava(a, b,NULL, STA_list));
    if(STA_list[a].End<=0){
        printf("No ticket left!\n");
        return 0;
    }
    char temp; int man;
    printf("ENTER 'Y' TO BOOK THE TICKET,'N' FOR ABORT\n");
    scanf("%s",&temp);
    if(temp=='Y'){
        printf("*****INSERT YOUR OPTION CODE AND PRESS RETURN!******\n");
        printf("1.AUTOMATIC SEAT ALLOCATION\n");
        printf("2.SELECT YOUR OWN SEAT\n");
        scanf("%d",&man);
        if(man==1){
        STA_OP(a,b,STA_list);//车站信息更新
        SEAT_ALL_SQ(a,b,'S',STA_list);//座位信息
    printf("%d TICKETS LEFT!\n",get_min_ava(a, b,NULL, STA_list));
            printf("SUCCESS!\n");
        }
        else if(man==2){
            while(1){
                int min_index;
                get_min_ava(a, b,&min_index, STA_list);
            Print_Seats(STA_list[min_index].seat);
                int row1; char col1; char ident;
            printf("WHICH SEAT WOULD YOU LIKE TO SELECT? FROMAT:ROW COL ID\n");
                
                scanf("%d %c",&row1,&col1);
                if(col1<'A'||col1>'T'||row1<0||row1>3){
                    printf("PLEASE SELECT THE SEAT WITHIN THE SEQUENTIAL RANGE");
                    continue;
                }
                   
            printf("INSERT YOUR IDENTIFIER\n");
                fflush(stdin);
                scanf(" %c",&ident);
                int sta;
            sta=SEAT_SELECT(a, b,rowtonum(col1, row1),ident,STA_list);
                if(sta==-1){
                    printf("OCCUPIED!\n");
                    continue;
                }
                else{
                    STA_OP(a,b,STA_list);
                    printf("%d TICKETS LEFT!\n",get_min_ava(a, b,NULL, STA_list));
                    printf("SUCCESS!\n");
                    break;
                }
            }
        }
        
    }
    return 0;
}

int Name2Index(char key[],station * STA_list){
    int index=1; int i;
    for( i=0;i<=MAXSTA&&index!=0;i++){
        index=strcmp(STA_list[i].Name,key);
    }
    if(index>=MAXSTA)
        return -1;
    //没找到，错误
    else //找到
        return i;
};
int STA_OP(int a,int b, station * STA_list){
    STA_list[a].End--;
    for(int i=a+1;i<b;i++){
        STA_list[i].Begin--;
        STA_list[i].End--;
    }
    STA_list[b].Begin--;
    return 0;
}
int SEAT_ALL_SQ(int a,int b,char iden ,station * STA_list){ //once at one station
    int i;
    for(i=0;i<SEAT&&STA_list[a].seat[i]!='O';i++);
    if(i==SEAT) return -1;
    STA_list[a].seat[i]=iden;
    for(int j=a+1;j<=b-1;j++)
        STA_list[j].seat[i]=iden;
    STA_list[b].seat[i]='O';//下车
    return 0;
}
int SEAT_ALL_RAN(int a,int b,char iden ,station * STA_list){ //once at one station
    int i;
    for(i=0;i<SEAT&&STA_list[a].seat[i]!='O';i=rand()%79)
    if(i==SEAT) return -1;
    STA_list[a].seat[i]=iden;
    for(int j=a+1;j<=b-1;j++)
        STA_list[j].seat[i]=iden;
    STA_list[b].seat[i]='O';//下车
    return 0;
}
int SEAT_SELECT(int a, int b,int pos, char iden, station * STA_list){
    if(STA_list[a].seat[pos]!='O') return -1;
    STA_list[a].seat[pos]=iden;
    for(int j=a+1;j<=b-1;j++)
        STA_list[j].seat[pos]=iden;
    STA_list[b].seat[pos]='O';//下车
    return 0;
}
int rowtonum(char a, int b){
    return ALP2NUM(a)+b*20;
}
int ALP2NUM(char a){
    return a-'A';
}
int get_min_ava(int a, int b,int* min_index, station * STA_list){
    int min[2];
     min[1]=STA_list[a].End;  min[0]=a;
    for(int i=a+1;i<=b-1;i++){
        if(STA_list[i].Begin<min[1]){
            min[0]=i;
            min[1]=STA_list[i].Begin;
        }
        if(STA_list[i].End<min[1]){
        min[0]=i;
        min[1]=STA_list[i].End;
        }
    }
    if(STA_list[b].Begin<min[1]){
        min[0]=b;
        min[1]=STA_list[b].Begin;
    }
    if(min_index){
        *min_index=min[0];
    }
    return min[1];
}
int book_ran(station * STA_list){
    int a; int b; char arr[10]={"!@#$%^&*()"};
    
    
    a=rand()%8;
    b=rand()%(9-a+1)+a;
    int c=rand()%10;
    printf("%d, %d",a,b);
    if(a==b) return 0;//丢弃
    STA_OP(a,b,STA_list);//车站信息更新
    SEAT_ALL_RAN(a,b,arr[c],STA_list);//座位信息
    return 0;
}
//implementation zone
#endif /* Passanger_h */
