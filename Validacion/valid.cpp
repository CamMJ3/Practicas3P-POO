#include <windows.h>
#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>

using namespace std;

int validarEdad(const string& num)
{
    try
    {
        size_t pos;
        int edad = stoi(num, &pos);
    
        if (pos != num.length())
        {
            throw invalid_argument("La edad debe contener únicamente números.");
        }
    
        if (edad < 6 || edad > 100)
        {
            throw out_of_range("Su edad está fuera del rango (6 a 100 años).");
        }

        return edad;
    }
    catch(const invalid_argument& e)
    {
        throw invalid_argument("Su edad no contiene números.");
    }
}

void validarCorreo(const string& correo)
{
    regex patron(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");

    if (!regex_match(correo, patron))
    {
        throw invalid_argument("Su correo no es válido.");
    }
}

//////////////////////////////////////////////////////////////

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    string nueva_edad;
    string nuevo_correo;

    cout << "---> Validación de EDAD y CORREO.\n\n";

    try
    {
        cout << "Tu edad es : ";
        getline(cin, nueva_edad);
        int edad = validarEdad(nueva_edad);

        cout << "Tu correo es : ";
        getline(cin, nuevo_correo);
        validarCorreo(nuevo_correo);

        cout << "\n¡Validación exitosa!\n--> Edad :" << edad << endl;
        cout << "--> Correo : " << nuevo_correo << endl;

    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}