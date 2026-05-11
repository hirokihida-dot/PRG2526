#ifndef SORTEDREGISTER_H
#define SORTEDREGISTER_H

#include <fstream>
#include <string>

/**
 * @class SortedRegister
 * @brief Registro ordenado de cantidades asociadas a fechas de un año.
 *
 * Esta clase encapsula una estructura matricial que permite almacenar,
 * clasificar y acumular datos asociados a días y meses de un año dado.
 * Los datos se leen desde ficheros de texto y se pueden guardar ordenados
 * cronológicamente.
 */
class SortedRegister {
public:

    /**
     * @brief Construye un registro ordenado para un año determinado.
     *
     * Reserva memoria para almacenar los datos correspondientes a todos
     * los días válidos del año indicado.
     *
     * @param year Año para el que se crea el registro.
     */
    SortedRegister(int year);

    /**
     * @brief Destructor de la clase.
     *
     * Libera toda la memoria reservada para el registro.
     */
    ~SortedRegister();

    /**
     * @brief Procesa un fichero de entrada completo.
     *
     * Si se detecta un error en alguna línea, el proceso se interrumpe y
     * se devuelve -1.
     *
     * @param input Fichero de entrada con los datos.
     * @return Número de líneas procesadas o -1 si se produce un error.
     */
    int add(std::ifstream& input);

    /**
     * @brief Procesa un fichero de entrada registrando los errores.
     *
     * Las líneas con errores no se procesan y se registran en el fichero
     * de log indicado.
     *
     * @param input Fichero de entrada con los datos.
     * @param log Fichero de salida para el informe de errores.
     * @return Número de líneas procesadas.
     */
    int add(std::ifstream& input, std::ofstream& log);

    /**
     * @brief Guarda los datos registrados en un fichero de salida.
     *
     * Solo se escriben los días cuya cantidad acumulada es mayor que cero.
     * Los datos se escriben ordenados cronológicamente.
     *
     * @param output Fichero de salida.
     */
    void save(std::ofstream& output) const;

private:
    int year;                 ///< Año del registro
    int** registerMatrix;     ///< Matriz de acumulación de datos [mes][día]

    static const int DAYS[13];

    bool isLeap(int year) const;
    void handleLine(const std::string& line);
};

#endif