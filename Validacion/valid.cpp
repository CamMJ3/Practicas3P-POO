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
        throw invalid_argument("Su edad no contiene números.")
    }
}

void validarCorreo(const string& correo)
{
    cout << "a";
}