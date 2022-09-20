# Playground de datos en memoria

Este proyecto es un espacio para comprobar como se despliegan los datos en la memoria. 
Se ha elegido C (con algo de C++) porque no usa ninguna abstracción y encontramos los
bytes de cada variable en memoria "sin aditivos".

## Vista de memoria

Se ha creado una función `hex_view_memory` que acepta un puntero a memoria. La función pinta
48 bytes en base a la dirección dada. Los bloques siempre se alinean a las posiciones 
de memoria múltiplo de 16, empezando por la anterior al puntero dado.

```
Start memory at: 0x7ffcbfcabca9
                  0    1    2    3    4    5    6    7      8    9    A    B    C    D    E    F
0x7ffcbfcabca0   0x80 0xbc 0xca 0xbf 0xfc 0x4a 0x75 0x61   0x6e 0x01 0x02 0x03 0x00 0x00 0x00 0x16
0x7ffcbfcabcb0   0xc0 0xbc 0xca 0xbf 0xfc 0x7f 0x00 0x00   0x89 0x93 0x09 0x87 0x07 0x56 0x00 0x00
0x7ffcbfcabcc0   0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00   0x83 0xa0 0x39 0x0c 0x55 0x7f 0x00 0x00
```

## NOTA: orden de las variables

En principio, podemo suponer que los bytes de variables locales en una función,
se despliegan en el mismo orden en el que se definen. Para asegurar más esto, 
se han desabilitado la mayoría de las optimizaciones, siemplemente para
que la observación de la memoría se ajuste más al concepto "ideal". 

Pero puede que, tras cambiar el código, veamos el orden de los bytes de las variables
locales en orden diferente. Aún quitando las optimizaciones, parece que el compilador
sigue haciendo de las suyas. Una opción para que respete este orden es encerrar las variables
en una estructura (`struct`). 