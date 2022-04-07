#include <iostream>
#include <fstream>
using namespace std;

int main {
    //out-Salida datos desde el programa al archivo
    ofstream archivo("prueba.txt", ios::out);//declaración objeto para manipular archivo
    
    /*
    * AbrirArchivo("dirección//string.c_str)", ios::salida/entrada)
    * archivo.open("prueba.txt", ios::out);
    *out: Reemplaza o crea archivo
    */
    string DataEntrada; getline(cin, DataEntrada);
    archivo<< DataEntrada;

    archivo.close()
    //Cerrar archivo
    
    return 0;
}