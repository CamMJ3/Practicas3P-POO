#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

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
    cout << "chanclas";
}

//////////////////////////////////////////////////////////////

int main()
{
    vector<string> deberes = 
    {
        "Lavar los trastes", "Trapear el suelo",
        "Alimentar a mis perros", "Acomodar la cama",
        "Limpiar la cocina"
    };
}