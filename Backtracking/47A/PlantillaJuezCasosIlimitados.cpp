// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


std::string dev(int i) {
	if (i == 0) return "azul";
	else if (i == 1) return "rojo";
	else return "verde";
}


void tratarSol(std::vector<int> s) {
	for (int i = 0; i < s.size(); i++)
		std::cout << dev(s[i]) << " ";
	std::cout << endl;
}

// función que resuelve el problema
void resolver(int altura, int npiezas, int k, std::vector<int> &s) {
    
	for (int i = 0; i < npiezas; i++) {

		s[k] = i;
			
		if (k == (altura - 1)) {
			tratarSol(s);
		}
		else resolver(altura, npiezas, k + 1, s);

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura;
	int npiezas = 3;

	std::cin >> altura;
    if (altura == 0)
        return false;
    
	std::vector<int> s(altura);
    resolver(altura, npiezas, 0, s);
	std::cout << endl;
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("entrada.txt");
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