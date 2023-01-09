#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std; 

int main()
{
        int segundos=45;
         int i;
          cout << "\t\t\t\t\t   LOADING...\n";
        for (int i = 0; i <=100; i++)
        {
            cout <<char(219);
            Sleep(segundos);
        } 
        cout <<"\nCompletado!\n";
        // system("pause");
        // system("clear");
    return 0;
}

