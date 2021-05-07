#include <iostream>
#include <ctime>
#include <cstdlib>
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

void mostrarArreglo(char arreglo[], int tamano) {
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

char* arrChar () {
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
	for(int i=0; i < cantChars ; i++) {
		cout << "Ingrese el caracter: "<<endl;
		cin >> caracter;
		caracter = arreglo[i];
	}
	cout << "Sus caracteres han sido guardados!" <<endl;
	cout << "Arreglo: " <<endl;
	mostrarArreglo(arreglo,cantChars);
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

int main(int argc, char** argv) {
	int opcion=0;
	while(opcion != 4) {
		switch(opcion=menu()) {
			case 1: {
				arrChar();
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