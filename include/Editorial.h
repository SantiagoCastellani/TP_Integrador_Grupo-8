#ifndef EDITORIAL_H
#define EDITORIAL_H


class Editorial
{
    public:
        const char *ARCHIVO_EDITORIAL = "Editoriales.dat";

        Editorial();
        Editorial(int idEditorial,char* nombre);

        // Cargar EDITORIAL
        Editorial cargarEditorial();

        // REGISTRAR una EDITORIAL en ARCHIVO
        void registrarEditorial(Editorial);

        // Mostrar EDITORIAL
        void mostrarEditorial(Editorial);

        // LEER Archivo de Editoriales
        void leerArchivoEditorial();
        void leerArchivoEditorial2();

        // Devuelve el proximo Id a setear
        int proximoIdEditorial();

        // Devuelve EDITORIAL By ID
        Editorial buscarEditorialById(int);

        // Existe Editorial?
        bool existeEditorial(int);

        // Modificar Editorial
        void modificarEditorial();
        void updateEditorial(Editorial editorial);


        /// GETTERS
        int getIdEditorial();
        const char* getNombre();

        /// SETTERS
        void setIdEditorial(int);
        void setNombre(const char*);

    protected:

    private:
        int _idEditorial;
        char _nombre[30];
};

#endif // EDITORIAL_H
