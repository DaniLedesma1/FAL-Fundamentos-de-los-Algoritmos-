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

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema


int resolver(const std::vector<int>&datos, const std::vector<int> &datos2, int ini, int fin) {
	int medio = (ini + fin) / 2;
	if (ini == fin)
	{
		return datos[ini];
	}
	else
	{
		if (datos[medio] != datos2[medio]) return resolver(datos, datos2, ini, medio);
		else return resolver(datos, datos2, medio + 1, fin);
	}

}

// Tratar cada caso
void resuelveCaso() {
    int numA, sol;
    // lectura del vector A
    std::cin >> numA;
    std::vector<int> a(numA);
    for (int i = 0; i < numA; ++i)
        std::cin >> a[i];
    // lectura del vector B
    std::vector<int> b(numA-1);
    for (int j = 0; j < numA - 1; ++j)
        std::cin >> b[j];
    // resolver
	if (numA == 1) 	sol = a[0];	
	else if (a[0] != b[0]) 	sol = a[0];	
	else if (a[a.size() - 1] != b[b.size() - 1]) sol = a[a.size() - 1];
	else sol = resolver(a, b, 0, a.size() -1);
	
    // mostrar resultado
    std::cout << sol << '\n';
    
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("32sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i)
        resuelveCaso();
    
    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
