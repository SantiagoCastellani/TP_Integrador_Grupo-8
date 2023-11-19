#ifndef CLIENTESERVICE_H
#define CLIENTESERVICE_H
#include "Cliente.h"

class ClienteService
{
    public:

        const char *ARCHIVO_CLIENTES = "Clientes.dat";
        const char *ARCHIVO_REGISTROVENTAS = "RegistrodeVentas.dat";

        ClienteService();


       // cargarCliente
       Cliente cargarCliente(char* dni);

       //mostrarCliente
       void mostrarCliente(Cliente);

       //registrarCliente
       void registrarCliente(Cliente);

       //leerArchivoClientes
       void leerArchivoClentes();

       //buscarClienteDni
       Cliente buscarClientexDni(char* dni);

       //extisteCliente
       bool existeCliente(char* dni);

       //clienteMayorGasto

       //listarClientes
       int obtenerCantidadClientes();
       void cargarRegistroClientes(Cliente *);
       void ordenarVectorPorNombres(Cliente *,int);
       void ordenarVectorPorFecha(Cliente *,int);
       void mostrarVectorOrdenadoPorApellido(Cliente *,int);
       void mostrarVectorOrdenadoPorFecha(Cliente *,int);
       void listarClientesByApellido();
       void listarClientesByFechaNacimiento();

       //modificarCliente
       void modificarCliente();

       void editarCliente(Cliente);

       void mostrarClienteRegistrado(Cliente cliente);

       /// EStadisticas
       float ventasXclienteAnio(char* dni,int anio);
       float ventasXclienteMes(char* dni,int anio,int mes);
       Cliente clienteMayorGastoAnio();
       Cliente clienteMayorGastoMes();

    protected:

    private:
};

#endif // CLIENTESERVICE_H
