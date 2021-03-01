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



// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores){
   // Aqui codigo del estudiante
	std::vector<int> c(maximoValores, 0);
	std::vector<int> sol;
	int max = 0;

	for (int i = 0; i < v.size(); i++) {
		c[v[i]-1]++;
	}
	
	for (int j = 0; j < c.size(); j++) {
		if (c[j] > max) {
			max = c[j];
		}
	}
    
	for (int k = c.size()-1; k >= 0; k--) {
		if (c[k] == max) {
			sol.push_back(k+1);
		}
	}
    

	return sol;
    
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
	std::vector<int> sol;
    for (int& i : v) std::cin >> i;
	
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces

                // Codigo
	sol = resolver(v, valorMax);
    // Escribir los valores del vector que ha calculado resolver

                // Codigo
	for (int i = 0; i < sol.size(); i++) {
		std::cout << sol[i] << " ";
	}
	std::cout << endl;
    return true;
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("08sample.in");
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

