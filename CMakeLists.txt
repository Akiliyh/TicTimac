cmake_minimum_required(VERSION 3.11)  # Make sure you have at least version 3.11

# La version du C++ que l'on souhaite utiliser (C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(TicTacToe)

# Réglage du compilateur pour les warnings
if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# On souhaite placer l'exécutable dans un sous-dossier "bin"
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Obtenir la liste des fichiers sources dans le dossier src
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

# Optionnel : afficher la liste des fichiers sources
message(STATUS "Found source files:")
foreach(SRC_FILE ${SRC_FILES})
    message(STATUS " - ${SRC_FILE}")
endforeach()

# Ajouter la bibliothèque FetchContent
include(FetchContent)

# Déclarer et télécharger terminal_ctrl via Git
FetchContent_Declare(
    terminal_ctrl
    GIT_REPOSITORY https://github.com/dsmtE/terminal_ctrl
    GIT_TAG "origin/main"
)

# Activer la bibliothèque terminal_ctrl
FetchContent_MakeAvailable(terminal_ctrl)

# On indique que l'on souhaite faire un exécutable avec nos fichiers sources
add_executable(TicTacToe ${SRC_FILES})

# Lier la bibliothèque terminal_ctrl à notre projet
target_link_libraries(TicTacToe PUBLIC terminal_ctrl)

# Optionnel : ajouter les répertoires d'inclusion de terminal_ctrl
target_include_directories(TicTacToe PUBLIC ${terminal_ctrl_SOURCE_DIR}/include)
