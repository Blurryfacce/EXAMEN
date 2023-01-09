/**
 * @2023 Isaacproano, All Rights Reserved.
 * @author: isaacproano
 * @date 2023.09.01
 * examen primer bimestre
 **/

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
#include <windows.h>
#include <iomanip>
#include<thread>
#include "..\lib\ipcolor.h"
#include "..\lib\ip.utility.h"

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;
// codigo para la primera opción <datos del usuario>
void ipUsuario(){
    cout<<COLOR_LGREEN"CEDULA: 1755575709\n";
    cout<<"CORREO: ISAAC.PROANO@EPN.EDU.EC\n";
    cout<<"NOMBRE: Isaac Joshua Proaño Zambrano\n";

}
// codigo para la segunda opcion <progressbar>
void ipShowLoadingNombre_e(std::ostream &os,int time,
                   std::string message,char symbol = '*')
{
    static const auto bar_length = 100;
    if(message.length() >= bar_length){
        os << message <<"\n";
        message.clear();
    }else{
        message+=" ";
    }

    const auto progress_level = 100.0/(bar_length - message.length()); //delay

    std::cout<<message;

    for(double percentage=0;percentage<=101;percentage+=progress_level)
    {
        message+=symbol;
        os << "\r ["<<std::setw(3)<<static_cast<int>(percentage)<<"% ] "<<message<<std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    os <<"\n\n";

}

  
int main()
{
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("isaac.proano@epn.edu.ec");
    usuarios.push_back("profe");
 

    // Se añaden claves al vector
    claves.push_back("1755575709");
    claves.push_back("12345");
   
    string ipusuario, ippassword;

    int ipcontador = 0;
    bool ipingresa = false;

    do
    {
        system("cls");
        cout << COLOR_RED"\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << COLOR_BLUE"\n\tUsuario: ";          //LOGIN
        getline(cin, ipusuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        ippassword = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                ippassword.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (ippassword.length() > 0)
                {
                    cout << "\b \b";
                    ippassword = ippassword.substr(0, ippassword.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == ipusuario && claves[i] == ippassword)
            {
                ipingresa = true;
                break;
            }
        }

        if (!ipingresa)
        {
            cout <<COLOR_RED "\n\n\tEl usuario o password son incorrectos" << endl;
            cin.get();
            ipcontador++;
        }

    } while (ipingresa == false && ipcontador < INTENTOS);

    if (ipingresa == false)
    {
        cout << "\n\tLo sentimos tu usuario y clave son incorrectos...! Gracias :3" << endl;
    }
        else
        {
            cout <<COLOR_YELLOW "\n\n\tBienvenido al sistema" << endl;
             int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        // Texto del menú que se verá cada vez
        cout << COLOR_WHITE"\n\n<USUARIO>, Selecciona: " << endl;
        cout << COLOR_ORANGE"1. Mostrar usuario" << endl;
        cout << "2. Barra de carga" << endl;                //MENU
        cout << "3. Combinatoria" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                 ipUsuario();              
                
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                ipShowLoadingNombre_e(std::clog,100,COLOR_ROSE"[Isaac Joshua Proano",'=');
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                cout<<"Profe no alcance, perdon, pero se hizo lo que se pudo :,)";                
                
                system("pause>nul"); // Pausa            
                break;
                
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
            
                

    
        }
    cin.get();
    return 0;
}


