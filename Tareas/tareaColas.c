//codigo creado por Gabo Rivas
#include <stdio.h>
#include <stdlib.h>

int i;

//Declaracion del nodo que nos va a servir para guardar datos y enlazarlos
struct nodo{
	int dato;
	struct nodo *siguiente;
	};

//estructura de la cola para tener la referencia de la cabeza y cola de la estructura  
struct cola{
	struct nodo *head;
	struct nodo *tail;
	};
    


int crearCola(struct cola *);
int encolar(struct cola *, int);
int desencolar(struct cola *);
void verCola(struct cola *);
int esVacio(struct cola *);
int obtenerLongitudCola(struct cola *);
int modificarDatoPorPosicion(struct cola *, int, int);

int main(){
	struct cola miCola;
	crearCola(&miCola);//Creamos la cola
	esVacio(&miCola);//Preguntamos si esta vacio
	//Ingresamos valores a la cola
	encolar(&miCola,1);
	encolar(&miCola,2);
	encolar(&miCola,3);
	encolar(&miCola,4);
	encolar(&miCola,5);//Ingresamos otro valor
	verCola(&miCola);//vemos los cambios reflejados
	int pos, dataMod;
    printf("Ingrese la posicion a modificar: ");
    scanf("%d", &pos);
    printf("Ingrese el dato a modificar: ");
    scanf("%d", &dataMod);
    modificarDatoPorPosicion(&miCola,pos-1,dataMod);
    verCola(&miCola);//vemos los cambios reflejados
    
	//Usamos esta funcion para liberar la memoria
	//ya que se esta emplenado memoria dinamica paar crear los nodos de una
	//cola dinamica
	while(&miCola==NULL){
    	desencolar(&miCola);
    	}
	
	return 0;
	}
    
    
int crearCola(struct cola *nuevaCola){
	nuevaCola->head = NULL; //Inicializamos la cola
	nuevaCola->tail = NULL;
	return 0;
	}
    
int encolar(struct cola *encolarCola, int dato){
	//Creamos un nuevo nodo de la estructura nodo
	struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
	if(nuevoNodo==NULL){
    	printf("No se pudo asignar la memoria al elemnto\n");
    	return -1;
    	}
	//si se creo correctamente
	//Pasamos el nuevo valor que se va a ingresar a la cola
	nuevoNodo->dato=dato;//le damos el dato al nuevo nodo
	nuevoNodo->siguiente = NULL;//Hacemos que el nuevo nodo en su valor siguiente sea NULL esto nos indicara que sera el ultimo elemento que ingreso
    
	//Hacemos una comparacion
	if(encolarCola->head==NULL){//Si la cola esta vacien en la posicien frente osease es el primer elemento en ingresara  la cola
    	encolarCola->head=nuevoNodo;//Hacemos que la cabeza sea el nuevo nodo
   	 
    	}else{
        	encolarCola->tail->siguiente = nuevoNodo;//si hay mas elementos antes posicionaremos el nuevo nodo al final del ultimo nodo ingresado
       	 
       	 
        	}
	encolarCola->tail=nuevoNodo;//ponemos el nuevo nodo al final de la cola
	nuevoNodo->siguiente=encolarCola->head;//Cerramos el ciclo con el ultimo elemento que el siguiente sea el inicio de la cola
	return 0;
	}
    
int desencolar(struct cola *desencolarCola){
	//verificamos si la pila esta vacia  
	if(desencolarCola->head==NULL){
    	printf("Error la cola esta vacia\n");
    	return -1;
    	}
	//Si no esta vacia creamos un nuevo nodo auxiliar para poder eliminar
	struct nodo *nodoEliminar = desencolarCola->head;//Se crea un nuevo nodo poniendolo en el elemento conde apunta head
   
    
	if(desencolarCola->head==desencolarCola->tail){//Si se eliminan todos los elementos y la cabeza queda con valor null
        	desencolarCola->head = NULL;//No hay elementos que apunten al head
        	desencolarCola->tail = NULL;//significa que tambien la cola esta en NULL y que no hay elementos en la cola
    	}else{
        	desencolarCola->head = desencolarCola->head->siguiente;//Usamos el valor siguiente antes de desencolarlo para el que este antes
        	desencolarCola->tail->siguiente=desencolarCola->head;//hacemos que la cola del suiguiente nodo apunte a la cabeza de la cola
        	}
    
	free(nodoEliminar);//Se elimina el nodo
	return 0;
	}
    
void verCola(struct cola *miCola){
	struct nodo *nodoAuxiliar= miCola->head;//creamos un nodo auxiliar para obtener los elementos de la cola empezando en el frente  
	printf("Datos en la cola\n");
	do{//mientras que el valor de la cola sea diferente de nulo
    	printf("%d",nodoAuxiliar->dato);//va a ir a la estructura de la pila en su variable dato y la imprime
    	printf("\n");
    	nodoAuxiliar = nodoAuxiliar->siguiente;//va ir al campo sighuiente es decir al nodo que esta siguiente del actual
    	//Y se pa a posicionar con su direccion de memoria en dicho nodo.
    	}while(nodoAuxiliar!=miCola->head);
	printf("\n");
	}

int esVacio(struct cola *miCola){
	if(miCola->head==NULL){//Verificamois si es nulo la Pila
    	printf("Esta Vacio\n");
    	return -1;
    	}else{
        	return 0;
        	}
	}
	
int modificarDatoPorPosicion(struct cola *miCola, int posicion, int nuevoDato) {
	// Validar si la cola está vacía
	if (esVacio(miCola)) {
		printf("Error: La cola está vacia.\n");
		return -1;
	}
	
	// Validar si la posición está dentro del rango válido
	int longitudCola = obtenerLongitudCola(miCola);
	if (posicion < 0 || posicion >= longitudCola) {
		printf("Error: La posición %d está fuera del rango válido (0-%d).\n", posicion, longitudCola-1);
		return -1;
	}
	
	// Crear un nodo auxiliar para recorrer la cola
	struct nodo *nodoActual = miCola->head;
	
	// Avanzar hasta la posición indicada
	for ( i = 0; i < posicion; i++) {
		nodoActual = nodoActual->siguiente;
	}
	
	// Modificar el dato
	nodoActual->dato = nuevoDato;
	
	// Imprimir mensaje de éxito
	printf("Dato en la posicion %d modificado correctamente.\n", posicion+1);
	
	return 0;
}
int obtenerLongitudCola(struct cola *miCola) {
	// Variable para contar la longitud
	int longitud = 0;
	
	// Nodo auxiliar para recorrer la cola
	struct nodo *nodoActual = miCola->head;
	
	// Si la cola no está vacía
	if (nodoActual != NULL) {
		// Recorrer la cola hasta llegar al nodo siguiente al head
		do {
			longitud++;
			nodoActual = nodoActual->siguiente;
		} while (nodoActual != miCola->head);
	}
	
	// Retornar la longitud de la cola
	return longitud;
}
