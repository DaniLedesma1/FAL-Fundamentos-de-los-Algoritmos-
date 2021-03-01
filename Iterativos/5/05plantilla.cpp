// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


std::vector<long int> resolver(std::vector<long int>const& v1, int inicio) {
    // Declaración de variables
	std::vector<long int> sol;
	int i = 1, max = v1[0];

    // Codigo del alumno  
	while (i < v1.size()) {

		// Aqui codigo del alumno
		if (v1[i] > max) {
			max = v1[i];
			sol.push_back(inicio +i);
			i++;
		}
		else {
			i++;
		}
	}
    return sol;
}


void resuelveCaso() {
    // Lectura de los datos de entrada
    int inicio, fin; 
    std::cin >> inicio >> fin;
    std::vector<long int> v1((fin-inicio)+1);
    for (long int& i : v1) std::cin >> i;
    // LLamada a la función que resuelve el problema
    std::vector<long int> sol = resolver(v1, inicio);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i) 
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
 #ifndef DOMJUDGE
    std::ifstream in("05sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
 #endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
