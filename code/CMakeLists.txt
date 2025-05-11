cmake_minimum_required(VERSION 3.10)
project(RICE)

set(CMAKE_CXX_STANDARD 17)

# Ajout des sous-répertoires
add_subdirectory(src)
add_subdirectory(utils)

# Création de l'exécutable
add_executable(RICE main.cpp)

# Lier les bibliothèques (src et utils)
target_link_libraries(RICE src utils)
