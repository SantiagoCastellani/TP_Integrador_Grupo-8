#ifndef MEDIODEPAGO_H
#define MEDIODEPAGO_H


class MedioDePago
{
    public:
        MedioDePago();

        MedioDePago(int,char*,float,int);


        /// GETTERS
        int getId();
        const char* getNombre();
        float getRecargo();
        int getCantCuotas();

        /// SETTERS
        void setId(int);
        void setNombre(const char*);
        void setRecargo(float);
        void setCantCuotas(int);

    protected:

    private:
        int _id;
        char _nombre[30];
        float _recargo;
        int _cantCuotas;
};

#endif // MEDIODEPAGO_H
