#include <windows.h>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

json calcIngresos(const json& ventas);
json menorIngreso(const json& productos);
json mayorIngreso(const json& productos);
json reporte(const json& ventas, const json& productos);
