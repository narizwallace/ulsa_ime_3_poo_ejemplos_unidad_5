# ulsa_ime_3_poo_ejemplos_unidad_5

Ejemplos de código de la Unidad V, Aspectos avanzados de la herencia, de Programación Orientada a Objetos. Cada archivo de `src/` es un programa completo e independiente y su prefijo indica la diapositiva correspondiente. La excepción es la diapositiva 40, que usa `include/` porque su tema son los encabezados.

> En un programa real no se comenta cada línea. Aquí se hace como apoyo para aprender.

## Cómo ejecutar

### Desde VSCode

1. Abre la carpeta del repositorio.
2. Abre un archivo de `src/`.
3. Presiona `Cmd + Shift + B` en macOS o `Ctrl + Shift + B` en Windows.

La tarea "Compilar y ejecutar ejemplo" compila el archivo abierto en `build/` y lo ejecuta.

Si VSCode genera una tarea para el depurador, revisa que se ejecute desde la raíz del repositorio y use las mismas banderas: `-Wall -Wextra -std=c++17 -Iinclude`, con la salida en `build/`.

### Desde la terminal en macOS

Ejecuta estos comandos desde la raíz del repositorio:

```bash
mkdir -p build
g++ -Wall -Wextra -std=c++17 -Iinclude src/08_costo_virtual.cpp -o build/08_costo_virtual
./build/08_costo_virtual
```

### Desde la terminal en Windows con PowerShell

Ejecuta estos comandos desde la raíz del repositorio:

```powershell
if (-not (Test-Path build)) { New-Item -ItemType Directory build | Out-Null }
g++ -Wall -Wextra -std=c++17 -Iinclude src/08_costo_virtual.cpp -o build/08_costo_virtual.exe
./build/08_costo_virtual.exe
```

Los tamaños de `sizeof` y el texto de los errores pueden variar según el compilador y el sistema.

## Ejemplos con errores a propósito

Estos programas tienen en su encabezado la marca `ESTE PROGRAMA TIENE UN ERROR A PROPOSITO`. Los errores de compilación van en líneas comentadas, marcadas con `>>> ERROR A PROPOSITO`, para que el programa pueda ejecutarse.

| Archivo | Error | Cómo verlo |
|---|---|---|
| `src/09_inicializacion_llaves.cpp` | Conversion con perdida usando llaves | Quitar el comentario de la linea marcada |
| `src/19_destructor_virtual.cpp` | Destructor no virtual en una clase polimorfica | Advertencia activa al compilar |
| `src/21_overriding.cpp` | Metodo sin const que no redefine a la base | Advertencia activa con g++ 13 o más reciente y con clang; la línea marcada muestra el error de override |
| `src/27_ocultamiento.cpp` | Sobrecarga oculta por la derivada | Quitar el comentario de la linea marcada |
| `src/29_metodos_diferidos.cpp` | Instanciar una clase abstracta | Quitar el comentario de la linea marcada |
| `src/32_ambiguedad_nombres.cpp` | Llamada ambigua a encender | Quitar el comentario de la linea marcada |
| `src/33_diamante.cpp` | Llamada ambigua a getId | Quitar el comentario de la linea marcada |
| `src/38_visibilidad.cpp` | Acceso a miembros no visibles | Quitar el comentario de una linea marcada |

## Índice por bloque

### Fundamentos de memoria

| Diapositiva | Archivo | Tema |
|---|---|---|
| 5 | `src/05_memoria_derivado.cpp` | Un derivado contiene a su base |
| 6-7 | `src/07_orden_construccion.cpp` | Orden de construccion y destruccion |
| 8 | `src/08_costo_virtual.cpp` | El costo de virtual |
| 9 | `src/09_inicializacion_llaves.cpp` | double valor{0} |
| 10 | `src/10_vptr_por_objeto.cpp` | vptr y vtable |
| 11 | `src/11_relleno.cpp` | Relleno |
| 12-13 | `src/13_slicing.cpp` | Slicing |

### Polimorfismo

| Diapositiva | Archivo | Tema |
|---|---|---|
| 15-16 | `src/16_llamada_virtual.cpp` | Con y sin virtual, llamada virtual |
| 17 | `src/17_metodo_no_redefinido.cpp` | Metodo virtual no redefinido |
| 18 | `src/18_vptr_construccion.cpp` | El vptr durante la construccion |
| 19 | `src/19_destructor_virtual.cpp` | Destructor virtual |
| 20 | `src/20_coleccion_polimorfica.cpp` | Colecciones polimorficas |

### Overriding y overloading

| Diapositiva | Archivo | Tema |
|---|---|---|
| 21 | `src/21_overriding.cpp` | Overriding |
| 22 | `src/22_overloading.cpp` | Overloading |
| 23 | `src/23_sobrecarga_operadores.cpp` | Sobrecarga de operadores |
| 24-25 | `src/25_rectangulo.cpp` | Constructores y metodos de Rectangulo |
| 26 | `src/26_overloading_vs_overriding.cpp` | Overloading vs. overriding |
| 27 | `src/27_ocultamiento.cpp` | Ocultamiento de nombres |

### Metodos diferidos

| Diapositiva | Archivo | Tema |
|---|---|---|
| 28-29 | `src/29_metodos_diferidos.cpp` | Metodos diferidos |
| 30 | `src/30_contrato_base.cpp` | El contrato vive en la base |

### Herencia multiple

| Diapositiva | Archivo | Tema |
|---|---|---|
| 31 | `src/31_herencia_multiple.cpp` | Herencia multiple |
| 32 | `src/32_ambiguedad_nombres.cpp` | Ambiguedad de nombres |
| 33 | `src/33_diamante.cpp` | El problema del diamante |
| 34-35 | `src/35_herencia_virtual.cpp` | Herencia virtual |
| 36 | `src/36_cuantos_vptr.cpp` | Cuantos vptr |

### Visibilidad y dependencia

| Diapositiva | Archivo | Tema |
|---|---|---|
| 38 | `src/38_visibilidad.cpp` | Visibilidad en la herencia |
| 39 | `src/39_dependencia.cpp` | Dependencia entre clases |
| 40 | `src/40_declaracion_adelantada.cpp` | Dependencias en los encabezados |
