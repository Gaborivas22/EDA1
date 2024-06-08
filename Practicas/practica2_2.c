//Creado por Gabo Rivas
#include <stdio.h>
#include <stdlib.h>

int i;

//Declaracion del nodo que nos va a servir para guardar datos y enlazarlos
struct nodo{
	int dato;
	int prioridad;
	struct nodo *siguiente;
	struct nodo *anterior;
	};

//estructura de la cola para tener la referencia de la cabeza y cola de la estructura  
struct cola{
	struct nodo *head;
	struct nodo *tail;
	};
    


int crearCola(struct cola *);
int encolarFrente(struct cola *, int, int);
int encolarFinal(struct cola *, int, int);
int desencolarFrente(struct cola *);
void verCola(struct cola *);
int esVacio(struct cola *);

int main(){
	struct cola miCola;
	crearCola(&miCola);//Creamos la cola
	//Ingresamos valores a la cola
    for (i = 1; i <= 6; i++) {
        encolarFinal(&miCola,i,1);
    }

    int choice;
    do {
        printf("\nMenu Impresora:\n");
        printf("1) Ver datos de Impresion\n");
        printf("2) Mandar a imprimir\n");
        printf("3) Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                desencolarFrente(&miCola);
                break;
            case 2:
                verCola(&miCola);
                int document, priority;
                printf("Ingrese el numero del documento a imprimir: ");
                scanf("%d", &document);
                do{
                	printf("Ingrese la prioridad (1 para baja, 2 para alta): ");
                	scanf("%d", &priority);
	                if(priority==1){
	                	encolarFinal(&miCola,document,1);
					}if(priority==2){
	                	encolarFrente(&miCola,document,2);
					}
					if(priority!=2 && priority!=1){
						printf("Prioridad invalida\n");
					}
				}while(priority!=2 && priority!=1);
				
                break;
            case 3:
            	while(&miCola==NULL){
			    	desencolarFrente(&miCola);
			    }
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Inténtelo de nuevo.\n");
                break;
        }
    } while (choice != 3);
    

	//system("PAUSE");
	return 0;
	}
    
    
int crearCola(struct cola *nuevaCola){
	nuevaCola->head = NULL; //Inicializamos la cola
	nuevaCola->tail = NULL;
	return 0;
	}
    
int encolarFrente(struct cola *encolarColaFrente, int dato, int prioridad){
	//Creamos un nuevo nodo de la estructura nodo
	struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
	if(nuevoNodo==NULL){
    	printf("No se pudo asignar la memoria al elemnto\n");
    	return -1;
    	}
	//si se creo correctamente
	//Pasamos el nuevo valor que se va a ingresar a la cola
	nuevoNodo->dato=dato;//le damos el dato al nuevo nodo
	nuevoNodo->prioridad=prioridad;
	nuevoNodo->siguiente = encolarColaFrente->head;//Hacemos que el nuevo nodo en su valor siguiente sea NULL esto nos indicara que sera el ultimo elemento que ingreso
	nuevoNodo->anterior=NULL;
    
	//Hacemos una comparacion
	if(encolarColaFrente->head==NULL){//Si la cola esta vacien en la posicien frente osease es el primer elemento en ingresara  la cola
    	encolarColaFrente->head=nuevoNodo;//Hacemos que la cabeza sea el nuevo nodo
    	encolarColaFrente->tail=nuevoNodo;//Hacemos que la cola apunte al nuevo elemento del nodo
    	}else{
        	encolarColaFrente->head->anterior = nuevoNodo;//si ya hubo un elemento antes vamos a poner en la parte anterior al nodo ingresado
        	encolarColaFrente->head=nuevoNodo;
       	 
        	}
	return 0;
	}
    
int encolarFinal(struct cola *encolarColaFinal, int dato,int prioridad){
	//Creamos un nuevo nodo de la estructura nodo
	struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
	if(nuevoNodo==NULL){
    	printf("No se pudo asignar la memoria al elemnto\n");
    	return -1;
    	}
	//si se creo correctamente
	//Pasamos el nuevo valor que se va a ingresar a la cola
	nuevoNodo->dato=dato;
	nuevoNodo->prioridad=prioridad;//le damos el dato al nuevo nodo
	nuevoNodo->siguiente = NULL;//Hacemos que el nuevo nodo en su valor siguiente sea NULL esto nos indicara que sera el ultimo elemento que ingreso
	nuevoNodo->anterior=encolarColaFinal->tail;
    
	//Hacemos una comparacion
	if(encolarColaFinal->head==NULL){//Si la cola esta vacien en la posicien frente osease es el primer elemento en ingresara  la cola
    	encolarColaFinal->head=nuevoNodo;//Hacemos que la cabeza sea el nuevo nodo
    	encolarColaFinal->tail=nuevoNodo;//Hacemos que la cola apunte al nuevo elemento del nodo
    	}else{
        	encolarColaFinal->tail->siguiente = nuevoNodo;//si ya hubo un elemento antes vamos a poner en la parte anterior al nodo ingresado
        	encolarColaFinal->tail=nuevoNodo;
       	 
        	}
	return 0;
	}
    
int desencolarFrente(struct cola *desencolarColaFrente){
	//verificamos si la pila esta vacia  
	if(desencolarColaFrente->head==NULL){
    	printf("Favor de mandar a imprimir documentos\n");
    	return -1;
    	}
	//Si no esta vacia creamos un nuevo nodo auxiliar para poder eliminar
	struct nodo *nodoEliminar = desencolarColaFrente->head;//Se crea un nuevo nodo poniendolo en el elemento conde apunta head
	struct nodo *nodoAuxiliar = desencolarColaFrente->head;
	printf("Documento impreso %d ",nodoAuxiliar->dato);
	printf("con prioridad %d",nodoAuxiliar->prioridad);
   
	if(desencolarColaFrente->head==desencolarColaFrente->tail){//Si se eliminan todos los elementos y la cabeza queda con valor null
        desencolarColaFrente->head = NULL;//No hay elementos que apunten al head
        desencolarColaFrente->tail = NULL;//significa que tambien la cola esta en NULL y que no hay elementos en la cola
    }else{
        desencolarColaFrente->head = nodoEliminar->siguiente;//Usamos el valor siguiente antes de desencolarlo para el que este antes
        desencolarColaFrente->head->anterior=NULL;//hacemos que la cola NULL
    	free(nodoEliminar);//Se elimina el nodo
		return 0;
	}
}
    

void verCola(struct cola *miCola){
	struct nodo *nodoAuxiliar= miCola->head;//creamos un nodo auxiliar para obtener los elementos de la cola empezando en el frente  
	printf("Datos en la cola\n");
	while(nodoAuxiliar!=NULL){//mientras que el valor de la cola sea diferente de nulo
    	printf("Documento %d ",nodoAuxiliar->dato);
		printf("con prioridad %d",nodoAuxiliar->prioridad);
    	printf("\n");
    	nodoAuxiliar = nodoAuxiliar->siguiente;//va ir al campo sighuiente es decir al nodo que esta siguiente del actual
    	//Y se pa a posicionar con su direccion de memoria en dicho nodo.
    	};
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


