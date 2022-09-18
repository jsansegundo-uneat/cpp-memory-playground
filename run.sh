# Crea la carpeta "build" si existe
[ -d build ] ||  mkdir build

# Archivo ejecutable
TARGET=build/mem-playground

# Borra ejecutable anterior si existe
[ -f $TARGET ] || rm $TARGET

# Compila con opciones dehabilitando optimizaciones
##  -O0 : Sin optimizaciones
##  -Og : Sin pasadas de optimización
##  -fno-stack-protector : Deshabilita la protección del stack
g++ hexview.cpp main.cpp -o $TARGET -Og -O0 -fno-stack-protector

./$TARGET