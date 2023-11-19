#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"


class Venta
{
    public:
        Venta();

        Venta(int, char*, int, double, int, Fecha);

        /// GETTERS
        int getIdVenta();
        const char* getDniCliente();
        int getIdLibro();
        double getImporteVenta();
        int getMedioDePago();
        Fecha getFecha();

        /// SETTERS
        void setIdVenta(int);
        void setDniCliente(const char*);
        void setIdLibro(int);
        void setImporteVenta(double);
        void setMedioDePago(int);
        void setFecha(Fecha);

    protected:

    private:
        int _idVenta;
        char _dniCliente[9];
        int _idLibro;
        double _importeVenta;
        int _idMedioDePago;
        Fecha _fecha;


};

#endif // VENTA_H
