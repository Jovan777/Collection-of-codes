// SQL_liteC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sqlite3.h"


using namespace std;

void print_allUsers(sqlite3* db) {

    sqlite3_stmt* stmt;
    const char* sql = "select * from Komitent";
    const char* endsql;
    
    int rc = sqlite3_prepare(db, sql, 256, &stmt, &endsql);

    if (rc!=SQLITE_OK)
    {
        cout << "sql error " << sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        return;

    }

    cout << "All users : " << endl;
    while ((rc=sqlite3_step(stmt))==SQLITE_ROW)
    {
        cout << sqlite3_column_int(stmt, 0)<<"\t";
        cout << sqlite3_column_text(stmt, 1) << "\t";
        cout << sqlite3_column_text(stmt, 2) << endl;


    }

    sqlite3_finalize(stmt);
    cout << endl;



}

void print_all_bank_acc(sqlite3* db) {

    sqlite3_stmt* stmt;
    const char* sql = "select idRac, Stanje, Status from Racun";
    const char* endsql;

    int rc = sqlite3_prepare(db, sql, 256, &stmt, &endsql);

    if (rc != SQLITE_OK)
    {
        cout << "sql error " << sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        return;

    }

    cout << "All users : " << endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        cout << sqlite3_column_int(stmt, 0) << "\t";
        cout << sqlite3_column_int(stmt, 1) << "\t";
        cout << sqlite3_column_text(stmt, 2) << endl;


    }

    sqlite3_finalize(stmt);
    cout << endl;

}



void exec_stmt(sqlite3* db, const char* sql) {
    char* errMsg;

    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
    if (rc!=SQLITE_OK)
    {
        cout << "greska " << errMsg << endl;
        sqlite3_free(errMsg);
    }



 }


void print_users_adress(sqlite3* db, const char* adress) {

    sqlite3_stmt* stmt;
    const char* sql = "select idKom, Naziv, Adresa from Komitent where Adresa=?";
    const char* endSql;
    int rc = sqlite3_prepare(db, sql, 256, &stmt, &endSql);
    if (rc!=SQLITE_OK)
    {
        cout << "greska  " << sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        return;
    }

    sqlite3_bind_text(stmt, 1, adress, -1, nullptr);
    cout << "        All Users" << endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        cout << sqlite3_column_int(stmt, 0)<<"\t";
        cout << sqlite3_column_text(stmt, 1)<<"\t";
        cout << sqlite3_column_text(stmt, 2)<<endl;



    }

    cout << endl;
    sqlite3_finalize(stmt);

}

void moneyTransfer(sqlite3* db, int racFrom, int racTo, int iznos) {

    const char* sql = "UPDATE Racun SET Stanje=Stanje + ? WHERE IdRac=?";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare(db, sql, 256, &stmt, nullptr);
    if (rc!=SQLITE_OK)
    {
        cout << "Greska";
        return;
    }

    sqlite3_bind_int(stmt, 1, -iznos);
    sqlite3_bind_int(stmt, 2, racFrom);
    if ((rc=sqlite3_step(stmt))!=SQLITE_DONE)
    {
        cout << "Greska";
    }

    sqlite3_reset(stmt);
    sqlite3_clear_bindings(stmt);

    sqlite3_bind_int(stmt, 1, iznos);
    sqlite3_bind_int(stmt, 2, racTo);
    if ((rc = sqlite3_step(stmt)) != SQLITE_DONE)
    {
        cout << "Greska";
    }




}



int main()
{
    //cout << "Hello World!\n";

    sqlite3* db;

    int rc = sqlite3_open("Banka.db", &db);
    if (rc!=SQLITE_OK)
    {
        cout << "Greska";
        return 0;
    }
     
    cout << "Uspesno ucitana baza" << endl;


    print_allUsers(db);

    cout << endl << endl << endl;

    print_all_bank_acc(db);

    cout << endl << endl << endl;

   //exec_stmt(db, "update Komitent set Adresa='Vojvode Stepe 39' where idKom<4");
   //print_allUsers(db);


    print_users_adress(db, "Vojvode Stepe 39");

    cout << endl << endl << endl;

    cout << "Pre transfera" << endl;

    print_all_bank_acc(db);

    moneyTransfer(db, 1, 2, 100);

    cout << endl << "Posle transfera" << endl;

    print_all_bank_acc(db);

    cout << endl << endl << endl;

    print_allUsers(db);

    cout << endl << endl << endl;

    print_all_bank_acc(db);

    sqlite3_close(db);





    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
