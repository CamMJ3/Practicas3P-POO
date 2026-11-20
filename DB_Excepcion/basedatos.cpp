#include <windows.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdexcept>

using namespace std;

class ConsultasDAO
{
    private:
        sqlite3* db;
    public:
        ConsultasDAO(const string& ruta)
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

        ~ConsultasDAO()
        {
            if (db != nullptr)
            {
                sqlite3_close(db);
                cout << "\n--> Conexión CERRADA.";

            }
        }

        ConsultasDAO(const ConsultasDAO&) = delete;
        ConsultasDAO& operator=(const ConsultasDAO&) = delete;

        void ejecutar(const string& sql)
        {
            char* mensaje = nullptr;
            int ejecucion = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mensaje);

            if (ejecucion != SQLITE_OK)
            {
                string mesg_error = mensaje ? mensaje : sqlite3_errmsg(db);
                sqlite3_free(mensaje);

                throw runtime_error("ERROR: " + mesg_error);
            }
        }

        void crearTabla()
        {
            string tabla = R"(
            CREATE TABLE IF NOT EXISTS productos (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nombre TEXT NOT NULL UNIQUE,
            precio REAL NOT NULL,
            cantidad INTEGER NOT NULL );
            )";

            ejecutar(tabla);
            cout << "--> Se ha creado la tabla.";
        }
};