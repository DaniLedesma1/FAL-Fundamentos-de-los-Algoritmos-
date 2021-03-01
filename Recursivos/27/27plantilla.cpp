//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno 
// Daniel Ledesma Ventura
// Usuario del juez de clase
// A39
// Enlace: https://youtu.be/pJn3YpeOFlU
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef struct {
	int acumder = 0;
	bool cumple = true;
}tP;



tP resuelver(int n, int acumanterior) {
	if (n < 10) {
		if (((acumanterior % n) == 0) && n != 0) return{ n, true };
		else return { n, false };
	}
	else {
		
		if (n % 10 == 0) return { n, false };
		else {
			if ((acumanterior % (n % 10)) != 0) return { n, false };
			else {
				tP sol = resuelver(n / 10, acumanterior + n % 10);
				if (!sol.cumple || (sol.acumder % (n % 10)) != 0) return{ n,false };
				else {
					sol.acumder += n % 10;
					return{ sol.acumder, sol.cumple };
				}
			}
		}
	}
}




// Para lectura de datos y mostrar los resultados
void resuelveCaso() {
    // Lectura de datos
	int numero;
	std::cin >> numero;

	tP sol;
   
	sol = resuelver(numero, 0);
	if (sol.cumple) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
	//if (interesanteder && interesanteiz) std::cout << "SI" << std::endl;
	//else std::cout << "NO" << std::endl;
    
}



int main() {
   // Para redireccionar la entrada del juez
#ifndef DOMJUDGE
    std::ifstream in("27sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
 
    int numCasos; std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) 
        resuelveCaso();

   
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
