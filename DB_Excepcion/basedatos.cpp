#include <windows.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdexcept>

using namespace std;

class Consultas
{
    private:
        sqlite3* db;
    public:
        Consultas(const string& ruta)
        {
            db = nullptr;
            int conexion = sqlite3_open(ruta.c_str(), &db);

            if (conexion != SQLITE_OK)
            {
                string mensaje = db ? sqlite3_errmsg(db) : "No es posible abrir la base de datos.";

                if (db != nullptr)
                {
                    sqlite3_close(db);
                    db = nullptr;
                }

                throw runtime_error("ERROR: " + mensaje);
            }

            cout << "\n--> Conexión EXITOSA.";
        }
};