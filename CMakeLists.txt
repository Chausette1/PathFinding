# CMakeLists.txt pour un projet C++ utilisant Raylib
cmake_minimum_required(VERSION 3.30)
project(PathFinding CXX)  # Spécifiez que c'est un projet C++

set(CMAKE_CXX_STANDARD 20)  # Utilisez C++ 20(ou une version plus récente si nécessaire)

# Inclure la commande pour télécharger des dépendances
include(FetchContent)

# Définir une fonction pour ajouter des dépendances depuis Git
function(include_dependency libName gitURL gitTag)
    # Configurer la déclaration
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )

    # Télécharger et rendre disponible la dépendance
    FetchContent_MakeAvailable(${libName})
endfunction()

# Ajouter le support de Raylib
set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Téléchargement de ${LIB1} depuis GitHub...")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.5)
else()
    message(STATUS "Utilisation de ${LIB1} installée localement")
endif()

# Ajouter l'exécutable du projet
add_executable(PathFinding main.cpp
        modele/Labyrinth.cpp
        modele/Labyrinth.h
        modele/case.cpp
        modele/case.h)  # Remplacez main.cpp par vos fichiers sources

# Configurer les répertoires d'inclusion
target_include_directories(PathFinding PRIVATE ${raylib_INCLUDE_DIRS})

# Lier les bibliothèques nécessaires
target_link_libraries(PathFinding PRIVATE ${LIB1})