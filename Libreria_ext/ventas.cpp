#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

json calcIngresos(const json& ventas)
{
    json productos = json::array();

    for(const auto& venta : ventas)
    {
        string nombre = venta["producto"];
        int cantidad = venta["cantidad"];
        int precio = venta["precio_indiv"];

        int ganancia_total = cantidad * precio;

        productos.push_back({
            {"nombre", nombre},
            {"cantidad", cantidad},
            {"ganancia_total", ganancia_total}
        });
    }

    return productos;
}

json menorIngreso(const json& productos)
{
    if (productos.empty())
    {
        throw invalid_argument("No se han identificado productos.");
    }

    json menor = productos[0];
    for (const auto& producto : productos)
    {
        if (producto["ganancia_total"] < menor["ganancia_total"])
        {
            menor = producto;
        }
    }

    return menor;
}

json mayorIngreso(const json& productos)
{
    if (productos.empty())
    {
        throw invalid_argument("No se han identificado productos.");
    }

    json mayor = productos[0];
    for (const auto& producto : productos)
    {
        if (producto["ganancia_total"] > mayor["ganancia_total"])
        {
            mayor = producto;
        }
    }

    return mayor;
}

json reporte(const json& ventas, const json& productos);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    vector<json> ventas = json::parse(R"({
        ventas = [
           {"id": 1, "producto": "Vaso", "cantidad": 4, "precio_indiv": 800"},
           {"id": 2, "producto": "Plato", "cantidad": 8, "precio_indiv": 500"},
           {"id": 3, "producto": "Frigobar", "cantidad": 1, "precio_indiv": 3900"},
           {"id": 4, "producto": "Licuadora", "cantidad": 2, "precio_indiv": 1000"},
           {"id": 5, "producto": "Bocina", "cantidad": 1, "precio_indiv": 3000"},
           {"id": 6, "producto": "Aspiradora", "cantidad": 1, "precio_indiv": 4500"},
        ]
        })");
}