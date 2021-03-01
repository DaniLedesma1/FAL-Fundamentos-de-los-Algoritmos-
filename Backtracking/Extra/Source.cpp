//Daniel Ledesma Ventura
// https://youtu.be/r-Px2iXjtDs

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// si las personas actuales superan al maximo de personas tenemos nueva solucion
// si las personas actuales son iguales al maximo de personas y el indicador  actual de poblacion infantil
// supera al indicador maximo tenemos nueva solucion
void tratarSol(int pactual, int &pmaximo, int iactual, int &imaximo, std::vector<bool> sol, std::vector<bool> &solf) {

	if (pactual > pmaximo) {
		pmaximo = pactual;
		imaximo = iactual;
		solf = sol;
	}
	else if (pactual == pmaximo && iactual > imaximo) {
		pmaximo = pactual;
		imaximo = iactual;
		solf = sol;
	}
}

// estimamos si hay una solucion mejor si las personas que quedan por ver mas las actuales es mayor el maximo actual de personas
bool estimacion(int pactual, int pmaximo, std::vector<int> p) {
	int acumulado = 0;

	for (int i = 0; i < p.size(); i++) acumulado += p[i];

	if ((pactual + acumulado) >= pmaximo) return true;
	else return false;
}



void combinacionsinrep(int presMax, std::vector<int> c, std::vector<int> p, std::vector<bool> ind, int k, std::vector<bool> s, std::vector<bool> &sfinal, int cactual, int pactual, int &pmaximo, int iactual, int &imaximo) {
	
	// Cogemos el parque
	s[k] = true;
	pactual += p[k];
	cactual += c[k];
	if (ind[k]) iactual += 1;

	if (cactual <= presMax) { // Si es valida
		if (k == s.size() - 1) { // Es solucion
			//Tratamiento de una posible solucion
			tratarSol(pactual, pmaximo, iactual, imaximo, s, sfinal);
		}
		else {
			combinacionsinrep(presMax, c, p, ind, k + 1, s, sfinal, cactual, pactual, pmaximo, iactual, imaximo);
		}
	}

	pactual -= p[k];			// Recupera el valor
	cactual -= c[k];			// Recupera el valor
	if (ind[k]) iactual -= 1;   // Recupera el valor
	s[k] = false;				// No cogemos el parque
	
	// Siempre es valido
	if (k == s.size() - 1) { // Es solucion
		//Tratamiento de una posible solucion
		tratarSol(pactual, pmaximo, iactual, imaximo, s, sfinal);
	}
	else {
		if (estimacion(pactual, pmaximo, p)) 
			combinacionsinrep(presMax, c, p, ind, k + 1, s, sfinal, cactual, pactual, pmaximo, iactual, imaximo);
		
	}
}



// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	int presMax, nparques;
	int personasmax = 0, indicadormax = 0;
	char ind;

	std::cin >> nparques;
	if (!std::cin) return false;
	std::cin >> presMax;
	
	std::vector<int> coste(nparques);
	std::vector<int> personas(nparques);
	std::vector<bool> indicador(nparques);
	// Lectura de los datos de entrada

	//Lectura de costes
	for (int i = 0; i < nparques; i++) {
		std::cin >> coste[i];
	}

	//Lectura de personas por parque
	for (int i = 0; i < nparques; i++) {
		std::cin >> personas[i];
	}

	//Lectura de indicador de poblacion infantil
	for (int i = 0; i < nparques; i++) {
		std::cin >> ind;
		if (ind == 's') indicador[i] = true;
		else indicador[i] = false;
	}
	
	// Generar las soluciones
	std::vector <bool> s(nparques);
	std::vector <bool> solfinal(nparques);

	//presupuestoMaximo, vector coste, vector personas, vector indicador, etapa, vector solactual, vector solfinal, 
	//coste actual, personas actuales, personas maximas, nº poblaciones infantiles actuales, nº poblaciones infantiles actuales maximas
	combinacionsinrep(presMax, coste, personas, indicador, 0, s, solfinal, 0, 0, personasmax, 0, indicadormax);
	
	std::cout << "Listado de parques a limpiar: ";
	for (int i = 0; i < nparques; i++) {
		if (solfinal[i]) std::cout << i+1 << " ";
	}
	std::cout << endl;
	return true;
}



int main() {
# ifndef DOMJUDGE
	std::ifstream in("prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}