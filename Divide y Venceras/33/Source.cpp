//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema


void mergesort(std::vector <int> & v, int ini, int fin) {
	if (ini + 1 < fin) { // Vector de mas de un elemento
		int mitad = (ini + fin) / 2;
		// Ordena cada parte
		mergesort(v, ini, mitad);
		mergesort(v, mitad, fin);
		// mezcla
		std::inplace_merge(v.begin() + ini, v.begin() + mitad, v.begin() + fin);
	}
}



// Tratar cada caso
bool resuelveCaso() {
	int tam;

	
	std::cin >> tam;
	if (!std::cin)
		return false;
	

	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	// resolver
	if (tam == 1) 	std::cout << v[0] << '\n';
	else {
		mergesort(v, 0, v.size()); //Ordeno el vector
		std::cout << v[0] << '\n';
	}
	// mostrar resultado
	
	return true;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("33sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
		

	// Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}