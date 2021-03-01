// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


std::vector<int> particion (std::vector<int> & v, int longi, int &numLlanos, int &sec) {
    // Aqui codigo del estudiante
	std::vector<int> v2;
	int longMax= 0, contlong = 1;
	int mov =  v[v.size() - 1];
	int maxvalue = -1;

	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] == mov) {
			if (v[i] > maxvalue) {
				contlong++;
				if (contlong >= longi) {
					if (longMax < contlong) {
						longMax = contlong;
					}
				}
			}	
		}
		else {
			if (contlong >= longi && mov > maxvalue) {
				numLlanos++;
				v2.push_back(i+contlong);
				maxvalue = mov;
			}
			if (mov > maxvalue) {
				maxvalue = mov;
			}
			contlong = 1;
			mov = v[i];
		}
	}
	if (contlong >= longi && mov > maxvalue) {
		numLlanos++;
		v2.push_back(contlong - 1);
	}
	sec = longMax; 
	return v2;
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numArboles, longi;
    std::cin >> numArboles;
    if (!std::cin) return false;
	std::cin >> longi;
    std::vector<int> v(numArboles), v2; // nombre y altura
    for (int & n : v) {
        std::cin  >> n;
    }
    // LLamada a la función paticion
    int numLlanos = 0, sec = 0;
	v2 = particion(v, longi, numLlanos, sec);
	std::cout << sec << " " << numLlanos;
	for (int i = 0; i < v2.size(); i++) {
		std::cout << " " << v2[i];
	}
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("14sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso()) {} //Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
