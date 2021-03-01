// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool esValida(int i, std::vector<int> s, int k, std::vector<int> p) {

	if ((i == 2) && (s[k - 1] == 2)) return false;
	else if (p[2] > p[0]) return false;
	else return true;
}

bool haypiezas(int mazul, int mrojo, int mverde, std::vector<int> p, int i) {

	if (i == 0) {
		if (p[0] <= mazul) return true;		
		else return false;
	}
	else if (i == 1) {
		if (p[1] <= mrojo) return true;
		else return false;
	}
	else{
		if (p[2] <= mverde) return true;
		else return false;
	}
}


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
void resolver(int altura, int npiezas, int k, std::vector<int> &s, int mazul, int mrojo, int mverde, std::vector<int> &p, bool &sol) {
    
	for (int i = 0; i < npiezas; i++) {

		p[i] ++;

		if (haypiezas(mazul, mrojo, mverde, p, i)) {
			
			s[k] = i;

			if (esValida(i, s, k, p)) {

				if (k == (altura - 1)) {
					if (p[1] > (p[0] + p[2])) {
						sol = true;
						tratarSol(s);
					}
				}
				else resolver(altura, npiezas, k + 1, s, mazul, mrojo, mverde, p, sol);
			}
		}
		p[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura;
	int npiezas = 3;
	int azules, rojas, verdes;
	int a = 0, r = 1, v = 0;
	bool solucion = false;

	std::cin >> altura;
    if (altura == 0)
        return false;

	std::cin >> azules >> rojas >> verdes;
	std::vector<int> s(altura);
	s[0] = 1;
	std::vector<int> p(npiezas);
	p[1] = 1;

	if (altura == 1) tratarSol(s);
	else resolver(altura, npiezas, 1, s, azules, rojas, verdes, p, solucion);
	if (!solucion) std::cout << "SIN SOLUCION"<< endl;
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