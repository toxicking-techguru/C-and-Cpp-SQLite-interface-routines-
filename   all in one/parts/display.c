// th codes blow will  Display data within th databas
#include <stdio.h>

#include <stdlib.h>

#include <sqlite3.h>

 

//Define Call()

static int Call(void *data, int argc, char **argv, char **azColName)

{

 



     int i;

 

   

     fprintf(stderr, "%s: ", (const char*)data);

 

     //Loop until argc value

     for (i = 0; i<argc; i++)

     {

 

      

printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

 

     }

 

     //Display newline

     printf("\n");

 

     //Return 0

     return 0;

 

}

 



int main(int argc, char* argv[])

 

{

     

     sqlite3 *db;

 

     //Declare variables

     char *MsgErr = 0;

 

     int cr;

 

     char *sql;

 

     const char* data = "Call function is called";

 

     // Open database

 

     cr = sqlite3_open("test.db", &db);

 

     
     if (cr)

     {

 

          //Display message

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     

     else

     {

 

          //Display message

          fprintf(stderr, "Successfull!!!\n");

 

     }

 

     // Display data

 

     sql = SELECT Dogs.age, COUNT(*), AVG(X.fee),AVG(V.eLevel) FROM Dogs AS D,Exmaine AS X, Veterinarians AS VWHERE D.did = X.did AND X.vid = V.vid GROUP BY D.age;

 

     // Execute SQL statement

     cr = sqlite3_exec(db, sql, Call, (void*)data, &MsgErr);

 

     
     if (cr != SQLITE_OK)

     {

 

          //Display message

          fprintf(stderr, "SQL error: %s\n", MsgErr);

 

   

          sqlite3_free(MsgErr);

 

     }

 

    

     else

     {

 

          //Display message

          fprintf(stdout, "Successfull\n");

 

     }

 

     //Close th database

     sqlite3_close(db);

 

     

     return 0;}

 