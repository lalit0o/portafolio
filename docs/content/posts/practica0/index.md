+++
date = '2025-02-21T10:18:14-08:00'
draft = false
title = 'Practica 0'
+++



**Sesion 1:** Sintaxis y uso de markdown
En la primera sesion se hizo uso de Markdown para construir el esqueleto de la pagina estatica de Hugo. Lo realizado en Markdown en la primera sesion fue lo siguiente:
<!--Encabezados-->

# Encabezado 1

## Encabezado 2

### Encabezado 3

#### Encabezado 4

##### Encabezado 5

<!--Italicas-->

Este es un texto en *italica*

Este es un texto en _italica_

<!--Negritas-->

Este es un texto en **negritas**

Este es un texto en __negritas__

<!--Tachado-->
Este es un texto ~~tachado~~

<!--UL-->

* Elemento 1
* Elemento 2
* Elemento 3
  * Elemento 3.1
  * Elemento 3.2
    * Elemento 3.2.1
* Elemento 4


<!--OL-->

1. Elemento 1
1. Elemento 2
1. Elemento 3
   1. Elemento 3.1
   1. Elemento 3.2
1. Elemento 4

<!--Hipervinculos-->
[Texto de enlace](https://www.google.com "Texto de tooltip")

[UABC](https://www.uabc.mx "Sitio Universitario")


<!--Imagenes-->

![Texto alternativo](.\images\Imagen.jpg)

![Logo-VSCode](.\images\Imagen.jpg "Tooltip de la imagen")

[![Escudo de UABC](.\images\Imagen.jpg)](https://www.uabc.mx "Sitio universitario")

<!--Bloques de código-->

```
This is un code block
This is the second line of the code block
```

```python
print("Hola mundo!")
```

```javascript
console.log('Hello world!')

const test= ()
```

```html
<h1>Hola mundo!</h1>
```

<!--Tablas -->

| Productos | Precio    | Cantidad   |
|  -------- |  -------- | ---------- |
| Laptop    | 3.3       |2           |
| Mouse     | 13.3      |1           |


<!-- Notas -->
>Esto es una nota 


<!-- Tareas -->

* [x] Primera tarea 
* [ ] Segunda tarea
* [ ] Tercera tarea 
* [x] Cuarta tarea
  
<!-- Divisores horizontales -->
***
---
___

  
<!-- Menciones -->
@darthrookie :+1: :smile:

---
***
___


**Sesion 2:** Uso de Git y Github

En la segunda sesión se hicieron uso de comandos de Git para iniciar nuestro repositorio, crear commits, usar push para enviar los archivos a nuestro repositorio, etc. Los principales comandos que se utilizaron fueron: init, add, restore, log, status, branch, commit, merge, switch, push, entre otros.

Todo esto para poder hacer el repositorio en donde utilizaremos Hugo para crear nuestra pagina estatica.

---
***
___

**Sesion 3:** Combinar los conocimientos de Markdown y Git para generar páginas estáticas con Hugo y GitHub Actions.

En esta tercera sesion aprendimos a usar Hugo, framework que facilita la creacion de sitios web estáticos, y a automatizar su despliegue con GitHub Actions.

Hugo permite generar páginas web de manera rápida organizando el contenido en carpetas y usando archivos en Markdown para añadir texto e imagenes.

Los comandos que se utilizaron para esta practica fueron: __hugo new site nombre-del -sitio__, este comando sirve para crear la estructura del proyecto en la carpeta content/

__hugo new post/mi-primer-post.md__ Sirve para crear un nuevo post en la pagina

__hugo server__ Sirve para crear el servidor de la pagina

Gracias a Git Bash, pudimos gestionar, hacer commits y conectar el proyecto con GitHub de manera eficiente. Al final, logramos comprender como crear, modificar y desplegar un sitio web estatico utilizando Hugo, GitHub Actions y Git Bash.