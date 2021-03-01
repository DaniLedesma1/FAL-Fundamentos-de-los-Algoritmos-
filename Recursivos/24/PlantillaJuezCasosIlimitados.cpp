// Daniel Ledesma Ventura
// A39


#include <iostream>
#include <iomanip>
#include <fstream>


using lli = long long int;

// función que resuelve el problema
/*int resolver2(lli n){
	if (n <= 9) {
		if (n % 2 == 0) {
			return 0 ;
		}
		else {
			return n % 10;
		}
	}
	else {
		if (n % 2 == 0) {
			return resolver2(n / 10);
		}
		else {
			return resolver2(n / 10)*10 + (n % 10);
		}
		
	}
}*/

lli resolver(lli n, lli sol, lli pot) {
	if (n <= 9) {
		if (n % 2 == 0) {
			return sol;
		}
		else {
			return sol + ((n%10) * pot);
		}
	}
	else {
		if (n % 2 == 0) {
			return resolver(n / 10, sol, pot);
		}
		else {
			sol += (n % 10)*pot;
			return resolver(n / 10, sol, pot*10) ;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	lli n;

	std::cin >> n;

    if (! std::cin)
        return false;
	

	//int sol = resolver2(n);
	lli sol2 = resolver(n, 0, 1);
	// escribir sol
	std::cout << sol2 << std::endl;
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