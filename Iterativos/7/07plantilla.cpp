
// Nombre y apellidos del estudiante
// Usuario del juez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include <iomanip>
#include <algorithm>
using namespace std;

using lli = long long int;
// Calcula un vector con los valores acumulados
// Recibe un vector a con los datos de entrada
// Devuelve en un vector diferente v los datos de entrada acumulados
// Postcondicion de la función para todo i: 0 <= i < v.size(): v[i] = Sum k : 0 <= k <= i: a[i]
std::vector<lli> resolver(std::vector<lli> const& v1, std::vector<lli> const& v2)
{
	std::vector<lli> sol;
	int i = 0, j = 0; 
   // Aqui codigo del estudiante
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] > v2[j]) {
			j++;
		}
		else if (v1[i] < v2[j]) {
			i++;
		}
		else {
			sol.push_back(v1[i]);
			i++;
			j++;
		}
	}
	return sol;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
	std::vector<lli> v1, v2;
	std::vector<lli> sol;
	lli v;
    // Lee el resto de los datos en un vector
	std::cin >> v;
	while (v != 0) {
		v1.push_back(v);
		std::cin >> v;
	}

	std::cin >> v;
	while (v != 0) {
		v2.push_back(v);
		std::cin >> v;
	}
    // Aqui código del estudiante
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
    // calcula los coincidentes
	sol = resolver(v1, v2);
	for (int i = 0; i < sol.size(); i++) {
		std::cout << sol[i] << " ";
	}
	std::cout << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    
#ifndef DOMJUDGE
    std::ifstream in("07sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}
    
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



