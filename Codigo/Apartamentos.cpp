#include <iostream> // librerias
#include <string>
#include <list> //manejos de listas
#include <fstream> //manejo de archivos
#include <cctype>

using namespace std;

//clase que representa un apartamento
class Apartamento {
public:
	int piso;
	int apto;
};
//lista de pisos
list<Apartamento> apartamentos[100];
int n = 0;

// compara dos apartamentos para ordenarlos ascendentemente
bool compararAsc(const Apartamento& first, const Apartamento& second) {
	return (first.apto < second.apto);
}
// compara dos apartamentos para ordenarlos descendentemente

bool compararDesc(const Apartamento& first, const Apartamento& second) {
	return (first.apto > second.apto);
}
// ordena  orden ascendente

void ordenarAsc() {
	for (int i = 0; i < 26; i++) {
		apartamentos[i].sort(compararAsc);
	}
}
// ordena en orden descendente

void ordenarDesc() {
	for (int i = 0; i < 26; i++) {
		apartamentos[i].sort(compararDesc);
	}
}
// lista los apartamentos ascendentemente
void ListarAsc() {
	//llama al metodo ordenar ascendentemente
	ordenarAsc();
	//crea un iterador de la lista
	list<Apartamento>::iterator it;
	//imprime mensajes
	cout << "Listar Ascendentemente" << endl;
	
	//itera en las 26 listas
	for (int i = 0;i < n;i++) {
		cout << "Piso:"<<(i+1)<<endl;
		//imprime la lista de apartamentos de la letra i
		for (it = apartamentos[i].begin(); it != apartamentos[i].end(); ++it) {
			std::cout << it->apto << "\t";
		}
		cout << endl;
	}
}
//similar a ordenar ascendentemente solo que lo hace al contrario
void ListarDesc() {
	ordenarDesc();
	list<Apartamento>::iterator it;
	cout << "Listar Descendentemente" << endl;
	for (int i = n-1;i >= 0;i--) {
		cout << "Piso:" << (i + 1) << endl;
		for (it = apartamentos[i].begin(); it != apartamentos[i].end(); ++it) {
			std::cout << it->apto << "\t";
		}
		cout << endl;
	}

}
//lee el archivo de datos apartamentos.txt
void leerArchivo() {
	//abre el archivo
	std::fstream f("apartamentos.txt", std::ios_base::in);

	string in;
	//lee de a 6 lineas que representan un apartamento, cuando llega a la ultima linea no encuentra otro y finalixa
		//crea el apartamento
	f >> n;
	
	for (int i = 0;i < n;i++) {
		int apts, num;
		f >> apts;
		for (int j = 0;j < apts;j++) {
			Apartamento c;
			c.piso = i + 1;
			f >> c.apto;
			apartamentos[i].push_back(c);
		}
	}

}



//imprime el resument
void resumen() {
	cout << "Resumen" << endl;
	//variable para calcular el total
	int total = 0;
	for (int i = 0;i < n;i++) {
		cout << "Piso " << i + 1 <<" = " << apartamentos[i].size() <<endl;

		total += apartamentos[i].size();
	}
	cout << "total: " << total;

}
//imprime menu
void menu() {
	system("cls");
	cout << "1. Listar Ordenado del primer piso al ultimo " << endl;
	cout << "2. Listar Ordenado del ultimo al primero" << endl;
	cout << "3. Resumen Edificio" << endl;
	cout << "4. Salir" << endl;


}

//metodo principal
int main() {
	//lee el archivo
	leerArchivo();

	int opt;
	//por siempre...
	while (true) {
		//imprime menu
		menu();
		cout << "Digite opcion: ";
		cin >> opt;
		//dependiendo de la opcion ingresada se accede a uno de los siguientes casos, si el usuario digita una opcion invalida se termina el programa
		switch (opt)
		{
		case 1:
			ListarAsc();
			break;
		case 2:
			ListarDesc();
			break;
		case 3:
			resumen();
			break;
		default:
			exit(0);
			break;
		}
		cout << endl;
		system("pause");
	}
	system("pause");
	return 0;
}
