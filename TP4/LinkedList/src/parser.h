/** \brief Funcion que lee los datos de un archivo de texto y los alamacena en una lista.
 *
 * \param pFile FILE* Puntero que contiene la direccion del archivo de donde se extraeran los datos.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de la lista donde se guardaran los datos.
 * \return int Retorna 0 si pudo leer los datos o -1 si hubo un error.
 *
 */
int parser_CompanyFromText(FILE* pFile , LinkedList* pArrayListCompany);


/** \brief Funcion que lee los datos de un archivo binario y los almacena en una lista.
 *
 * \param pFile FILE* Puntero que contiene la direccion del archivo de donde extraera los datos.
 * \param pArrayListCompany LinkedList* Puntero que contiene la direccion de la lista donde se guardaran los datos.
 * \return int Retorna 0 si pudo leer los datos o -1 si hubo un error.
 *
 */
int parser_CompanyFromBinary(FILE* pFile , LinkedList* pArrayListCompany);

