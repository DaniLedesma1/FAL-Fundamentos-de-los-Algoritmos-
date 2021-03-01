// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


int particion (std::vector<int> & v) {
    // Aqui codigo del estudiante

	std::sort(v.begin(), v.end());
	int contmax = 1, contactual = 1, acumMax, acum2;
	acumMax = v[0];
	acum2 = acumMax;

	for (int i = 1; i < v.size(); i++) {
		if (v[i] == acum2) {
			contactual++;
			if (contactual > contmax) {
				contmax = contactual;
				acumMax = acum2;
			}
		}
		else {
			contactual = 1;
			acum2 = v[i];
		}
	}
	return acumMax;
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numAccidentes;
    std::cin >> numAccidentes;
    if (numAccidentes == -1) return false;
    std::vector<int> v(numAccidentes); // nombre y altura
    for (int & n : v) {
        std::cin  >> n;
    }
    // LLamada a la función paticion
    int p;
	p = particion(v);
	std::cout << p;
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("13sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso()) {} //Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
