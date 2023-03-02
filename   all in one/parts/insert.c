

//this code will Insert data into tables
#include <stdio.h>

#include <stdlib.h>

#include <sqlite3.h>

 



static int CALL(void *NotUsed, int argc, char **argv, char **azColName)

{

 

     

     int i;

 

     

     for (i = 0; i<argc; i++)

     {

 

          //Display message

printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

 

     }

 

    

     printf("\n");

 

    

     return 0;

 

}

 

 



int main(int argc, char* argv[])

{

     //Defining th database

     sqlite3 *db;

 

     

     char *MsgErr = 0;

     int cr;

     char *sql;

 

     // Open database

     cr = sqlite3_open("test.db", &db);

 

     

     if (cr)

     {

 

        

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

         

          return(0);

 

     }

 

     //this willm check If database is present

     else

     {

 

       
          fprintf(stderr, "Successfull!!1\n");

 

     }

 

     // Defne Insert statements

sql = "INSERT INTO Veterinarians (vid,elevel)VALUES (1001,1); " \

 

     "INSERT INTO Examine (vid,did,FEE)VALUES (1001,1234,25 ); " \

 

     "INSERT INTO Dogs (did,age)VALUES (1234,10);"

 

 

 

     // Execute SQL statement

     cr = sqlite3_exec(db, sql, callback, 0, &MsgErr);

 

 


     if (cr != SQLITE_OK)

     {

 

          //Display message

          fprintf(stderr, "SQL error: %s\n", MsgErr);

 

      

          sqlite3_free(MsgErr);

 

     }

 

  

     else

     {

 

        

          fprintf(stdout, "Successfull\n");

 

     }

 

    

     sqlite3_close(db);

 

     //return 0

     return 0;

 

}

 





 
