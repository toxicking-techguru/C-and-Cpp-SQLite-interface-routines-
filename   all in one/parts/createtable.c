//c code to  CreateTable.cpp

 



#include <stdio.h>

#include <stdlib.h>

#include <sqlite3.h>

 

static int Call(void *NotUsed, int argc, char **argv, char **azColName)

{

 

 

     int i;

 


     for (i = 0; i<argc; i++)

     {

 

          //Display message

printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

 

     }

 

   

     printf("\n");

 

     //Retiurn 0

     return 0;

 

}

 



int main(int argc, char* argv[])

{

 

     //Define db

     sqlite3 *db;

 

    

     char *MsgErr = 0;

     int cr;

     char *sql;

 

     // Open database

     cr = sqlite3_open("test.db", &db);

 

   
     if (cr)

     {

 


fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     //If database present

     else

     {

 


          fprintf(stdout, "Successfull!!\n");

 

     }

 

     // Create table Veterinarians

 

     sql = "CREATE TABLE Veterinarians (" \

 

     "vid INT PRIMARY KEY NOT NULL," \

 

     "elevel INT NOT NULL);";

 


 

     sql = "CREATE TABLE Examine(" \

 

     "vid INT PRIMARY KEY NOT NULL," \

 

     "did INT NOT NULL," \

 

     "FEE INT );";

 

 


     sql = "CREATE TABLE Dogs(" \

 

     "did INT PRIMARY KEY NOT NULL," \

 

     "age INT NOT NULL);";

 

    

 

     cr = sqlite3_exec(db, sql, Call, 0, &MsgErr);

 

    

     if (cr != SQLITE_OK)

     {

 

          //Display message

          fprintf(stderr, "SQL error: %s\n", MsgErr);

 

          //Call sqlite3_free()

          sqlite3_free(MsgErr);

 

     }

 

   

     else

     {

 

      

          fprintf(stdout, " successfull!!!\n");

 

     }

 

     //Call sqlite3_close

     sqlite3_close(db);

 

     //Return 0

     return 0;

 

}

 



 


 
