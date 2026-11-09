#include <bits/stdc++.h>
using namespace std;

void ejercicio1() {
    array<int, 20> grupo;
    int menores20[] = {1, 3, 5, 7, 9};
    int mayores20[] = {21, 23, 25, 27, 29};
    int medio[] = {11, 13, 15, 17, 19, 31, 33, 35, 37, 39};

    for (int i = 0; i < 5; i++) grupo[i] = mayores20[i];
    for (int i = 0; i < 10; i++) grupo[i + 5] = medio[i];
    for (int i = 0; i < 5; i++) grupo[i + 15] = menores20[i];

    cout << "a. Todos los elementos:" << endl;
    for (int x : grupo) cout << x << " ";
    cout << endl;

    cout << "b. Mayores de 20 y menores que 50:" << endl;
    for (int x : grupo) if (x > 20 && x < 50) cout << x << " ";
    cout << endl;

    sort(grupo.begin(), grupo.end());
    cout << "c. Ordenados:" << endl;
    for (int x : grupo) cout << x << " ";
    cout << endl;

    cout << "d. Indices impares con valor menor a 10:" << endl;
    for (int i = 1; i < 20; i += 2) if (grupo[i] < 10) cout << grupo[i] << " ";
    cout << endl;
}

void ejercicio2() {
    vector<string> paises = {"Argentina", "Bolivia", "Brasil", "Chile", "Colombia",
                             "Ecuador", "Paraguay", "Peru", "Uruguay", "Venezuela"};
    
    paises.at(0) = "Argentina";
    paises[1] = "Bolivia";
    paises.push_back("Guyana");
    paises.push_back("Surinam");

    cout << "b. Paises que inician con C o P:" << endl;
    for (const string& p : paises) {
        if (p[0] == 'C' || p[0] == 'P') cout << p << " ";
    }
    cout << endl;

    cout << "c. Primer y ultimo elemento:" << endl;
    cout << paises.front() << " - " << paises.back() << endl;

    sort(paises.begin(), paises.end());
    cout << "d. Paises ordenados:" << endl;
    for (const string& p : paises) cout << p << " ";
    cout << endl;
}

struct Estudiante {
    string nombre;
    int anioNacimiento;
    double gpa;
};

void ejercicio3() {
    vector<Estudiante> estudiantes;
    estudiantes.push_back({"Juan", 2000, 3.4});
    estudiantes.push_back({"Maria", 2005, 2.8});

    Estudiante e3, e4;
    cout << "Ingrese nombre, anio y gpa del estudiante 3: ";
    cin >> e3.nombre >> e3.anioNacimiento >> e3.gpa;
    cout << "Ingrese nombre, anio y gpa del estudiante 4: ";
    cin >> e4.nombre >> e4.anioNacimiento >> e4.gpa;
    estudiantes.push_back(e3);
    estudiantes.push_back(e4);

    string nombres[] = {"Gaby", "Patty", "Diana"};
    int nacimientos[] = {2002, 2004, 2006};
    double gps[] = {3.8, 3.0, 2.9};
    for (int i = 0; i < 3; i++) {
        estudiantes.push_back({nombres[i], nacimientos[i], gps[i]});
    }

    ifstream archivo("datos.txt");
    string nom;
    int anio;
    double gpa;
    while (archivo >> nom >> anio >> gpa) {
        estudiantes.push_back({nom, anio, gpa});
    }
    archivo.close();

    cout << "d. Lista de estudiantes:" << endl;
    for (const Estudiante& e : estudiantes) {
        int edad = 2026 - e.anioNacimiento;
        cout << e.nombre << " - Edad: " << edad << " - GPA: " << e.gpa;
        if (e.gpa >= 3.5) cout << " - CALIFICA A BECA";
        cout << endl;
    }
}

int main() {
    cout << "EJERCICIO 1" << endl;
    ejercicio1();
    cout << "\n EJERCICIO 2" << endl;
    ejercicio2();
    cout << "\n EJERCICIO 3" << endl;
    ejercicio3();
    return 0;
}