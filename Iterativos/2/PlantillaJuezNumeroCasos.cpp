// Daniel Ledesma Ventura
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool resolver(const vector<int> &d, int pos);
void resuelveCaso();
int main();

// función que resuelve el problema
bool resolver(const vector<int> &d, int pos) {
	int max = d[0];
	bool bien = true;
	long unsigned int j = 1;
	int i = 1;
	
	while (bien && j < d.size()) {
		if (d[i] > max && i <= pos) {
			max = d[i];
		}
		else {
			if (i > pos && d[i] <= max) {				
				bien = false;
			}
		}
		i++;
		j++;
	}
	return bien;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int num, pos, aux;
	std::cin >> num >> pos;
	vector<int> datos(num);
	for (int i = 0; i < num; i++) {
		std::cin >> aux;
		datos[i] = aux;
	}
	
	if (pos == num - 1) {
		std::cout << "SI" << endl;
	}
	else {
		bool sol = resolver(datos, pos);

		if (sol) {
			std::cout << "SI" << endl;
		}
		else {
			std::cout << "NO" << endl;
		}
	}
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
     #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}