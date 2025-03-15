+++
date = '2025-02-21T10:19:38-08:00'
draft = false
title = 'Practica 0'
+++

<!-- Los comentarios se hacen de esta manera -->
<!-- Encabezados depende el numero de # es el numero de encabezados-->
Como hacer los titlos los titulos solo es necesario agregar un # al principio depende de cuantos # tenga el titulo sera por ejemplo:

# Encabezado 1

## Encabezado 2

### Encabezado 3

#### Encabezado 4

##### Encabezado 5

<!-- como hacer el tipo de letra, ejemplo italicas-->
Este es un texto en italica
<!-- Tambien se puede con guin bajo -->
<!-- como hacer negritas -->
Para poner un texto en Negritas solo basta con poner * al principio y al final 
Este es un texto en *Negritas*
<!-- tambien se puede con doble guion bajo -->

<!-- como tachar -->
Para tachar un texto, solo basta con poner ~ al principio y al final.

Este es un texto ~tachado~
<!-- como hacer listas -->
Para hacer listas no ordenadas, usa un asterisco (*) seguido de un espacio al principio de cada línea de la lista:

* Elemento 1
* Elemento 2
* Elemento 3 <!--Para hacer los subtemas es con tab -->
  * Elemento 3.1
  * Elemento 3.2
* Elemento 4
  
<!-- Como hacer listas ordenadas -->
Para hacer listas ordenadas, usa un número seguido de un punto (.) y un espacio al principio de cada línea de la lista:

1. Elemento 1
1. Elemento 2
1. Elemento 3
   1. Elemento 3.1
   1. Elemento 3.2
1. Elemento 4

<!-- Enlaces -->
Para poder hacer un enlace con un texto solo basta con poner el 
[Texto del enlace](http://www.google.com "Texto del tooltip")


[Texto del enlace](http://www.google.com
"Texto del tooltip")

[UABC](http://www.uabc.mx)

[UABC](http://www.uabc.mx
"Sitio universitario")

<!-- Imagenes -->
Para insertar una imagen, usa la siguiente sintaxis:
```
![Texto alternativo](URL_de_la_imagen "Texto del tooltip")
```

![Texto alternativo](https://imgs.search.brave.com/Q8GmreufhSz-icEVaO3Gbb3JwALvCkuKrC5Ijrzqbeo/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly9zdGF0/aWMubmF0aW9uYWxn/ZW9ncmFwaGljLmVz/L2ZpbGVzL3N0eWxl/cy9pbWFnZV8zMjAw/L3B1YmxpYy83NTU1/Mi5uZ3N2ZXJzaW9u/LjE0MjIyODU1NTMz/NjAud2VicD93PTE2/MDAmaD0xMDY3)



<img src="./images/code.png" alt="uabc image" width="150" height="auto">
<!-- Bloques de codigo -->


Para un bloque de codigo solo es necesario poner ` tres de eses simbolos:

```txt
This is a code block
This is the second line of the code block
```

```python
print("Hola mundo!")
```

```javascript
console.log('Hello world!')

console.test = ()
```

```html
<h1>Hola mundo</h1>
```

<!-- como hacer tablas -->
para hacer una tabla solo debes hacer de esta formas 

```
 | Productos | Precio | Cantidad |
 | - | - | - |
 | Laptop | 3.3| 2 |
 | Mouse | 13.3 | 1 |
```
como resultadora dara 
 | Productos | Precio | Cantidad |
 | - | - | - |
 | Laptop | 3.3| 2 |
 | Mouse | 13.3 | 1 |

Para poder hacerlo de una forma mas limpia seria asi
```
| Productos | Precio | Cantidad |
| --------- | ------ | -------- |
| Laptop    | 3.3    | 2        |
| Mouse     | 13.3   | 1        |
```
quedaria de esta forma:

<!-- Manera limpia -->
| Productos | Precio | Cantidad |
| --------- | ------ | -------- |
| Laptop    | 3.3    | 2        |
| Mouse     | 13.3   | 1        |

<!-- Notas -->
> Esto es una nota

para poder hacer una lista debe ser de esta forma:
```
* [x] Primera tarea
* [ ] Segunda tarea
* [ ] Tercera tarea
  * [x] Tercera y media
* [ ] Cuarta tarea
```
Que dara como resultado: 
<!-- Tareas -->
* [x] Primera tarea
* [ ] Segunda tarea
* [ ] Tercera tarea
  * [x] Tercera y media
* [ ] Cuarta tarea

<!-- Divisores horizontales -->
***  
<!-- Menciones -->
Las menciones se hacen con un @ 
@allan3235 