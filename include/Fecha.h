#ifndef FECHA_H
#define FECHA_H
#include <iostream>

class Fecha
{
    public:
        Fecha();

        Fecha(int dia,int mes,int anio);

        bool esAnteriorA(Fecha fecha);
        bool esPosteriorA(Fecha fecha);

        /// Getters
        int getDia();
        int getMes();
        int getAnio();

        /// Setters
        void setDia(int);
        void setMes(int);
        void setAnio(int);

        // Fecha Formateada
        std::string fechaFormateada();

        // Cargar Fecha
        Fecha cargarFecha();

    protected:

    private:
        int _dia;
        int _mes;
        int _anio;
};

#endif // FECHA_H
