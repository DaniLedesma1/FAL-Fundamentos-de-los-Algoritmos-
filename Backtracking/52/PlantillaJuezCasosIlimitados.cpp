// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;



// función que resuelve el problema
void resolver(int funcionarios, std::vector < std::vector <int>> trabajo, int k, std::vector<bool> &asignados, std::vector<int> &s, std::vector <int> &solf, int &costeactual, int &costemejor) {
    
	for (int i = 0; i < funcionarios; i++) {
	
		s[k] = i;
		if (!asignados[i]) {//Es valido
			asignados[i] = true;
			costeactual += trabajo[k][i];
			if (k == funcionarios - 1) { //Es sol
				if (costeactual < costemejor) { //Es sol mejor
					costemejor = costeactual;
					solf = s;
				}
			}
			else {
				resolver(funcionarios, trabajo, k+1, asignados, s, solf, costeactual, costemejor);
			}
			asignados[i] = false;
			costeactual -= trabajo[k][i];
		}
		
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
	// leer los datos de la entrada
	int funcionarios;
	int coste = 0, costemejor = 0;

	std::cin >> funcionarios;
    if (funcionarios == 0)
        return false;
	
	std::vector < std::vector <int>> trabajo;

	for (int i = 0; i < funcionarios; ++i) {
		std::vector <int > aux(funcionarios);
		for (int j = 0; j < funcionarios; ++j) {
			std::cin >> aux[j]; costemejor += aux[j];
		}
		trabajo.push_back(aux);
	}


	std::vector <int> s(funcionarios);
	std::vector <int> solf(funcionarios);
	std::vector <bool> asignados(funcionarios);


	resolver(funcionarios, trabajo, 0, asignados, s, solf, coste, costemejor);

	std::cout << costemejor << endl;
    
    
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