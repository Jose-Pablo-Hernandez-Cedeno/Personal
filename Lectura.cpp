#include <iostream>
#include <fstream>
using namespace std;

int main {
    //in-Entrada datos desde el archivo al programa
    ifstream archivo("prueba.txt");//declaración objeto para manipular archivo
    //archivo.open("dirección//string.c_str", ios::salida/entrada);

    string DataSalida; getline(archivo, DataSalida);
    cout>> DataSalida;

    archivo.close()
    //Cerrar archivo
    
    return 0;
}