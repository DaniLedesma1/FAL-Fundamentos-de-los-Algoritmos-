// Daniel Ledesma Ventura
// A39


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

// función que resuelve el problema
int resolver2(lli n, int cont){
	if (n <= 9) {
		cont++;
		return cont;
	}
	else {
		return resolver2(n / 10, cont+1);
	}
}
/*
int resolver(lli n) {
	int cont = 0;
	if (n <= 9) {
		cont++;
		return cont;
	}
	else {
		return cont = 1 + resolver(n / 10);
	}
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	lli n;

	std::cin >> n;

    if (! std::cin)
        return false;
	

	int sol = resolver2(n,0);
	//int sol2 = resolver2(n, 0);
    // escribir sol
	std::cout << sol << std::endl;
	//std::cout << "---------------------------" << std::endl;
	//std::cout << sol2 << std::endl;
	//std::cout << "---------------------------" << std::endl;
 
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}