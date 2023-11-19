#ifndef CONFIG_H
#define CONFIG_H
#include "Cliente.h"

class Config
{
    public:
        Config();

        /// BACKUP
        void backupLibros();
        void backupVentas();
        void backupClientes();

        /// RESTAURAR ARCHIVOS
        void restaurarArchivosLibros();
        void restaurarArchivosVentas();
        void restaurarArchivosClientes();

        /// GENERAR EXCEL
        void crearExcelLibros();
        void crearExcelClientes();
        void crearExcelVentas();

    protected:

    private:

    /// ARCHIVOS DE BACKUP
    const char *BACKUP_VENTAS = "Backup-Ventas.bak";
    const char *BACKUP_CLIENTES = "Backup-Clientes.bak";
    const char *BACKUP_LIBROS = "Backup-Libros.bak";
};

#endif // CONFIG_H
