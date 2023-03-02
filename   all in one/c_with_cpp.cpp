//Connect to the Database by the following code:

 

// Dbconnectivity.cpp:

 

 

//Include libraries

#include<iostream>

#include <stdio.h>

#include <sqlite3.h>

 

//Define main method

int main(int argc, char* argv[])

{

     //Define db

     sqlite3 *db;

 

     //Declare variables

     char *MsgErr = 0;

     int cr;

 

     //Open database

     cr = sqlite3_open("database.db", &db);

 

     //If database not present

     if (cr)

     {

 

          //Display message

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     //If it is present

     else

     {

 

          //display message

          fprintf(stderr, "Database successfully Connected\n");

 

     }

 

     //Close

     sqlite3_close(db);

 

}

 

// Create table

 

// CreateTable.cpp

 

//Include libraries

#include <stdio.h>

#include <stdlib.h>

#include <sqlite3.h>

 

//Define Call()

static int Call(void *NotUsed, int argc, char **argv, char **azColName)

{

 

     //Declare variable

     int i;

 

     //Loop until value

     for (i = 0; i<argc; i++)

     {

 

          //Display message

printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

 

     }

 

     //Display newline

     printf("\n");

 

     //Retiurn 0

     return 0;

 

}

 

//Define main method

int main(int argc, char* argv[])

{

 

     //Define db

     sqlite3 *db;

 

     //Declare variables

     char *MsgErr = 0;

     int cr;

     char *sql;

 

     // Open database

     cr = sqlite3_open("test.db", &db);

 

     //If database not present

     if (cr)

     {

 

          //Display message

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     //If database present

     else

     {

 

          //Display message

          fprintf(stdout, "Successfull!!\n");

 

     }

 

     // Create table Veterinarians

 

     sql = "CREATE TABLE Veterinarians (" \

 

     "vid INT PRIMARY KEY NOT NULL," \

 

     "elevel INT NOT NULL);";

 

     // Create table Examine

 

     sql = "CREATE TABLE Examine(" \

 

     "vid INT PRIMARY KEY NOT NULL," \

 

     "did INT NOT NULL," \

 

     "FEE INT );";

 

 

     //Create table Dogs

     sql = "CREATE TABLE Dogs(" \

 

     "did INT PRIMARY KEY NOT NULL," \

 

     "age INT NOT NULL);";

 

     // Execute SQL statement

 

     cr = sqlite3_exec(db, sql, Call, 0, &MsgErr);

 

     //If cr not equals SQLITE_OK

     if (cr != SQLITE_OK)

     {

 

          //Display message

          fprintf(stderr, "SQL error: %s\n", MsgErr);

 

          //Call sqlite3_free()

          sqlite3_free(MsgErr);

 

     }

 

     //If cr equals SQLITE_OK

     else

     {

 

          //Display message

          fprintf(stdout, " successfull!!!\n");

 

     }

 

     //Call sqlite3_close

     sqlite3_close(db);

 

     //Return 0

     return 0;

 

}

 

//Insert data into tables

 

//InsertValue.cpp

 

 

//Include libraries

#include <stdio.h>

#include <stdlib.h>

#include <sqlite3.h>

 

//Defne CALL()

static int CALL(void *NotUsed, int argc, char **argv, char **azColName)

{

 

     //Declare variable

     int i;

 

     //Loop until argc value

     for (i = 0; i<argc; i++)

     {

 

          //Display message

printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

 

     }

 

     //Display new line

     printf("\n");

 

     //Return 0

     return 0;

 

}

 

 

//Define main method

int main(int argc, char* argv[])

{

     //Define db

     sqlite3 *db;

 

     //Declare variables

     char *MsgErr = 0;

     int cr;

     char *sql;

 

     // Open database

     cr = sqlite3_open("test.db", &db);

 

     //If database not present

     if (cr)

     {

 

          //Display message

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     //If database present

     else

     {

 

          //Display message

          fprintf(stderr, "Successfull!!1\n");

 

     }

 

     // Defne Insert statements

sql = "INSERT INTO Veterinarians (vid,elevel)VALUES (1001,1); " \

 

     "INSERT INTO Examine (vid,did,FEE)VALUES (1001,1234,25 ); " \

 

     "INSERT INTO Dogs (did,age)VALUES (1234,10);"

 

 

 

     // Execute SQL statement

     cr = sqlite3_exec(db, sql, callback, 0, &MsgErr);

 

 

     //If cr not equals SQLITE_OK

     if (cr != SQLITE_OK)

     {

 

          //Display message

          fprintf(stderr, "SQL error: %s\n", MsgErr);

 

          //Call sqlite3_free()

          sqlite3_free(MsgErr);

 

     }

 

     //If cr equals SQLITE_OK

     else

     {

 

          //Display message

          fprintf(stdout, "Successfull!!\n");

 

     }

 

     //Call sqlite3_close()

     sqlite3_close(db);

 

     //return 0

     return 0;

 

}

 

// Display data

 

// Display.cpp:

 

//Include libraries

#include <stdio.h>

#include <stdlib.h>

#include <sqlite3.h>

 

//Define Call()

static int Call(void *data, int argc, char **argv, char **azColName)

{

 

     //Declare variable

     int i;

 

     //Display message

     fprintf(stderr, "%s: ", (const char*)data);

 

     //Loop until argc value

     for (i = 0; i<argc; i++)

     {

 

          //Display message

printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

 

     }

 

     //Display newline

     printf("\n");

 

     //Return 0

     return 0;

 

}

 

//Define main method

int main(int argc, char* argv[])

 

{

     //Define db

     sqlite3 *db;

 

     //Declare variables

     char *MsgErr = 0;

 

     int cr;

 

     char *sql;

 

     const char* data = "Call function is called";

 

     // Open database

 

     cr = sqlite3_open("test.db", &db);

 

     //If database not present

     if (cr)

     {

 

          //Display message

fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

 

          //Return 0

          return(0);

 

     }

 

     //If database is present

     else

     {

 

          //Display message

          fprintf(stderr, "Successfull!!!\n");

 

     }

 

     // Display data

 

     sql = SELECT Dogs.age, COUNT(*), AVG(X.fee),AVG(V.eLevel) FROM Dogs AS D,Exmaine AS X, Veterinarians AS VWHERE D.did = X.did AND X.vid = V.vid GROUP BY D.age;

 

     // Execute SQL statement

     cr = sqlite3_exec(db, sql, Call, (void*)data, &MsgErr);

 

     //If cr not equals SQLITE_OK

     if (cr != SQLITE_OK)

     {

 

          //Display message

          fprintf(stderr, "SQL error: %s\n", MsgErr);

 

          //Call sqlite3_free()

          sqlite3_free(MsgErr);

 

     }

 

     //If cr equals SQLITE_OK

     else

     {

 

          //Display message

          fprintf(stdout, "Successfull!!!\n");

 

     }

 

     //Close

     sqlite3_close(db);

 

     //Return 0

     return 0;}

 