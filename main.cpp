#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
int menu() {
	while(true) {
		cout <<" Menu "<<endl
		     <<"1. Ejercicio 1: "<<endl
		     <<"2. Ejercicio 2: "<<endl
		     <<"3. Ejercicio 3: "<<endl
		     <<"4. Salir"<<endl
		     <<"Ingrese una opcion: ";
		int valor;
		cin>>valor;
		if(valor > 0 && valor < 5)
			return valor;
	}
}

void mostrarArreglo(char* arreglo, int tamano) {
	for (int i = 0; i < tamano; i++)
		cout << "['" << arreglo[i]<<"']";
	cout << endl;
}

void mostrarMatriz(char** matriz, int filas,int columnas) {
	for(int i=0; i < filas; i++) {
		for(int j=0; j < columnas; j++) {
			cout << "[ "<<matriz[i][j]<<" ]";
		}
		cout<<endl;
	}
}

char* arrChar (int cantChars, char* arreglo) {
	int cont;
	string acum1= "";
	string acum2= "";
	for(int i = 0; i < cantChars; i++) {
		char temporal = arreglo[i];
		if (temporal >= 48 && temporal <= 57) {
			acum1+=temporal;
		}
		if(temporal >= 48 && temporal <= 57) {
			if(arreglo[i+1]>= 48 && arreglo[i+1]<=57) {
				acum1+=arreglo[i+1];
				i++;
			}
		}
		if(temporal == 'D' || temporal == 'U' || temporal == 'R' || temporal == 'L') {
			cont = stoi(acum1);
			for(int j = 0; j  < cont; j++) {
				acum2+=temporal;
			}
			acum1="";
		}
	}
	char arregloResultante[acum2.size()];
	for(int i = 0; i < acum2.size(); i++) {
		arregloResultante[i]=acum2.at(i);
	}
	//DEBE SER LITERAL MAYUSCULAS PARA QUE NO EXPLOTE
	mostrarArreglo(arregloResultante,acum2.size());
	return arregloResultante;
}

char** retornarMatriz(int filas,int columnas,int obstaculos) {
	char** matrizTemp = 0; //inicializar en null
	srand(time(0));
	matrizTemp = new char*[filas];
	for(int i = 0; i<filas; i++) {
		matrizTemp[i] = new char[columnas];
	}
	int posicion1,posicion2, cont=0;
	//aqui la llenamos con guiones
	for(int i=0; i < filas; i++) {
		for(int j=0; j < columnas; j++) {
			matrizTemp[i][j]='-';
		}
	}
	for(int i=0; i < obstaculos; i++) {
		posicion1 = rand()%filas;
		posicion2 = rand()%columnas;
		while(matrizTemp[posicion1][posicion2]=='#') {
			posicion1 = rand()%filas;
			posicion2 = rand()%columnas;
		}
		matrizTemp[posicion1][posicion2] = '#';
	}
	return matrizTemp;
}
void pause() {
	cout << "Presione Enter para ver el siguiente paso...";
	cin.ignore();
	cin.get();
}

void clear() {
	if( getenv( "OS" ) == NULL) {
		system( "clear" );
	} else {
		system( "cls" );
	}
}

int main(int argc, char** argv) {
	int opcion=0;
	while(opcion != 4) {
		switch(opcion=menu()) {
			case 1: {
				int cantChars;
				string caracter;
				char arreglo[cantChars];
				cout << "Ingrese la cantidad de caracteres que desee ingresar: " << endl;
				cin >> cantChars;
				while(cantChars < 0) {
					cout << "No se permiten numeros negativos, intente nuevamente!" << endl;
					cout << "Ingrese la cantidad de caracteres que desee ingresar: " << endl;
					cin >> cantChars;
				}
				char* arregloTemp = new char [cantChars];
				for(int i=0; i < cantChars ; i++) {
					cout << "Ingrese el caracter(LETRAS MAYUSCULAS [U,D,L,R]): "<<endl;
					cin >> arreglo[i];
				}
				cout << "Sus caracteres han sido guardados!" <<endl;
				cout << "Arreglo: " <<endl;
				mostrarArreglo(arreglo,cantChars);
				cout << endl;
				cout << "Arreglo Resultante: ";
				arrChar(cantChars,arreglo);
				break;
			}
			case 2: {
				//Matriz de chars
				int filas,columnas, obstaculos;
				char** MatrizResultante;
				cout << "Ingrese la cantidad de filas: "<< endl;
				cin >> filas;
				while(filas < 0) {
					cout << "Las filas no pueden ser negativas" << endl;
					cout << "Ingrese la cantidad de filas: "<< endl;
					cin >> filas;
				}
				cout << "Ingrese la cantidad de columnas: "<<endl;
				cin >> columnas;
				while(columnas < 0) {
					cout << "Las columnas no pueden ser negativas" << endl;
					cout << "Ingrese la cantidad de columnas: "<< endl;
					cin >> columnas;
				}
				cout << "Ingrese la cantidad de obstaculos: "<<endl;
				cin >> obstaculos;
				while(obstaculos < 0) {
					cout << "Las obstaculos no pueden ser negativas" << endl;
					cout << "Ingrese la cantidad de obstaculos: "<< endl;
					cin >> obstaculos;
				}
				MatrizResultante=retornarMatriz(filas,columnas,obstaculos);
				mostrarMatriz(MatrizResultante,filas,columnas);
				break;
			}
			case 3: {
				//COMBINACION DE EJERCICIOS
				int cantChars;
				string caracter;
				char arreglo[cantChars];
				cout << "Ingrese la cantidad de caracteres que desee ingresar: " << endl;
				cin >> cantChars;
				while(cantChars < 0) {
					cout << "No se permiten numeros negativos, intente nuevamente!" << endl;
					cout << "Ingrese la cantidad de caracteres que desee ingresar: " << endl;
					cin >> cantChars;
				}
				char* arregloTemp = new char [cantChars];
				for(int i=0; i < cantChars ; i++) {
					cout << "Ingrese el caracter(LETRAS MAYUSCULAS [U,D,L,R]): "<<endl;
					cin >> arreglo[i];
				}
				cout << "Sus caracteres han sido guardados!" <<endl;
				cout << "Arreglo: " <<endl;
				mostrarArreglo(arreglo,cantChars);
				cout << endl;
				cout << "Secuencia transformada: " << endl;
				arrChar(cantChars,arreglo);
				//REUTILIZO EL EJERCICIO2
				int filas,columnas, obstaculos;
				char** MatrizResultante;
				cout << "Ingrese la cantidad de filas: "<< endl;
				cin >> filas;
				while(filas < 0) {
					cout << "Las filas no pueden ser negativas" << endl;
					cout << "Ingrese la cantidad de filas: "<< endl;
					cin >> filas;
				}
				cout << "Ingrese la cantidad de columnas: "<<endl;
				cin >> columnas;
				while(columnas < 0) {
					cout << "Las columnas no pueden ser negativas" << endl;
					cout << "Ingrese la cantidad de columnas: "<< endl;
					cin >> columnas;
				}
				cout << "Ingrese la cantidad de obstaculos: "<<endl;
				cin >> obstaculos;
				while(obstaculos < 0) {
					cout << "Las obstaculos no pueden ser negativas" << endl;
					cout << "Ingrese la cantidad de obstaculos: "<< endl;
					cin >> obstaculos;
				}
				MatrizResultante=retornarMatriz(filas,columnas,obstaculos);
				mostrarMatriz(MatrizResultante,filas,columnas);
				//Tercer parte
				char caracter186 = 186,caracter187=187,caracter188=188,caracter200=200, caracter201 = 201, caracter205=205;
				int filaInicial, columnaInicial;
				cout << "Ingrese la fila inicial de la ruta: " <<endl;
				cin >> filaInicial;
				while(filaInicial < 0){
					cout<< "Las filas no pueden ser negativas!!" << endl;
					cout << "Ingrese la fila inicial de la ruta: " <<endl;
					cin >> filaInicial;
				}
				//validar si esta dentro del rango
				while(filaInicial > filas){
					cout << "El rango se excede, intente nuevamente" <<endl;
					cout << "Ingrese la fila inicial de la ruta: " <<endl;
					cin >> filaInicial;
				}	
				cout << "Ingrese la columna inicial de la ruta: "<<endl;
				cin >> columnaInicial;
				while(columnaInicial < 0){
					cout<< "Las columnas no pueden ser negativas!!" << endl;
					cout << "Ingrese la columna inicial de la ruta: " <<endl;
					cin >> columnaInicial;
				}
				while(columnaInicial > columnas){
					cout << "El rango se excede, intente nuevamente" <<endl;
					cout << "Ingrese la columna inicial de la ruta: " <<endl;
					cin >> columnaInicial;
				}
				//Validar si encuentra un obstaculo
				/*while(MatrizResultante[i][j]!='#'){
					MatrizResultante[i][j]=caracter186;
				}*/
				break;
			}
			case 4: {
				cout << "Gracias por utilizar el programa!" << endl;
				break;
			}
			default: {
				cout << "Dato ingresado no es valido!" << endl;
				break;
			}
		}
	}
	return 0;
}