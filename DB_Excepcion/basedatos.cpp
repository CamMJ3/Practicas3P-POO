#include <windows.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdexcept>


// IMPORTANTE : El presente archivo pertenece al problema 3 y 5.

/** 
 * @file 
 * @brief Implementación de la libreria "stdexcept" para manejar excepciones, y la libreria "sqlite3.h" para las operaciones de conectividad con la base de datos SQLite.
 */


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

            cout << "\n--> Conexión EXITOSA.\n";
        }

        ~ConsultasDAO()
        {
            if (db != nullptr)
            {
                sqlite3_close(db);
                cout << "\n--> Conexión CERRADA.\n";

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
            cout << "\n--> Se ha CREADO la tabla.\n";
        }

        void insertar(const string& nombre, double precio, int cantidad)
        {
            string sql = R"(
            INSERT OR IGNORE INTO productos (nombre, precio, cantidad)
            VALUES(?, ?, ?);
            )";

            sqlite3_stmt* instruccion = nullptr;
            int ejecucion = sqlite3_prepare_v2(db, sql.c_str(), -1, &instruccion, nullptr);

            if (ejecucion != SQLITE_OK)
            {
                throw runtime_error("ERROR al preparar consulta: " + string(sqlite3_errmsg(db)));
            }

            sqlite3_bind_text(instruccion, 1, nombre.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_double(instruccion, 2, precio);
            sqlite3_bind_int(instruccion, 3, cantidad);

            ejecucion = sqlite3_step(instruccion);
            string mensaje = sqlite3_errmsg(db);
            sqlite3_finalize(instruccion);

            if (ejecucion != SQLITE_DONE)
            {
                throw runtime_error("ERROR al insertar: " + mensaje);
            }

            cout << "\n--> Producto " << nombre << " insertado exitosamente.\n";
        }

        void consultar()
        {
            string sql = R"(
            SELECT *
            FROM productos;
            )";

            sqlite3_stmt* instruccion = nullptr;

            int ejecucion = sqlite3_prepare_v2(db, sql.c_str(), -1, &instruccion, nullptr);

            if (ejecucion != SQLITE_OK)
            {
                throw runtime_error("ERROR al preparar consulta: " + string(sqlite3_errmsg(db)));
            }

            cout << "\n---- PRODUCTOS ----\n\n";
            while((ejecucion = sqlite3_step(instruccion)) == SQLITE_ROW)
            {
                int id = sqlite3_column_int(instruccion, 0);
                const unsigned char* nombre = sqlite3_column_text(instruccion, 1);
                double precio = sqlite3_column_double(instruccion, 2);
                int cantidad = sqlite3_column_int(instruccion, 3);

                string text_nombre = nombre ? reinterpret_cast<const char*>(nombre) : "";
                cout << "--> ID: " << id << endl;
                cout << "--> Nombre: " << text_nombre << endl;
                cout << "--> Precio: " << precio << endl;
                cout << "--> Cantidad: " << cantidad << "\n\n";
            }

            string mensaje = sqlite3_errmsg(db);
            sqlite3_finalize(instruccion);

            if (ejecucion != SQLITE_DONE)
            {
                throw runtime_error("ERROR al consultar: " + mensaje);
            }
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    try
    {
        ConsultasDAO base("tienda.db");
        base.crearTabla();

        base.insertar("Lavadora", 5000.00, 1);
        base.insertar("Refrigerador", 25500.00, 2);
        base.insertar("Trapeador", 100.00, 4);

        base.consultar();

        ConsultasDAO base2("Z:/ruta_inexistente/tienda.db");
    }
    catch (const exception& e)
    {
        cerr << e.what() << '\n';
    }
}