#include <fstream>
#include <iostream>
using namespace std;

int MenuPrincipal();//Función que imprime el menú y retorna elección del usuario
bool ValidarCaracterNumerico(char Carcater);//Algoritmo de búsqueda lineal que retorna true solo si el caracter se valida como dato numérico
int ConvertirChar(char Caracter);//Función que recibe un caracter numérico y retorna su quivalente en tipo int
char LeerValidandoChar(char ValorPosible1, char ValorPosible2);//Función que lee un caracter validando que tome uno de los 2 valores especificados en los argumentos
string LeerValidandoCedula();

int main() {
	setlocale(LC_CTYPE,"");
	system("title Proyecto Final");

	int EleccionMenu = 0;//Almacena la elección del usuario para el menú en caso de cumplirse parametros de entrada
	bool VolverAlMenu = false;//Boleano que controla si debe reiniciarse el programa y o si no
	
	do {
		//Reinicio de variable para finalizar ejecución del programa por default al acabar ejecución del ciclo del do-while
		system("cls");
		VolverAlMenu = false;
		
		//Menú principal
		EleccionMenu = MenuPrincipal();
		system("cls");

		//Ejecución de código según elección
		switch (EleccionMenu) {
		case (1):
			//Mecánica ingresar jugadores
			cout <<	"****************************************************************\n";
			cout.width(42);
			cout <<right<< "Ingresar Jugadores\n";
			cout << "****************************************************************\n\n";
			RegistrarCedula();
			break;
		
		case (2):
			//Jugar hiatos y diptongos
			cout <<	"****************************************************************\n";
			cout.width(45.5);
			cout <<right<< "Jugar Hiatos y Diptongos\n";
			cout << "****************************************************************\n\n";
			
			break;
		
		case (3):
			//Jugar antónimos y sinónimos

			break;
		
		case (4):
			//Mostrar reporte de jugadores
			break;
		
		case (5):
			//Mostrar los 10 mejores jugadores
			break;
		
		case (6):
			//Salir del programa
			cout << "    ¿Está seguro de que desea salir del programa?\n\n"
			"Formato de respuesta: S/N\n"
			"Su respuesta: ";
			if (LeerValidandoChar('S','N') == 'S') {
				system("cls");
				cout << "                LA EJECUCIÓN HA TERMINADO PORQUE HA SALIDO DEL PROGRAMA";
				exit(0);
			} else {
				VolverAlMenu = true;
			}//Fin if-else que finaliza la ejecución o reinicia el programa en función del boleano VolverAlMenu
			break;
		
		default:
			system("cls");
			cout << " ***ALGÚN ERROR FATAL OCURRIÓ, ESTE CARTEL NUNCA DEBIÓ MOSTRARSE***\n\n"
			"                LA EJECUCIÓN HA TERMINADO AUTOMÁTICAMENTE";
			exit(1);
			break;
		}
		system("cls");
	} while (VolverAlMenu);
	
	return 0;
}

int MenuPrincipal() {
	int Eleccion = 0;//Almacena la elección del usuario para el menú y es retornado en caso de cumplirse parametros de entrada
	bool RespuestaValida = false;//Almacena estado de validez de datos ingresados
	string InfoIngresada;//Almacena todos los datos ingresados para efectuar validación de los mismos
	
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
        getline(cin, InfoIngresada, '\n');
		if (ValidarCaracterNumerico(InfoIngresada[0])) {
			Eleccion = ConvertirChar(InfoIngresada[0]);
			RespuestaValida = (InfoIngresada.length() == 1 && 1 <= Eleccion && Eleccion <= 6);
		}//Fin if de validaciones de parámetros de ingreso que se efectúan en caso de haber un primer caracter numérico 
		
        if (!RespuestaValida) {
            cout << "\n\n   ***ERROR, DATOS INGRESADOS INVÁLIDOS***\n\n"
            "Digite un número para acceder a la opción: ";
        }//Fin if para mostar mensaje de error en caso de no cumplir parámetros de ingreso
    } while(!RespuestaValida);
    return Eleccion;
}//Fin función que imprime el menú y retorna elección del usuario

bool ValidarCaracterNumerico(char Caracter) {
	const int CantCaracNumericos = 10;//Cantidad total de posibles caracteres númericos
	char CaracterNumerico[CantCaracNumericos] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};//Arreglo de posibles caracteres numéricos
	for (int Indice = 0 ; Indice < CantCaracNumericos ; Indice++) {
		if (Caracter == CaracterNumerico[Indice]) {
			return true;
		}//Fin if que compara al caracter con el elemento del arreglo de posibles caracteres numéricos
	}//Fin for que recorre los elementos del Arreglo de posibles caracteres numéricos
	return false;
}//Fin función que valida que el argumento sea un caracter numérico mediante búsqueda lineal de una coincidencia con él en el arreglo de posibles caracteres numéricos

int ConvertirChar(char Caracter) {
	const int CantCaracNumericos = 10;//Cantidad total de posibles caracteres númericos
	char CaracterNumerico[CantCaracNumericos] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};//Arreglo de posibles caracteres numéricos
	for (int Indice = 0 ; Indice < CantCaracNumericos ; Indice++) {
		if (Caracter == CaracterNumerico[Indice]) {
			return Indice;//Se retorna el valor numérico del caracter númerico de ser el caso
		}//Fin if que compara al caracter con el elemento del arreglo de posibles caracteres numéricos
	}//Fin for que recorre los elementos del Arreglo de posibles caracteres numéricos
}//Fin función que recibe un caracter numérico y retorna su quivalente en tipo int

char LeerValidandoChar(char ValorPosible1, char ValorPosible2) {
	string ValorLeido;//Almacena todos los datos ingresados para efectuar validación de los mismos
	char RespuestaValida;//Almacena estado de validez de datos ingresados
	do {
		getline(cin, ValorLeido, '\n');
		RespuestaValida = ((ValorLeido[0] == ValorPosible1 || ValorLeido[0] == ValorPosible2) && ValorLeido.length() == 1);
		//Fin validaciones de parámetros de ingreso
		if (!RespuestaValida) {
			cout << "\n\n   ***ERROR, DATOS INGRESADOS INVÁLIDOS***\n\n"
			"Formato de respuesta: S/N\n"
			"Su respuesta: ";
		}//Fin if para mostar mensaje de error en caso de no cumplir parámetros de ingreso
	} while(!RespuestaValida);
	return ValorLeido[0];	
}//Función que lee un caracter validando que tome uno de los 2 valores especificados en los argumentos

RegistrarCedula() {
	string Cedula;
	string NombreJugador;
	bool CedulaRepetida = false;
	do {
		Cedula = LeerValidandoCedula();
		getline(cin, NombreJugador, '\n');
		CedulaRepetida = EncontrarCedula(Cedula);
		if (CedulaRepetida) {
			cout << "  ***El jugador ya existe, la cédula ya fue registrada anteriormente, intentelo de nuevo***\n\n";
		} else {
			cout << "El jugador ha sido registrado correctamente\n\n";
			ofstream archivo("Registros_jugadores.txt", ios::app);
			archivo << Cedula+' '+NombreJugador+' '+'0'+' '+'\n';
		}
	} while (CedulaRepetida);
	
	

}

string LeerValidandoCedula() {
	string Intento;
	const int NumDigitos = 10;//Número de dígitos requeridos en el formato de cédula usado
	int IndCaracter = 0;
	bool CaracteresNumericos = true;//Almacena estado de validez de datos ingresados en cuanto asi son numéricos en su totalidad o no
	bool CedulaValida = false;//Almacena estado de validez de datos ingresados
	
	do {
		cout << "Formato de respuesta: (10 Dígitos | Solo números)\n"
		"Número de cédula: ";
		getline(cin, Intento, '\n');
		while (Intento[IndCaracter] != '\n') {
			if (!ValidarCaracterNumerico(Intento[IndCaracter])) {
				CaracteresNumericos = false;
			}
			IndCaracter++;
		}
		CedulaValida = (CaracteresNumericos && Intento.length() == 10);
		if (!CedulaValida) {
			cout << "\n\n   ***ERROR, DATOS INGRESADOS INVÁLIDOS***\n\n"
			"Formato de respuesta: (10 Dígitos | Solo números)\n"
			"Número de cédula: ";
		}
	} while (!CedulaValida);
	cout << "\n\n";
	return Intento;
}