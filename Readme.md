# SISTEMAS OPERATIVOS 2021: LABORATORIO 2: XV6-VGA

## Grupo 5:
* Arias, Eliana - eliana.arias@mi.unc.edu.ar
* Leiva, Mauro - mauro.leiva@mi.unc.edu.ar
* Toyos, Milagros - milagros.toyos@mi.unc.edu.ar

## Modo de trabajo

Cada uno de los integrantes del grupo colaboró con el trabajo usando su computadora y programando en tiempo real conectados por Google meet, grupo en Whatsapp y docs de Google.

## Modo de uso

Pueden ejecutarse los tests provistos por la cátedra con los siguientes comandos (desde el directorio principal):

> $ make qemu

y una vez dentro de qemu, ejecutamos los archivos de dibujo:

> $ lluvia

> $ sonic

> $ rex

#### Proceso de desarrollo

## Parte 1
Para cumplir con el objetivo de esta parte, primero implementamos en **console.c** vga_init() imprime el mensaje "SO2021" por pantalla, para ello usamos la siguiente documentación para conocer el address space correspondiente al modo texto.

## Parte 2
Leyendo la documentación que nos fue proporcionada en el enunciado pudimos obtener los arreglos que contienen los valores para setear los registros y así hacer correctamente el cambio de modo texto/gráfico

## Parte 3
Aquí creamos Syscalls para hacer efectivo el cambio de modo, y la impresión de píxeles. Para ello se utilizó el comando grep que nos ayudó a saber donde añadir nuestras nuevas Syscalls y luego seguimos el formato que tenía cada llamada a sistema en los diferentes archivos.

- Syscall modeswitch(): cambia de modo texto a modo gráfico y viceversa según su argumento de entrada. Esta syscall toma un entero, el cual nos cambia a modo texto si es 0 o modo gráfico si es 1.

- Syscall plotpixel(): en el modo gráfico, recibe como argumento las coordenadas de un pixel y un color y pinta dicho pixel del color recibido como argumento.


## Parte 4
Creamos un dibujo en el archivo **sonic.c**, otro en **lluvia.c** y otro en **rex.c**. Para ello teníamos que dibujar pixel por pixel en pantalla; una forma de hacer esto fue usando la función plotrectangle(), que nos ahorró muchas líneas de código permitiéndonos realizar un dibujo de tamaño más grande. Además seguimos la siguiente documentación:
https://commons.wikimedia.org/wiki/File:EGA_Table.svg
para tener una referencia sobre la paleta de colores que estábamos usando.

#### Extras
- Modularizamos creando los archivos **vga.c, vga.h**
- Implementación de la syscall **plotrectangle()**

## Modularización
Para poder hacer más legible el código en esta parte hicimos la Modularización y creamos dos archivos,los cuales son **vga.h** y  **vga.c**. En este último se implementaron todas las funciones relacionadas al cambio de modo texto/gráfico y el dibujo en pixeles:
- modeswitch(), plotpixel(), plotrectangle()
Además contiene la definición de dos arreglos:
- t_80x25[] es un arreglo con bytes utilizados para modificar los registros para el modo texto
- g_320x200x4[] es un arreglo con bytes utilizados para modificar los registros para el modo gráfico
