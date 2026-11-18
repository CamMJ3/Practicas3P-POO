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

json reporte(const json& ventas, const json& productos)
{
    if (productos.empty())
    {
        throw invalid_argument("No se han identificado productos.");
    }

    int total_semanal = 0;
    int unidades_total = 0;

    for (const auto& producto : productos)
    {
        total_semanal += producto["ganancia_total"].get<int>();
        unidades_total += producto["cantidad"].get<int>();
    }

    json mayor = mayorIngreso(productos);
    json menor = menorIngreso(productos);

    json reporte =
    {
        {"total_ventas", ventas.size()},
        {"unidades_total", unidades_total},
        {"total_semanal", total_semanal},
        {"producto_mas_ingreso", mayor},
        {"producto_menos_ingreso", menor},
        {"productos", productos}
    };

    return reporte;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try
    {
        json ventas = json::parse(R"({
            "ventas": [
               {"id": 1, "producto": "Vaso", "cantidad": 4, "precio_indiv": 800},
               {"id": 2, "producto": "Plato", "cantidad": 8, "precio_indiv": 500},
               {"id": 3, "producto": "Frigobar", "cantidad": 1, "precio_indiv": 3900},
               {"id": 4, "producto": "Licuadora", "cantidad": 2, "precio_indiv": 1000},
               {"id": 5, "producto": "Bocina", "cantidad": 1, "precio_indiv": 3000},
               {"id": 6, "producto": "Aspiradora", "cantidad": 1, "precio_indiv": 4500}
            ]})");

        json info = ventas["ventas"];
        json productos = calcIngresos(info);
        json reporte_semanal = reporte(info, productos);

        cout << "--> Reporte SEMANAL de VENTAS en formato JSON.\n\n";
        cout << reporte_semanal.dump(4) << endl;

        cout <<  "--> Reporte SEMANAL de VENTAS en formato legible.\n\n";
        cout << "Total de ventas = " << reporte_semanal["total_ventas"] << endl;
        cout << "Total de unidades vendidas = " << reporte_semanal["unidades_total"] << endl;
        cout << "Ganancia total = " << reporte_semanal["total_semanal"] << endl;
        cout << "Producto con mayor ingreso = " << reporte_semanal["producto_mas_ingreso"]["nombre"].get<string>() << endl;
        cout << "Producto con menor ingreso = " << reporte_semanal["producto_menos_ingreso"]["nombre"].get<string>() << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}