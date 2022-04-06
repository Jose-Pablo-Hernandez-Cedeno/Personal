#include <fstream>
#include <iostream>
using namespace std;

bool CinFail();

int main() {
	setlocale(LC_CTYPE,"");
	system("title Proyecto Final");

	int EleccionMenu = 0;//Almacena la respuesta del usuario
    bool RespuestaInvalida = true;//Boleano correspondiente al estado de invalidez de respuesta introducida

	cout <<	"****************************************************************\n*";
	cout.width(39);
	cout << right << "Menú Principal";
	cout << "                       *\n"
	"****************************************************************\n\n"
	"1. Ingresar jugadores\n"
	"2. Jugar hiatos y diptongos\n"
	"3. Jugar antónimos y sinónimos\n"
	"4. Reporte de jugadores\n"
	"5. Los 10 mejores jugadores\n"
	"6. Salir del programa\n\n"
	"Digite un número para acceder a la opción: ";

    do {
        cin >> EleccionMenu;
        RespuestaInvalida = (CinFail() || EleccionMenu>6 || EleccionMenu<1);
        if (RespuestaInvalida) {
            cout << "\n\n   ***ERROR, DATOS INGRESADOS INVÁLIDOS***\n\n"
            "Digite un número para acceder a la opción: ";
        }
    } while(RespuestaInvalida);
    cout << "\n\n";
    return 0;
}

bool CinFail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        fflush(stdin);
        return true;
    } 
    return false;
}