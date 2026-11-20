#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

// IMPORTANTE : El presente archivo pertenece al problema 2.

/** 
 * @file 
 * @brief Implementación de la libreria "fstream" para guardar y leer la lista de deberes en pendientes.txt, la libreria "vector" para
 * almacenar la lista de deberes, y la libreria "stdexcept" para manejar excepciones.
 */


using namespace std;

void guardarTareas(const vector<string>& deberes)
{
    ofstream archivo("pendientes.txt");

    if (!archivo.is_open())
    {
        throw runtime_error("No se creó el archivo 'pendientes.txt'.");
    }

    for (const string& tarea : deberes)
    {
        archivo << tarea << "\n";
    }

    archivo.close();
}

void leerTareas()
{
    ifstream archivo("pendientes.txt");

    if (!archivo.is_open())
    {
        throw runtime_error("No se ha creado el archivo.");
    }

    string tarea;
    while (getline(archivo, tarea))
    {
        cout << "--> " << tarea << "\n";
    }

    archivo.close();

}

//////////////////////////////////////////////////////////////

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    vector<string> deberes = 
    {
        "Lavar los trastes", "Trapear el suelo",
        "Alimentar a mis perros", "Acomodar la cama",
        "Limpiar la cocina"
    };

    try
    {
        cout << "_-_- Guardando deberes...\n";
        guardarTareas(deberes);
        cout << "\n¡Se logró guardar la lista!\n\n";

        cout << "_-_- Leyendo deberes...\n\n";
        leerTareas();
        cout << "\n¡Se logró leer la lista!";

    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}