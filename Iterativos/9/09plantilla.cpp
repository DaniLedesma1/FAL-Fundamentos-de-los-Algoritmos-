// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado

int resuelve( std::vector<int> const& v, int &pos, int longTela) {
	
	int cont = 0, cont2 = 0;

	for (int k = 0; k < longTela; k++) {
		if (v[k] == 0) {
			cont++;
		}
	}
	cont2 = cont;
	for (int j = longTela; j < v.size(); j++) {
		if (v[j - longTela] == 0) {
			cont2--;
		}
		if (v[j] == 0) {
			cont2++;
		}
		if (cont2 >= cont) {
			pos = j - longTela + 1;
			cont = cont2;
		}
	}
	return cont;
}

// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	int longValla, longTela;
	int p, pos = 0, contsol;
	std::cin >> longValla >> longTela;
	if (!std::cin) return false;

	std::vector<int> v(longValla);

	for (int i = 0; i < longValla; i++) {
		std::cin >> p;
		v[i] = p;
	}

	contsol  = resuelve(v, pos, longTela);
	


	if (contsol == 0) {
		std::cout << "No hace falta" << endl;
	}
	else {
		std::cout << pos << endl;
	}

	return true;
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("09sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif
    
    while (resuelveCaso()) 
        ;
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

