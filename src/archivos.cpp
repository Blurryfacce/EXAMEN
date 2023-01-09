#include<iostream>
#include<stdlib.h>
#include <string.h>
#include<fstream>
using namespace std;

void escribirArchivo();
void lecturaArchivo();
int main(){
	escribirArchivo();
	lecturaArchivo();
	system("pause");
	return 0;
} 

void escribirArchivo(){
	ofstream escribirArchivo;
	string nombreArchivo,frase; // funcion para poder colocar el nombre que quiero que se cree el archivo y la frase
	char rpt;
	
	cout<<"Digite el nombre del archivo: ";
	getline(cin,nombreArchivo); //guardar e indicar donde guardarse
	
	escribirArchivo.open(nombreArchivo.c_str(),ios::out); //Creamos el archivo
	
	if(escribirArchivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"Digite una frase: ";
		getline(cin,frase);
		escribirArchivo<<frase<<endl;
		
		cout<<"\nDesea agregar otra frase(S/N): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	escribirArchivo.close(); //Cerramos el archivo
}
void lecturaArchivo(){
	ifstream leerArchivo;
	string texto;

	leerArchivo.open(".\\files\\hola.txt",ios::in); //abrimos el archivo en modo lectura

	if(leerArchivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}

	while(!leerArchivo.eof()){ // mientras no sea el final del archivo 
		getline(leerArchivo,texto);
		cout<<texto<<endl;

	}
leerArchivo.close(); //cerramos el archivo

}