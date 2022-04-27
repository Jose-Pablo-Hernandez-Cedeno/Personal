#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int MenuPrincipal();//Función que imprime el menú y retorna elección del usuario
bool ValidarCaracterNumerico(char Carcater);//Algoritmo de búsqueda lineal que retorna true solo si el caracter se valida como dato numérico
int ConvertirChar(char Caracter);//Función que recibe un caracter numérico y retorna su quivalente en tipo int
int ConvertirString(string Cadena);//Función que recibe una cadena de caracteres numéricos y retorna su quivalente en tipo int
string ConvertirNum(int Numero);//Función que recibe un dato tipo int  y retorna su quivalente en forma de cadena de caracteres numéricos
char LeerValidandoChar(char ValorPosible1, char ValorPosible2);//Función que lee un caracter validando que tome uno de los 2 valores especificados en los argumentos
void RegistrarDatosUsuario();//Función que verifica que la cédula ingresada no esté ya registrada y registra los datos de ser el caso
void NuevoRegistro(string Direccion, string ContenidoRegistro);//Función que escribe un nuevo registro con el contenido especificado en el archivo
string LeerValidandoCedula();//Función que lee una cadena validando que solo tenga caracteres númericos y sean 10
string LeerValidandoNombre();//Función que lee una cadena validando que no contenga ningún caracter de espacio en blanco
int BuscarRegistro(string Dato, string Direccion, int NumCampo);//Algoritmo de búsqueda lineal del registro que contiene el dato especificado, del archivo especificado, sobre los campos indicados en el tercer argumento
void VerificarArchivoSistema(string Direccion);//Función que intenta abrir un archivo para verificar su existencia, si falla verifica que si es un archivo de sistema para finalizar ejecución o crearlo si no
string ObtenerCampo(string Direccion, int NumRegistro, int NumCampo);//Función que retorna el dato ubicado en el archivo, registro y campo especificado
void ReporteJugadores();//Función que genera el reporte de jugadores
void MostrarMejoresJugadores();//Función que imprime los datos del archivo Registros_jugadores.txt en el orden especificado por las referencias almacenadas en un archivo temporal
void OrdenarRegistros();//Función que genera un archivo temporal en dónde, mediante referencias a los registros originales, enlista ascendentemente, respecto a los puntajes, los registros del archivo Registros_jugadores.txt

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
			{
			//Mecánica ingresar jugadores
			char SeguirIngresando;
			do {
				system("cls");
				cout <<	"****************************************************************\n";
				cout.width(42);
				cout <<right<< "Ingresar Jugadores\n";
				cout << "****************************************************************\n\n";
				RegistrarDatosUsuario();
				cout << "¿Desea ingresar otro jugador?\n"
				"Formato de respuesta: S/N\n"
				"Su respuesta: ";
				SeguirIngresando = LeerValidandoChar('S', 'N');
			} while (SeguirIngresando == 'S');
			VolverAlMenu = true;
			break;
			}

		case (2):
			{
			//Jugar hiatos y diptongos
			cout <<	"****************************************************************\n";
			cout.width(45.5);
			cout <<right<< "Jugar Hiatos y Diptongos\n";
			cout << "****************************************************************\n\n";
			ifstream PruebaLectura("Registros_jugadores.txt");
			bool LecturaFallida = PruebaLectura.fail();
			PruebaLectura.close();
			if ( LecturaFallida ) {
				cout << "ADVERTENCIA:\n"
				"Debe registrar previamente a los jugadores para acceder al\n"
				"juego de hiatos y diptongos\n\n";
			} else {
				

				//codjksdf


			}
			break;
			}

		case (3):
			{
			//Jugar antónimos y sinónimos
			cout <<	"****************************************************************\n";
			cout.width(48.5);
			cout <<right<< "Jugar antónimos y sinónimos\n";
			cout << "****************************************************************\n\n";
			ifstream PruebaLectura("Registros_jugadores.txt");
			bool LecturaFallida = PruebaLectura.fail();
			PruebaLectura.close();
			if ( LecturaFallida ) {
				cout << "ADVERTENCIA:\n"
				"Debe registrar previamente a los jugadores para acceder al\n"
				"juego de antónimos y sinónimos\n\n";
			} else {


				//codjksdf


			}
			break;
			}

		case (4):
			{
			//Mostrar reporte de jugadores
			cout <<	"****************************************************************\n";
			cout.width(43);
			cout <<right<< "Reporte de jugadores\n";
			cout << "****************************************************************\n\n";
			ifstream PruebaLectura("Registros_jugadores.txt");
			bool LecturaFallida = PruebaLectura.fail();
			PruebaLectura.close();
			if ( LecturaFallida ) {
				cout << "ADVERTENCIA:\n"
				"Debe registrar previamente a los jugadores para acceder al\n"
				"reporte de jugadores\n\n";
			} else {
				ReporteJugadores();
			}
			cout << "¿Desea volver al menú principal?\n"
			"Formato de respuesta: S/N\n"
			"Su respuesta: ";
			VolverAlMenu = ( LeerValidandoChar('S', 'N') == 'S' ?true:false);
			break;
			}
		case (5):
			{
			//Mostrar los 10 mejores jugadores
			cout <<	"****************************************************************\n";
			cout.width(45);
			cout <<right<< "Los 10 Mejores Jugadores\n";
			cout << "****************************************************************\n\n";
			ifstream PruebaLectura("Registros_jugadores.txt");
			bool LecturaFallida = PruebaLectura.fail();
			PruebaLectura.close();
			if ( LecturaFallida ) {
				cout << "ADVERTENCIA:\n"
				"Debe registrar previamente a los jugadores para acceder al\n"
				"top 10 de mejores jugadores\n\n";
			} else {
				MostrarMejoresJugadores();
			}
			
			cout << "¿Desean volver al menú?\n"
			"Formato de respuesta: S/N\n"
			"Su respuesta: ";
			VolverAlMenu = ( LeerValidandoChar('S', 'N') == 'S' ?true:false);
			break;
			}
		case (6):
			{
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
			}
		default:
			{
			system("cls");
			cout << " ***ALGÚN ERROR FATAL OCURRIÓ, ESTE CARTEL NUNCA DEBIÓ MOSTRARSE***\n\n"
			"                LA EJECUCIÓN HA TERMINADO AUTOMÁTICAMENTE";
			exit(1);
			break;
			}
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

int ConvertirString(string Cadena) {
	int DatoInt = 0;//Almacena el resultado de la conversión
	for(int NumCaracter = 0 ; NumCaracter < Cadena.length() ; NumCaracter++) {
		DatoInt = DatoInt + ConvertirChar(Cadena[NumCaracter])*pow( 10, Cadena.length()-(NumCaracter+1) );
	}
	return DatoInt;
}//Función que recibe una cadena de caracteres numéricos y retorna su quivalente en tipo int

string ConvertirNum(int Numero) {
	const int CantCaracNumericos = 10;
	char CaracNumericos[CantCaracNumericos] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char CaracDigito;
	string DatoString;
	while ( Numero != 0 ) {
		for ( int NumDigito = 0 ; NumDigito < CantCaracNumericos ; NumDigito++ ) {
			if ( NumDigito == (Numero % 10) ) {
				CaracDigito = CaracNumericos[NumDigito];
			}
		}
		DatoString = CaracDigito + DatoString;
		Numero /= 10;
	}
	return DatoString;
}//Función que recibe un dato tipo int  y retorna su quivalente en forma de cadena de caracteres numéricos

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

void RegistrarDatosUsuario() {

	string Cedula;
	string NombreJugador;
	bool CedulaRepetida = false;
	do {
		Cedula = LeerValidandoCedula();
		NombreJugador = LeerValidandoNombre();
		CedulaRepetida = BuscarRegistro(Cedula, "Registros_jugadores.txt", 1);
		if (CedulaRepetida) {
			cout << "  ***El jugador ya existe en el registro, intentelo de nuevo***\n\n";
		} else {
			cout << "El jugador ha sido registrado correctamente!!!\n\n";
			NuevoRegistro("Registros_jugadores.txt", Cedula+' '+NombreJugador+' '+'0'+' '+'\n');
		}
	} while (CedulaRepetida);
}//Función que verifica que cada cédula ingresada no esté ya registrada y registra los datos de ser el caso

void NuevoRegistro(string Direccion, string ContenidoRegistro) {
	ofstream archivo(Direccion, ios::app);
	archivo << ContenidoRegistro;
	archivo.close();
}

string LeerValidandoCedula() {
	string Intento;//Almacena los datos ingresados
	const int NumDigitos = 10;//Número de dígitos requeridos en el formato de cédula usado
	bool CaracteresNumericos = true;//Almacena estado de validez de datos ingresados en cuanto asi son numéricos en su totalidad o no
	bool CedulaValida = false;//Almacena estado de validez de datos ingresados

	cout << "Formato de respuesta: (10 Dígitos | Solo números)\n"
	"Número de cédula: ";
	do {
		CaracteresNumericos = true;//Reinicio de boleano que almacena el estado de validez de datos ingresados en cuanto asi son numéricos en su totalidad o no
		getline(cin, Intento, '\n');
		for (int IndCaracter = 0 ; IndCaracter < Intento.length() ; IndCaracter++) {
			if ( !ValidarCaracterNumerico(Intento[IndCaracter]) ) {
				CaracteresNumericos = false;
			}
		}//For que recorre la string digitada para validar caracter por caracter que el dato ingresado sea numérico
		CedulaValida = (CaracteresNumericos && Intento.length() == NumDigitos);
		if (!CedulaValida) {
			cout << "\n\n   ***ERROR, DATOS INGRESADOS INVÁLIDOS***\n\n"
			"Formato de respuesta: (10 Dígitos | Solo números)\n"
			"Número de cédula: ";
		}//Fin if que muestra mensaje de error de ser necesario
	} while (!CedulaValida);
	cout << "\n\n";
	return Intento;
}//Función que lee una cadena validando que solo tenga caracteres númericos y sean 10

string LeerValidandoNombre() {
	string Intento;//Almacena los datos ingresados
	bool NombreValido = true;//Almacena estado de validez de datos ingresados

	cout << "Formato de respuesta: (No se aceptan espacios en blanco)\n"
	"Nombre del Jugador: ";

	do {
		NombreValido = true;//Reincio de boleano que almacena estado de validez de datos ingresados
		getline(cin, Intento, '\n');
		for (int IndCaracter = 0; IndCaracter < Intento.length() ; IndCaracter++) {
			if (Intento[IndCaracter] == ' ') {
				NombreValido = false;
			}
		}//For que recorre la string digitada para validar caracter por caracter que el dato ingresado no contenga espacios en blanco

		if (!NombreValido) {
			cout << "\n\n   ***ERROR, DATOS INGRESADOS INVÁLIDOS***\n\n"
			"Formato de respuesta: (No se aceptan espacios en blanco)\n"
			"Nombre del Jugador: ";
		}//Fin if que muestra mensaje de error de ser necesario
	} while (!NombreValido);
	cout << "\n\n";
	return Intento;
}//Función que lee una cadena validando que no contenga ningún caracter de espacio en blanco

int BuscarRegistro(string Dato, string Direccion, int NumCampo) {
	VerificarArchivoSistema(Direccion);
	int NumRegistro = 1;
	while (ObtenerCampo(Direccion, NumRegistro, NumCampo) != "\n\n") {
		VerificarArchivoSistema(Direccion);
		if (ObtenerCampo(Direccion, NumRegistro, NumCampo) == Dato) {
			return NumRegistro;
		}//Fin if que retorna el número del registro en caso de que corresponda al que contenga a Dato en el campo número NumCampo
		NumRegistro++;
	}//Fin while que recorre todos los campos con el número especificado del archivo especificado
	return 0;
}//Función que lee una cadena validando que no contenga ningún caracter de espacio en blanco

void VerificarArchivoSistema(string Direccion) {
	ifstream Archivo(Direccion);
	if (Archivo.fail()) {
		if (Direccion == "Registros_jugadores.txt" || Direccion == "temp.txt") {
			ofstream NuevoArchivo(Direccion);
			NuevoArchivo.close();
		} else {
			system("cls");
			cout <<"\n\n\n   ***ERROR: UN ARCHIVO DEL SISTEMA HA SIDO ELIMINADO***\n\n\n"
			"Verifique la existencia de los archivos:\n\n      *Sinónimos\n      *Antónimos\n      *Diptongos\n      *Hiatos\n\nY luego vuelva a ejecutar el programa";
			Archivo.close();
			exit(0);
		}//Fin if-else que cierra la jecución si la apertura fallida fue de un archivo de sistema o crea uno nuevo si no
	}//Fin if que verifica si falló la apertura del archivo
	Archivo.close();
}//Función que intenta abrir un archivo para verificar su existencia, si falla verifica si es un archivo de sistema para finalizar ejecución o crearlo si no

string ObtenerCampo(string Direccion, int NumRegistro, int NumCampo) {
	string CandidatoRegistro;
	string CandidatoCampo;
	int Indice = 0;
	ifstream Archivo(Direccion);

	for (int Registro = 0 ; Registro < NumRegistro ; Registro++) {
		if ( !getline(Archivo, CandidatoRegistro, '\n') ) {
			Archivo.close();
			return "\n\n";
		}
	}//Fin for que obtiene el registro correspondiente del archivo

	for(int Campo = 0 ; Campo < NumCampo ; Campo++) {
		CandidatoCampo = "";
		while (CandidatoRegistro[Indice] != ' ') {
			CandidatoCampo += CandidatoRegistro[Indice];
			Indice++;
		}
		Indice++;
	}//Fin for que obtiene el campo correspondiente del registro leído
	Archivo.close();
	return CandidatoCampo;
}//Función que retorna el dato ubicado en el archivo, registro y campo especificado

void ReporteJugadores() {
	const int DatosPorRegistro = 2;//Cantidad de datos a imprimir por cada registro leído
	int NumRegistro = 0;//Contador que almacena el número de registro a ser leído
 	ifstream Registros;

	cout << setw(41) << left << "Nombre del Jugador" << " | " << "Número de cédula" << endl;
	while ( ObtenerCampo("Registros_jugadores.txt", ++NumRegistro, 1 ) != "\n\n" ) {
		for (int NumCamposLeidos = 0 ; NumCamposLeidos < DatosPorRegistro ; NumCamposLeidos++ ) {
			cout << setw(41) << ObtenerCampo( "Registros_jugadores.txt", NumRegistro,(NumCamposLeidos?1:2) ) << (NumCamposLeidos?"\n":" | ");
		}
	}//Fin while que recorre los registros imprimiendo el campo de la cédula o del nombre del jugador en cada ciclo según la paridad del contador
	cout << "\n";
}//Función que genera el reporte de jugadores

void MostrarMejoresJugadores() {

	OrdenarRegistros();
	int NumRegistro = 0;
	while ( ObtenerCampo("temp.txt", ++NumRegistro, 1) != "\n\n" ) {
		int RegistroJugador = ConvertirString( ObtenerCampo("temp.txt", NumRegistro, 1) );
		cout <<"Jugador #" << setw(20) << left << NumRegistro << "|      " << ObtenerCampo("Registros_jugadores.txt", RegistroJugador, 2)<<endl;
	}
	cout << "\n";
}//Función que genera reporte de los 10 mejores jugadores

void OrdenarRegistros() {
	ofstream archivo("temp.txt");
	archivo.close();
	int RegistrosLeidos = 0;

	while( ObtenerCampo("Registros_jugadores.txt", ++RegistrosLeidos, 1) != "\n\n" ) {
		int NumRegistro = 0;
		int PuntajeLeidoInt = 0;
		int MayorPuntaje = 0;
		int NumRegistroMejorPuntaje = 0;
		while( ObtenerCampo("Registros_jugadores.txt", ++NumRegistro, 1) != "\n\n" ) {
			PuntajeLeidoInt = ConvertirString(ObtenerCampo("Registros_jugadores.txt", NumRegistro, 3));
			if (NumRegistro == 1) {
				MayorPuntaje = PuntajeLeidoInt;
				NumRegistroMejorPuntaje = NumRegistro;
			} else if ( PuntajeLeidoInt > MayorPuntaje && !BuscarRegistro(ConvertirNum(NumRegistro), "temp.txt", 1) ) {
				MayorPuntaje = PuntajeLeidoInt;
				NumRegistroMejorPuntaje = NumRegistro;
			}

		}

		if ( !BuscarRegistro(ConvertirNum(NumRegistroMejorPuntaje), "temp.txt", 1) ) {
			NuevoRegistro("temp.txt", ConvertirNum(NumRegistroMejorPuntaje)+' '+'\n');
		}

		int NumRegistroVerif = 0;
		while ( ObtenerCampo("Registros_jugadores.txt", ++NumRegistroVerif, 1) != "\n\n") {
			if ( ConvertirString( ObtenerCampo("Registros_jugadores.txt", NumRegistroVerif, 3) ) == MayorPuntaje && !BuscarRegistro(ConvertirNum(NumRegistroVerif), "temp.txt", 1)) {
				NuevoRegistro("temp.txt", ConvertirNum(NumRegistroVerif)+' '+'\n');
			}
		}
	}
}//Función que genera un archivo temporal en dónde, mediante referencias a los registros originales, enlista ascendentemente, respecto a los puntajes, los registros del archivo Registros_jugadores.txt
