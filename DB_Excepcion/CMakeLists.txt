add_executable(db_excepcion basedatos.cpp sqlite/sqlite3.c)

target_include_directories(db_excepcion PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sqlite)