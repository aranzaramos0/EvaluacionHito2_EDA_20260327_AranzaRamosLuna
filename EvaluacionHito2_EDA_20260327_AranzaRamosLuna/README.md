# Sistema de Gestión de Turnos para Estudiantes

**Autor:** Aranza Mayerlin Ramos Luna  
**Fecha:** 27 de marzo de 2026  
**Curso:** Estructuras de Datos

---

## 1. Descripción del Sistema

El presente programa implementa una aplicación de consola en C++ que permite administrar una cola de estudiantes que esperan ser atendidos. La lógica sigue el principio **FIFO** (First In, First Out): el primer estudiante en registrarse es el primero en ser atendido.

El sistema cuenta con un menú interactivo que ofrece las siguientes operaciones:

- **Registrar estudiante:** ingresa nombre y código, y se agrega al final de la cola.
- **Atender estudiante:** elimina al estudiante que lleva más tiempo esperando y muestra sus datos.
- **Mostrar estudiantes en espera:** lista todos los estudiantes en orden de llegada.
- **Buscar estudiante por nombre:** recorre la cola y muestra la posición si el estudiante existe.
- **Salir:** termina la ejecución del programa.

---

## 2. Estructura de Datos Utilizada

Se eligió implementar manualmente una **lista enlazada simple** para modelar la cola. Cada elemento de la lista es un nodo que contiene:

- `nombre` (string)
- `codigo` (string)
- `siguiente` (puntero al siguiente nodo)

Además, la clase `FilaAtencion` mantiene dos punteros especiales:
- `inicio`: apunta al primer nodo (frente de la cola).
- `fin`: apunta al último nodo (final de la cola).

### Justificación

La lista enlazada simple fue seleccionada porque:

1. **Dinamismo:** no existe un límite predefinido de estudiantes, a diferencia de un arreglo estático.
2. **Eficiencia en extremos:** las operaciones de encolar (insertar al final) y desencolar (eliminar al inicio) se realizan en **O(1)**, simplemente actualizando punteros.
3. **Cumple con la restricción técnica:** se implementa manualmente, sin usar contenedores de la STL (`vector`, `list`, etc.).

Si se hubiera usado un arreglo estático, las operaciones de inserción y eliminación en los extremos requerirían desplazar elementos, resultando en **O(n)**. La lista enlazada evita este costo.

---

## 3. Complejidad Algorítmica

| Operación        | Complejidad | Explicación |
|------------------|-------------|-------------|
| **Registrar** (encolar) | O(1) | Se inserta un nuevo nodo al final actualizando el puntero `fin`. |
| **Atender** (desencolar) | O(1) | Se elimina el nodo al inicio actualizando `inicio`. |
| **Mostrar**      | O(n) | Se recorre toda la lista desde el inicio hasta el final. |
| **Buscar por nombre** | O(n) | En el peor caso se recorre la lista completa hasta encontrar el nombre o llegar al final. |

*Nota:* `n` representa la cantidad de estudiantes en la cola.

---

## 4. Instrucciones de Compilación y Ejecución

### Requisitos Previos
- Tener un compilador de C++ (se recomienda `g++`).
- Sistema operativo Windows, Linux o macOS.

### Pasos para compilar y ejecutar

1. **Clonar o descargar** el repositorio y ubicarse en la carpeta que contiene el archivo `main.cpp`.

2. **Abrir una terminal** en dicha carpeta.

3. **Compilar** el programa con el siguiente comando:
   ```bash
   g++ main.cpp -o turnos
   Ejecutar el programa:

En Linux/macOS: ./turnos

En Windows: turnos.exe
Autor/a:
Aranza Mayerlin Ramos Luna
27 de marzo de 2027
