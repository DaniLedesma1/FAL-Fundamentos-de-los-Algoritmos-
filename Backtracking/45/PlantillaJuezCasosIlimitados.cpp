// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


void tratarSol(std::vector<char> s) {
	for (int i = 0; i < s.size(); i++)
		std::cout << s[i];
	std::cout << endl;
}

// función que resuelve el problema
void resolver(int nletras,  int tam, int k, std::vector<char> s) {
    
	for (char c = 'a'; c < 'a' + nletras; c++) {

		s[k] = c;
		if (k == (tam - 1)) {
			tratarSol(s);
		}
		else resolver(nletras, tam, k + 1, s);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nletras, tam;
	

	std::cin >> nletras;
    if (! std::cin)
        return false;
    
	std::cin >> tam;
	std::vector<char> s(tam);

    resolver(nletras, tam, 0, s);
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