#ifndef GENERO_H
#define GENERO_H


class Genero
{
    public:
        const char *ARCHIVO_GENEROS = "Generos.dat";

        Genero();
        Genero(int idGenero,char* genero);

        // Cargar GENERO
        Genero cargarGenero();

        // REGISTRAR una Genero en ARCHIVO
        void registrarGenero(Genero);

        // Mostrar Genero
        void mostrarGeneros(Genero);

        // LEER Archivo de Generos
        void leerArchivoGenerosActivos();
        void leerArchivoGenerosActivos2();
        void leerArchivoGenerosTodos();
        void leerArchivoGenerosInactivos();
        int cantGenerosInactivos();

        // Devuelve el proximo Id a setear
        int proximoIdGenero();

        // Devuelve Genero By ID
        Genero buscarGeneroById(int);

        // Existe Genero?
        bool existeGenero(int);

        // Modificar Genero
        void modificarGenero();
        void updateGenero(Genero genero);


        /// GETTERS
        int getIdGenero();
        const char* getGenero();
        bool getActivo();

        /// SETTERS
        void setIdGenero(int);
        void setGenero(const char*);
        void setActivo(bool);

    protected:

    private:
        int _idGenero;
        char _genero[30];
        bool _activo;
};

#endif // GENERO_H
