//Creado por Gabo Rivas
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
int size(struct cola *);
int ordenarCola(struct cola *);

int main(){
	struct cola miCola;
	crearCola(&miCola);//Creamos la cola
	esVacio(&miCola);//Preguntamos si esta vacio
	//Ingresamos valores a la cola
	int dato;
	printf("Ingrese los 6 datos separados por espacios: ");
	for (i = 1; i <= 6; i++) {
        scanf("%d", &dato);
        encolar(&miCola,dato);
    }
    printf("Datos en la cola inicial\n");
	verCola(&miCola);//vemos los cambios reflejados
	ordenarCola(&miCola);
	printf("Datos en la cola ordenada\n");
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
	//printf("Datos en la cola\n");
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

int size(struct cola *miCola) {
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

int ordenarCola(struct cola *miCola) {
    struct nodo *temp = NULL;
    struct nodo *ptr;

    // Verificar si la cola está vacía o tiene solo un elemento
    if (miCola->head == NULL || miCola->head == miCola->tail) {
        return;
    }

    // Utilizamos un bucle for para recorrer la cola
    for (i = 0; i < size(miCola); i++) {
        ptr = miCola->head;

        // Recorremos la cola desde el principio hasta el final
        while (ptr->siguiente != miCola->head) {
            // Comparamos el nodo actual con su siguiente
            if (ptr->dato > ptr->siguiente->dato) {
                // Si el nodo actual es mayor que el siguiente, intercambiamos los valores
                int tempData = ptr->dato;
                ptr->dato = ptr->siguiente->dato;
                ptr->siguiente->dato = tempData;
            }
            ptr = ptr->siguiente;
        }
    }
}
