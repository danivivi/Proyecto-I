#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*Programa que crea, lista y modifica clientes y productos para despues
crear y listar facturas.
Fecha: 8 Marzo 2018
Elaborado por: Viviana Rojas Ruiz, Alejandro Gonzalez y Luisa Fernanda Andrade*/

struct Productos{
	int id;
	char nombre[20];
	float valor;
}productico[100],*pproduc=productico;

struct Factura{
	int id;	
	char cliente[20];
	char producto[20];
	int cantidad;
	float valorFac;
	char estado[20];
}facturitas[100],*pfac=facturitas,produc[100];

struct Personas{
	char nombre[20];
	int id;
	int cc;
	char direccion [40];
	int telefono;
	struct Productos produc;
	struct Factura fac;
}personitas[100],*ppersonitas=personitas;

//Prototipos
void crearClientes();
void modificarClientes();
void ListarClientes();
void crearProductos();
void listarProductos();
void modificarProductos();
void crearFacturas();
void listarFactura();
void listarPagas();
void listarNoPagas();
void Menu1();
void Menu2();
void Menu3();
char validarCar();

int cantclientes;
int tam;
int cant_facturas;
float total=0;
int a =0;
char entrar;
int acum=0;
int acumProduc=0;
int acumFac=0;
int cantProductos;

int main() {
	//Menu1();
	crearClientes();
	crearProductos();
	crearFacturas();
	listarFactura();	
	return 0;
}
char validarCar(){
	int j,pw;
	char opcion[60],c;
	fflush(stdin);
	printf("Ingresar-->  ");
	gets(opcion);
	
	j=strlen(opcion);
	
	if (j==1){
		if(isdigit(opcion[0])!=0){
			pw=1;
		}
	}
	if (pw==1){
		c=opcion[0];
	}
	return c;
}
void Menu1(){
	do{	
		printf("\n<<<<<<<<<<<<MENU 1.CREAR>>>>>>>>>>>\n");
		printf("-------------------------------------\n");
		printf("|        1.Crear Clientes           |\n");
		printf("|        2.Crear Productos          |\n");
		printf("|        3.Pasar al Siguiente Menu  |\n");		
		printf("|        0.Salir                    |\n");
		printf("-------------------------------------\n");		
		entrar = validarCar();
		switch(entrar){
		case '0':
			exit(0);
			break;
		case '1':
			crearClientes();
			break;
		case '2':
			crearProductos();
			break;
		case '3':
			Menu2();
			break;
		default:
			printf("Opcion Incorrecta\n");
		}
		
	}while(entrar!=0);
}

void Menu2(){
	int opcion;
	do{	
		printf("\n\n<<<<<<<<<MENU 2.LISTAR Y MODIFICAR>>>>>>>\n");
		printf("-------------------------------------------\n");
		printf("|         1.Listar Clientes               |\n");
		printf("|         2.Listar Productos              |\n");
		printf("|         3.Modificar Datos del cliente   |\n");		
		printf("|         4.Modificar Datos del Producto  |\n");		
		printf("|         5.Pasar a Registrar Factura     |\n");	
		printf("|         6.Volver al Menu Anterior       |\n");
		printf("|         0.Salir                         |\n");
		printf("-------------------------------------------\n");
		printf("\nIngrese una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
		case 0:
			exit(0);
			break;
		case 1:
			ListarClientes();
			break;
		case 2:
			listarProductos();
			break;
		case 3:
			modificarClientes();
			break;
		case 4:
			modificarProductos();
			break;
		case 5:
			Menu3();
			break;
		case 6:
			Menu1();
			break;
		default:
			printf("Opcion Incorrecta\n");
		}		
	}while(opcion!=0);	
}

void Menu3(){
	int opcion;
	do{	
		printf("\n\n<<<<<<<MENU 3.CREAR Y LISTAR FACTURAS>>>>>\n");
		printf("--------------------------------------------\n");
		printf("|           1.Crear Factura                |\n");
		printf("|           2.Listar Facturas              |\n");	
		printf("|           3.Volver al Menu Anterior      |\n");
		printf("|           0.Salir                        |\n");
		printf("--------------------------------------------\n");
		printf("Ingrese una opcion: ");		
		scanf("%d",&opcion);
		switch(opcion){
		case 0:
			exit(0);
			break;
		case 1:
			crearFacturas();
			break;
		case 2:
			int num;
			printf("\nQue Desea Ver: \n");
			printf("1.Todas las Facturas\n");
			printf("2.Facturas Pagas\n");			
			printf("3.Facturas No Pagas\n");			
			printf("4.Volver al Menu\n");			
			printf("0.Salir\n");
			printf("Ingrese Opcion: ");
			scanf("%d",&num);
			switch(num){
			case 0:
				exit(0);
				break;
			case 1:
				listarFactura();
				break;
			case 2:
				listarPagas();
				break;
			case 3:
				listarNoPagas();
				break;
			case 4:
				Menu3();
				break;
			default:
				printf("Opcion Invalida.\n");
			}
			break;
		case 3:
			Menu2();
			break;
		default:
			printf("Opcion Incorrecta\n");
		}		
	}while(opcion!=0);	
}

void crearClientes(){
	printf("\nCantidad de Clientes:");
	scanf("%d",&cantclientes);
	for(int i=acum;i<acum+cantclientes;i++){
		(ppersonitas+i)->id=i+1;
		printf("%i. Nombre: ",i+1);
		fflush stdin;
		fgets((ppersonitas+i)->nombre,20,stdin);
		printf("Cedula: ");
		scanf("%d",&(ppersonitas+i)->cc);
		printf("Direccion: ");
		fflush stdin;
		fgets((ppersonitas+i)->direccion,40,stdin);
		printf("Telefono: ");
		scanf("%d",&(ppersonitas+i)->telefono);		
	}
	acum=acum+cantclientes;
}

void ListarClientes(){
	printf("\n-----------Mostrando Listado de Clientes------------\n");
	for(int i=0;i<acum;i++){
		printf("\n");
		printf("Id.%d ",(ppersonitas+i)->id);
		printf("Nombre: %s ",(ppersonitas+i)->nombre);
		printf("Cedula: %d ",(ppersonitas+i)->cc);
		printf("Direccion: %s ",(ppersonitas+i)->direccion);
		printf("Telefono: %d\n",(ppersonitas+i)->telefono);
	}
}

void modificarClientes(){
	char buscarnombre[20];
	int pos=0;
	int dato,opcion,nuevacedula,nuevotelefono;
	char nuevo_nombre[20],nuevadireccion[40];
	printf("\nIngrese Nombre del Cliente que desea Modificar: ");
	fflush stdin;
	fgets(buscarnombre,20,stdin);
	for(int i=0;i<acum;i++){
		if(strcmp(buscarnombre,(ppersonitas+i)->nombre)==0){
			pos=i;
			printf("\nQue desea Modificar:\n");
			printf("1.Nombre\n");
			printf("2.Cedula.\n");
			printf("3.Direccion.\n");
			printf("4.Telefono.\n");
			printf("0. Salir.\n");
			scanf("%d",&opcion);
			switch(opcion){
			case 0:
				exit(0);
				break;
			case 1:				
				printf("Ingrese Nuevo Nombre\n");
				fflush stdin;
				fgets(nuevo_nombre,20,stdin);
				strcpy((ppersonitas+pos)->nombre,nuevo_nombre);
				printf("\nNombre Modificado.\n");
				break;
			case 2:
				printf("Ingrese Nueva Cedula:\n");
				scanf("%d",&nuevacedula);
				(ppersonitas+pos)->cc=nuevacedula;
				printf("\nCedula Modificada.\n");
				break;
			case 3:
				printf("Ingrese Nueva Direccion:\n");
				fflush stdin;
				fgets(nuevadireccion,40,stdin);
				strcpy((ppersonitas+pos)->direccion,nuevadireccion);
				printf("\nDireccion Modificada.\n");
				break;
			case 4:
				printf("Ingrese Nuevo Telefono:\n");
				scanf("%d",&nuevotelefono);
				(ppersonitas+pos)->telefono=nuevotelefono;
				printf("\nTelefono Modificado.\n");
				break;
			default:
				printf("Opcion Invalida.\n");
			}
		}else{
			printf("\nNOMBRE NO ENCONTRADO.\n\n");
			printf("Desea Ingresar los datos del nuevo Cliente?\n");
			printf("Marque 1 para SI, Marque 2 para NO o Marque 0 para Salir.\n");
			scanf("%d",&dato);
			switch(dato){
			case 0:
				exit(0);
			case 1:
				crearClientes();
				break;
			case 2:
				exit(2);
				break;
			default:
				printf("Opcion Invalida.\n");
			}			
		}	
	}	
}
void crearProductos(){
	printf("\nIngrese Cantidad de Productos: ");
	scanf("%d",&tam);
	printf("\nIngrese Productos.\n");
	for(int i=acumProduc;i<acumProduc+tam;i++){
		(pproduc+i)->id=i+1;
		printf("\n%i.Nombre: ",i+1);
		fflush stdin;
		fgets((pproduc+i)->nombre,20,stdin);
		printf("\nPrecio: ");
		scanf("%f",&(pproduc+i)->valor);
	}
	acumProduc=acumProduc+tam;
}

void listarProductos(){
	printf("\n---------Mostrando Listado de Productos.-------------");
	for(int i=0;i<acumProduc;i++){
		printf("\n\nid.%d  Nombre: %s Valor: $%.2f\n",(pproduc+i)->id,(pproduc+i)->nombre,(pproduc+i)->valor);
	}
}

void modificarProductos(){
	char buscar_producto[20],nuevoNom[20];
	int x,opcion,dato;
	float nuevoVal;
	printf("\nIngrese Nombre del Producto a Modificar: ");
	fflush stdin;
	fgets(buscar_producto,20,stdin);
	for(int i=0;i<acumProduc;i++){
		if(strcmp((pproduc+i)->nombre,buscar_producto)==0){
			x=i;
			printf("\nQue desea Modificar Ingrese una Opcion\n");
			printf("1.Modificar Nombre.\n");
			printf("2.Modificar Valor.\n");
			printf("0.Salir.\n");
			scanf("%d",&opcion);
			switch(opcion){
			case 0:
				exit(0);
				break;
			case 1:
				printf("\nIngrese Nuevo Nombre: ");
				fflush stdin;
				fgets(nuevoNom,20,stdin);
				strcpy((pproduc+x)->nombre,nuevoNom);
				printf("\nNombre Modificado.\n");
				break;
			case 2:
				printf("\nIngrese Nuevo Valor: ");
				scanf("%f",&nuevoVal);
				(pproduc+x)->valor=nuevoVal;
				printf("\nValor Modificado.\n");
				break;
			default:
				printf("Opcion Invalida.");
			}
		}else{
			printf("\nPRODUCTO NO ENCONTRADO EN LISTA.\n\n");
			printf("Que desea Hacer:\n");
			printf("1.Agregar Producto a la Lista.\n");
			printf("2.Salir.\n");
			scanf("%d",&dato);
			switch(dato){
			case 1:
				crearProductos();
				break;
			case 2:
				exit(2);
				break;
			default:
				printf("\nOpcion Invalida.\n");
			}
		}
	}
}

void crearFacturas(){
	int pos,x,c=0;
	char encontrado='F';
	char buscar_cliente[20];
	float vecproductos[100];
	char buscar_produc[20];
	int opcion,dato;
	printf("\nIngrese Cantidad de Facturas a Crear: ");
	scanf("%d",&cant_facturas);
	for(int i=acumFac;i<acumFac+cant_facturas;i++){		
		(pfac+i)->id=i+1;		
		printf("\n\nNombre del Cliente: ");	
		for(int i=0;i<acum;i++){		
			fflush stdin;
			fgets(buscar_cliente,20,stdin);
			if(strcmp(buscar_cliente,(ppersonitas+i)->nombre)==0){
				pos=i;
				printf("\n----------Cliente Registrado------------.\n\n");
				printf("Datos del Cliente:\n");
				printf("ID.%d  Nombre: %s Cedula: %d  Direccion: %s Telefono: %d\n\n",(ppersonitas+pos)->id,(ppersonitas+pos)->nombre,(ppersonitas+pos)->cc,(ppersonitas+pos)->direccion,(ppersonitas+pos)->telefono);				
				strcpy((pfac+c)->cliente,(ppersonitas+pos)->nombre);
				encontrado='F';
				printf(">>>hola<<<");
			}else{
				printf("\nEl Cliente No se Encuentra Registrado.\n");
				printf("\nPara continuar Registre el Cliente.\n");
				crearClientes();
			}
		}
		if(encontrado=='F'){
			printf("\nCuentos Productos desea Agregar a la Factura: ");
			scanf("%d",&cantProductos);
			for(int j=0;j<cantProductos;j++){
				printf("\nProducto: ");
				fflush stdin;
				fgets(buscar_produc,20,stdin);
				printf("\n------------------------------------\n");
				for(int j=0;j<acumProduc;j++){
					if(strcmp(buscar_produc,(pproduc+j)->nombre)==0){
						x=j;						
						printf("Producto: %s    Valor:  %.2f",(pproduc+x)->nombre,(pproduc+x)->valor);
						vecproductos[a]=(pproduc+x)->valor;
						strcpy(produc[a].producto,(pproduc+x)->nombre);
						a++;
					}else if (a==0){
						printf("\nNo Hay Existencia del Producto.\n");
					}
				}
			}
		}
		printf("\nDesea  Realizar el Pago.\n");
		printf("1.Si\n");
		printf("2.No\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			for(int i=0;i<acumFac;i++){
				strcpy((pfac+i)->estado,"pagar");
			}		
			break;
		case 2:
			for(int i=0;i<acumFac;i++){
				strcpy((pfac+i)->estado,"sin pagar");
			}
			break;
		default:
			printf("Opcion Invalida.\n");
		}
	}
	acumFac=acumFac+cant_facturas;	
	for(int b=0;b<a;b++){
		total=total+vecproductos[b];
	}		
	printf("\nDesea Generar Otra Venta.\n");
	printf("1.Si\n");
	printf("2.Volver al Menu\n");
	scanf("%d",&dato);
	switch(dato){
	case 1:
		crearFacturas();
		break;
	case 2:
		Menu3();		
		break;
	default:
		printf("Opcion Invalida.\n");
	}	
}

void listarFactura(){
	for(int i=0;i<acumFac;i++){
		printf("\n\n*********FACTURA - Id.%d*******",(pfac+i)->id);
		printf("\n*****************************\n");		
		printf("Nombre del Cliente: %s",(pfac+i)->cliente);
		printf("\n*****************************\n");
		while(i<cantProductos)
		{
			printf("Productos: %s\n",produc[i].producto);
			i++;
		}
		printf("\n*****************************\n");
		printf("Total de la Factura: %.2f",total);
		printf("\n*****************************\n");
	}
}

void listarPagas(){
	printf("\n--------Facturas Pagas-------------\n");
	for(int i=0;i<acumFac;i++){
		if(strcmp((pfac+i)->estado,"pagar")==0){
			listarFactura();
		}
	}
}
void listarNoPagas(){
	printf("\n----------Facturas No Pagas---------\n");
	for(int i=0;i<acumFac;i++){
		if(strcmp((pfac+i)->estado,"sin pagar")==0){
			listarFactura();		 
		}
	}
}

