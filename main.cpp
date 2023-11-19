#include <iostream>
#include "menu.h"
#include "Venta.h"
#include "VentasService.h"
#include "LibroService.h"
#include "Libro.h"
#include "Editorial.h"
#include "Autor.h"
#include "Genero.h"
#include "Fecha.h"
#include "Config.h"


int main()
{
    menuInicio();
    int numero = 1234;
    char resultado[5];  // Se reserva espacio para el número y el carácter nulo '\0'

    // Utilizando sprintf para convertir el entero a una cadena de caracteres
    sprintf(resultado, "%d", numero);
    std::cout<<resultado;


    return 0;
}
