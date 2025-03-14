#include <stdio.h>
int choice = 0;
int main() {
    do
    {
        printf("\nMenu de sistema de biblioteca\n");
        printf("\t1 - Agregar un libro\n");
        printf("\t2 - Mostrar libro disponibles\n");
        printf("\t3 - Agregar un miembro\n");
        printf("\t4 - Prestar un libro\n");
        printf("\t5 - Salir,\n");
        printf("Indica tu opcion: ");  
        scanf("%d", &choice);
        switch(choice) {
            case 1:
               // addBook();
                break;
            case 2:
                //displayBooks();
                break;
            case 3:
                //addMember();
                break;
            case 4:
                //issueBook();
                break;
            case 5:
                printf("Adios!!!\n");
                break;
            default:
                printf("Esta no es una opcion valida!!!\n");
                break;
        }
    } while (choice != 5);
    
        
}