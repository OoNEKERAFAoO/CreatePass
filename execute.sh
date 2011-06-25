#!/bin/bash
# Compile CreatePass 1.01 (Linux)
#
# Create by NEKERAFA on sat, 25 jun 2011 13:25:22 (CEST) 
# Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Spain 2011 NEKERAFA (nekerafa@gmail.com)
# http://creativecommons.org/licenses/by-nc-sa/3.0/es/legalcode.es

# Variables
VERSION=1.01

# Loading CreatePass
echo -e '\e[0;32mLoading CreatePass '$VERSION' (Linux)...'

# Detecting Language
if [ $LANG="es_ES.UTF-8" ]; then
	# Spanish
	echo 'Español...'
	lang="es"
else
	# English
	echo 'English...'
	lang="en"
fi

# Print language
echo -e '   '$LANG'\n'

# Compile CreatePass
if [ $lang="es" ]; then
	# Compiling spanish file
	echo 'Compilando...'
	echo -e '   gcc -Wall -o "CreatePass" "_'$lang'.c"\e[0m'
	gcc -Wall -o "CreatePass" "_$lang.c" || { echo -e '   \e[0;31mERROR: No se ha podido compilar CreatePass.\n   Error en _'$lang', ¿Existe el archivo?\e[0m\n'; exit 1; }
	echo -e '\e[0;32mCompilado.\nIniciando CreatePass...\e[0m'
else
	# Compiling english file
	echo -e 'Compiling...[0m'
	echo '   gcc -Wall -o "CreatePass" "_'$lang'.c"'
	gcc -Wall -o "CreatePass" "_$lang.c" || { echo -e '   \e[0;31mERROR: Failed to compile CreatePass.\n   Error in _'$lang'.c, Is there the file?\n\e[0m\n'; exit 1; }
	echo -e '	\e[0;32mCompiled.\nStarting CreatePass...\e[0m'
fi

# Starting CreatePass
echo -e '   ./CreatePass\n\n'
./CreatePass