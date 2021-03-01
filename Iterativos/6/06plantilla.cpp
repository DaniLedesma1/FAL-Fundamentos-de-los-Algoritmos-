
// Nombre y apellidos del estudiante
// Usuario del juez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


using lli = long long int;
// Calcula un vector con los valores acumulados
// Recibe un vector a con los datos de entrada
// Devuelve en un vector diferente v los datos de entrada acumulados
// Postcondicion de la función para todo i: 0 <= i < v.size(): v[i] = Sum k : 0 <= k <= i: a[i]
void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
   // Aqui codigo del estudiante
	v.push_back(a[0]);
	for (int i = 1; i < a.size(); i++) {
		v.push_back(v[i-1] + a[i]);
	}

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
	std::vector<lli> v;
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos en un vector
	std::vector<int> v1((a2 - a1) + 1);
	for (int& i : v1) std::cin >> i;
    // Aqui código del estudiante
    
    // calcula el vector de acumulados llamando a la funcion resolver
	resolver(v1, v);
    // Aqui código del estudiante

    // Lectura de las preguntas
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        // Escribir la respuesta
        
        // Aqui codigo del estudiante
		if (f1 - a1 == 0) {
			std::cout << v[f2- a1] << endl;
		}
		else {
			std::cout << v[f2 - a1] - v[(f1 - a1)-1] << endl;
		}
    }
    std::cout << "---\n";

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    
#ifndef DOMJUDGE
    std::ifstream in("06sample.in");
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



