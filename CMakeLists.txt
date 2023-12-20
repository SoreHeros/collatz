cmake_minimum_required(VERSION 3.26)
project(3n_1)

set(CMAKE_CXX_STANDARD 17)

# Agregar los archivos fuente a la variable sources
set(SOURCES ABB.c)

# Agregar el archivo de encabezado a la variable headers
set(HEADERS ABB.h ABB.c)

# Ejecutable nombre heros con los fuente y cabezeras
add_executable(3n_1 main.c ${SOURCES} ${HEADERS})
