#!/bin/bash
# Compile CreatePass 1.0 (Linux)
#
# Create by NEKERAFA on thu, 22 jun 2011 00:20:31 (CEST)
# Copyleft 2011 NEKERAFA (nekerafa@gmail.com)

# Variables
VERSION=1.0

# Loading CreatePass
echo -e '\e[0;32mLoading CreatePass '$VERSION' (Linux)...'

# Detecting Language
if [ $LANG="es_ES.UTF-8" ]; then
	# Spanish
	echo -e 'Español...\n'
	lang="es"
else
	# English
	echo -e 'English...\n'
	lang="en"
fi

# Compile CreatePass
if [ $lang="es" ]; then
	# Compiling spanish file
	echo -e 'Compilando...\e[0m'
	gcc -Wall -o "CreatePass" "_$lang.c" || { echo -e '\e[0;32mERROR: No se ha podido compilar CreatePass.\n	Error en _'$lang', ¿Existe el archivo?\e[0m\n'; exit 1; }
	echo -e '\e[0;32mCompilado.\nIniciando CreatePass...\n\n\e[0m'
else
	# Compiling english file
	echo -e 'Compiling...[0m'
	gcc -Wall -o "CreatePass" "_$lang.c" || { echo -e '\e[0;32mERROR: Failed to compile CreatePass.Error in _'$lang'.c, Is there the file?\n\e[0m\n'; exit 1; }
	echo -e '\e[0;32mCompiled.\nStarting CreatePass...\n\n\e[0m'
fi

# Starting CreatePass
./CreatePass
