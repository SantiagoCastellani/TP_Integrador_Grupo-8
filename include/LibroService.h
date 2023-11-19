#ifndef LIBROSERVICE_H
#define LIBROSERVICE_H
#include "Libro.h"

class LibroService
{
    public:

        const char *ARCHIVO_LIBROS = "Libros.dat";
        const char *ARCHIVO_REGISTROVENTAS = "RegistrodeVentas.dat";

        LibroService();

        /// LIBROS

        // Cargar un Libro
        Libro cargarLibro();

        // Mostrar un Libro
        void mostrarLibro(Libro);
        void mostrarLibro2(Libro);
        void infoBasicaLibro(int id);

        // Devuelve el proximo Id a setear
        int proximoIdLibro();

        // REGISTRAR un LIBRO en ARCHIVO
        void registrarLibro(Libro);

        // LEER Archivo de LIBROS
        void leerArchivoLibros();

        // Buscar LIBRO By ID
        Libro buscarLibroById(int);

        // Existe LIBRO?
        bool existeLibro(int);

        // Buscar LIBRO por TITULO
        Libro buscarLibroByTitulo();

         // Buscar LIBRO por TITULO
        Libro buscarLibroByTitulo(char*titulo);

        // Existe TITULO?
        bool existeTitulo(char*titulo);

        // Elegir entre Posibles LIBROS
        int devolverIdLibro(char* titulo);

        // Devolver un Id de Libro Elegido
        int elegirLibro(char*titulo);

        // Funcion Busqueda de LIBRO por TITULO desde MENU
        void buscarLibroTitulo();

        // Funcion Busqueda de LIBRO por COD AUTOR desde MENU
        void buscarLibroCodAutor();

        // Comparar Titulos
        int compararTitulos(char * tituloBuscado,char *tituloLibro);

        // Cantidad de Libros By Id Autor
        int tieneLibrosByIdAutor(int idAutor);

        /// LISTADOS

        // Lista por GENERO
        void listarPorGenero();

        // Listado By Editorial
        void listarPorEditorial();

        // Listado por TITULO Alfabeticamente
        void listarPorTituloAZ();
        void leerLibrosCargarVector(Libro * vectorLibros);
        void ordenarAlfabeticamente(Libro *vectorLibros,int cantLibros);
        void listarOrdenado(Libro *vectorLibros,int cantLibros);

        //Listar Libros Todos
        void listarLibrosTodos();

        // Modificar Libros
        void modificarLibro();
        void updateLibro(Libro libro);

        // Ventas de Libros
        bool hayStock(int id);
        void reducirStock(int id);
        void updatearLibroPosVenta(Libro libro);

        // El LIBRO mas VENDIDO
        Libro libroMasVendido();
        int copiasVendidas(int idLibro);

        // El LIBRO mas VENDIDO del ANIO
        Libro libroMasVendido(int anio);
        int copiasVendidas(int idLibro,int anio);

        // El LIBRO mas VENDIDO del MES
        Libro libroMasVendido(int anio,int mes);
        int copiasVendidas(int idLibro,int anio,int mes);




    protected:

    private:
};

#endif // LIBROSERVICE_H
