
// Daniel Ledesma Ventura
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado
/*
Uso un contador y una variable que almacena el valor maximo en cada momento, si aparece un numero mayor se cambia por el y se reestablece 
el contador a 1, sino, si son iguales se aumenta el contador
*/
// Coste del algoritmo utilizado
/*
Coste lineal de orden n O(n) dependiente del numero de elementos en cada caso
Bucle while recorrido nveces, tantas como elementos halla
*/

// Funcion que lee de la entrada, resuelve el problema y escribe la salida
bool resuelveCaso() {
    int n;
    std::cin >> n;
    // Declaración de variables
    // Codigo del alumno
	int max = n;
	int cont = 0;
    
    while (n != 0) {
        
        // Aqui codigo del alumno
		if (max < n) {
			max = n;
			cont = 1;
		}
		else {
			if (max == n) {
				cont++;
			}
			
		}
        
        std::cin >> n;
    }
    
    // Escribir el resultado
	std::cout << max << " " << cont << std::endl;
    // Codigo del alumno
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
  
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
