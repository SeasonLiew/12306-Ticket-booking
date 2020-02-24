# 12306-Ticket-booking
This is a program simulating the train ticket booking procedure for reserved seats of a coach with 20*5 seats. As a human, you can specify your starting station, destination station and the seat position you want to order. The system will display the amount of available seats for your intended interval before you book the ticket. On confirming to book the ticket, you can either manually choose the seat from the seat graph shown on the prompt, or the system will randomly allocate the seat for you. You can also simulate the ticket booking activity done by the random population to test the usability of the program. You can also view the passenger represented by different ascii character of each station of the 10 stations(0 means empty), with the number of the station specified.



interface：
```
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      ////////     ////////     //      // 2018(C)
     //           //    //     //      // 
    //           ////////     //////////  
   //           ////         //      //   
  //           // ///       //      //    
 ////////     //    ///    //      //    RAILWAY BOOKING SYSTEM 
                                         SEASON LIEW 

*****INSERT YOUR OPTION CODE AND PRESS RETURN!******
1.BOOKING TICKET
2.VIEWING A SINGLE STATION
3.VIEWING ALL STATIONS
0.EXIT

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
view the station e.g. view the 2n station after a population simulation

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*****INSERT YOUR OPTION CODE AND PRESS RETURN!******
1.BOOKING TICKET
2.VIEWING A SINGLE STATION
3.VIEWING ALL STATIONS
0.EXIT
2
WHICH STATION YOU WANT TO VIEW?
2
--------------------------------------------
|# A B C D E F G H I J K L M N O P Q R S T | 
|0 ) O ) O # O O O O # & O $ ^ O ( O * O O | 
|1 O @ O & O O O @ O O O O O O % O ) O $ O | 
|2 O * & O O $ O & O O ^ O O @ O O O O ) O | 
|3 O # O O O & O O & ^ % O O ( O % O O O O | 
--------------------------------------------
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
manually choose seat
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*****INSERT YOUR OPTION CODE AND PRESS RETURN!******
1.I'M HUMAN!
2.POPULATION SIM
3.RETURN TO THE MAIN MENU
1
Please specify the Station A to B
3 to 8
54 TICKETS LEFT!
ENTER 'Y' TO BOOK THE TICKET,'N' FOR ABORT
Y
*****INSERT YOUR OPTION CODE AND PRESS RETURN!******
1.AUTOMATIC SEAT ALLOCATION
2.SELECT YOUR OWN SEAT
2
--------------------------------------------
|# A B C D E F G H I J K L M N O P Q R S T | 
|0 & O O O O O O ^ O O O ) O O O O ( O & O | 
|1 O % O O ^ O O O O O O * # $ O O @ O ( O | 
|2 & O ) ) ^ O O O & O O O O O O ! O O ! & | 
|3 O O O O O O O O * O @ O * O O O O O $ O | 
--------------------------------------------
WHICH SEAT WOULD YOU LIKE TO SELECT? FROMAT:ROW COL ID
0 G (
INSERT YOUR IDENTIFIER
53 TICKETS LEFT!
SUCCESS!
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
```
