#include <fstream>
#include <iostream>
using namespace std;

int MenuPrincipal();//Función que imprime el menú y retorna elección del usuario
bool ValidarCaracterNumerico(char Carcater);//Algoritmo de búsqueda lineal que retorna true solo si el caracter se valida como dato numérico
int ConvertirChar(char Caracter);//Función que recibe un caracter numérico y retorna su quivalente en tipo int
char LeerValidandoChar(char ValorPosible1, char ValorPosible2);//Función que lee un caracter validando que tome uno de los 2 valores especificados en los argumentos

int main() {
	setlocale(LC_CTYPE,"");
	system("title Proyecto Final");

	int EleccionMenu = 0;//Almacena la elección del usuario para el menú en caso de cumplirse parametros de entrada
	bool VolverAlMenu = true;//Boleano que controla si debe reiniciarse el programa y o si no
	
	do {
		//Menú principal
		system("cls");
		EleccionMenu = MenuPrincipal();
		system("cls");

		//Ejecución de código según elección
		switch (EleccionMenu) {
		case (1):
			//Mecánica ingresar jugadores
			break;
		
		case (2):
			//Jugar hiatos y diptongos
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
		} else {
			RespuestaValida = false;
		}//Fin if-else de validaciones de parámetros de ingreso
		
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
			"Su respuesta: ";
		}//Fin if para mostar mensaje de error en caso de no cumplir parámetros de ingreso
	} while(!RespuestaValida);
	return ValorLeido[0];	
}//Función que lee un caracter validando que tome uno de los 2 valores especificados en los argumentos