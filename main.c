#include <stdio.h>
#include <string.h>

#define Total_productos 6
#define Limite_carrito 50

typedef struct {
    int id;
    char nombre[30];
    int precio;
} Producto;

typedef struct {
    Producto producto;
    int cantidad;
} ItemCarrito;

int main() {
    Producto catalogo[Total_productos] = {
        {1, "Pan", 4000},
        {2, "Leche", 5000},
        {3, "Huevos", 12000},
        {4, "Arroz", 6000},
        {5, "Cafe", 10000},
        {6, "Queso", 8500}
    };

    ItemCarrito carrito[Limite_carrito];
    int carritoSize = 0;
    int opcion;
    int total = 0;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ver lista de productos\n");
        printf("2. Agregar producto al carrito\n");
        printf("3. Ver carrito\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("\n--- LISTA DE PRODUCTOS ---\n");
            for (int i = 0; i < Total_productos; i++) {
                printf("%d. %s - %d\n", catalogo[i].id, catalogo[i].nombre, catalogo[i].precio);
            }

        } else if (opcion == 2) {
            int id, cantidad;
            printf("\nIngrese el ID del producto: ");
            scanf("%d", &id);

            int encontrado = -1;
            for (int i = 0; i < Total_productos; i++) {
                if (catalogo[i].id == id) {
                    encontrado = i;
                    break;
                }
            }

            if (encontrado == -1) {
                printf("No existe ese producto.\n");
            } else {
                printf("Cantidad: ");
                scanf("%d", &cantidad);
                if (cantidad <= 0) {
                    printf("Cantidad invalida.\n");
                } else {
                    carrito[carritoSize].producto = catalogo[encontrado];
                    carrito[carritoSize].cantidad = cantidad;
                    carritoSize++;
                    printf("Producto agregado al carrito.\n");
                }
            }

        } else if (opcion == 3) {
            // Ver carrito
            printf("\n--- CARRITO ---\n");
            total = 0;
            for (int i = 0; i < carritoSize; i++) {
                int subtotal = carrito[i].producto.precio * carrito[i].cantidad;
                total += subtotal;
                printf("%d x %s - %d\n",
                       carrito[i].cantidad,
                       carrito[i].producto.nombre,
                       subtotal);
            }
            printf("Total: %d\n", total);

        } else if (opcion == 4) {
            // Confirmar pedido
            if (carritoSize == 0) {
                printf("El carrito esta vacio, no se puede confirmar.\n");
            } else {
                printf("\n--- RESUMEN DE PEDIDO ---\n");
                total = 0;
                for (int i = 0; i < carritoSize; i++) {
                    int subtotal = carrito[i].producto.precio * carrito[i].cantidad;
                    total += subtotal;
                    printf("%d x %s - %d\n",
                           carrito[i].cantidad,
                           carrito[i].producto.nombre,
                           subtotal);
                }

                int costoDomicilio = 3000;
                total += costoDomicilio;

                printf("Costo de domicilio: %d\n", costoDomicilio);
                printf("Total a pagar: %d\n", total);
                printf("Pedido confirmado. ¡Gracias por su compra!\n");

                carritoSize = 0; // Vaciar carrito
            }
        } else if (opcion == 5) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}
