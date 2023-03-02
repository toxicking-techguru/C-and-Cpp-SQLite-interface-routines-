// Dbconnectivity.cpp code to connct

#include<iostream>

#include <stdio.h>

#include <sqlite3.h>

 



int main(int argc, char* argv[])

{



     sqlite3 *db;

 

     //Declare variables

     char *MsgErr = 0;

     int cr;

 


     cr = sqlite3_open("database.db", &db);

 

     

     if (cr)

     {

 

        

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     //If it is present

     else

     {

 

          

          fprintf(stderr, "Database successfully Connected\n");

 

     }

 

     //Close

     sqlite3_close(db);

 

}

 
