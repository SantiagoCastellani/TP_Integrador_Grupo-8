#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#include "Fecha.h"
#include "Venta.h"
#include "Libro.h"
#include "Cliente.h"


class DetalleVenta
{
    public:
        DetalleVenta();

        // DetalleVentaCompleto
        DetalleVenta(int,
                     char dniCliente[9],
                     char nombreCliente[25],
                     char apellidoCliente[24],
                     char telefonoCliente[15],
                     char emailCliente[100],
                     char tituloLibro[100],
                     char nombreAutor[25],
                     char apellidoAutor[24],
                     char editorialLibro[30],
                     double importeVenta,
                     int medioDePago,
                     Fecha fecha);


        // Detalle Venta (Venta)
        DetalleVenta(Venta venta);

        // Imprimir DETALLE
        void imprimirDetalle(Venta venta);

        /// GETTERS
        int getIdVenta();
        const char* getDniCliente();
        const char* getNombreCliente();
        const char* getApellidoCliente();
        const char* getTelefonoCliente();
        const char* getEmailCliente();
        const char* getTituloLibro();
        const char* getNombreAutor();
        const char* getApellidoAutor();
        const char* getEditorialLibro();
        double getImporteVenta();
        int getMedioDePago();
        Fecha getFecha();

        /// SETTERS
        void setIdVenta(int);
        void setDniCliente(const char*);
        void setNombreCliente(const char*);
        void setApellidoCliente(const char*);
        void setTelefonoCliente(const char*);
        void setEmailCliente(const char*);
        void setTituloLibro(const char*);
        void setNombreAutor(const char*);
        void setApellidoAutor(const char*);
        void setEditorialLibro(const char*);
        void setImporteVenta(double);
        void setMedioDePago(int);
        void setFecha(Fecha);


    protected:

    private:
        int _idVenta;
        char _dniCliente[9];
        char _nombreCliente[25];
        char _apellidoCliente[24];
        char _telefonoCliente[15];
        char _emailCliente[100];
        char _tituloLibro[100];
        char _nombreAutor[25];
        char _apellidoAutor[24];
        char _editorialLibro[30];
        double _importeVenta;
        int _medioDePago;
        Fecha _fecha;
};

#endif // DETALLEVENTA_H
