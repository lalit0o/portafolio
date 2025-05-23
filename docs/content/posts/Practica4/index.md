+++
date = '2025-05-23T10:18:14-08:00'
draft = false
title = 'Practica 4'
+++


***Sesion 1***

En la primera sesión se realizó la instalación e introducción a Prolog.

[Prolog](https://www.swi-prolog.org/download/stable "Descargar Prolog")

Prolog, como su propio nombre sugiere, es la forma corta de PROgramación LÓGICA. Es un lenguaje de programación lógico y declarativo. 

La Programación Lógica es uno de los Paradigmas de Programación Informática, en el que las declaraciones del programa expresan los hechos y las reglas sobre diferentes problemas dentro de un sistema de lógica formal.


# ¿Qué es prolog? #

Prolog o PROgritando REGISTROics es un lenguaje de programación lógico y declarativo. Es un ejemplo importante del lenguaje de cuarta generación que apoya el paradigma de programación declarativa. Esto es particularmente adecuado para programas que involucran simbólico o cálculo no numérico. Esta es la razón principal para usar Prolog como lenguaje de programación en Inteligencia Articifial, donde manipulación de símbolos y manipulación de inferencia son las tareas fundamentales.

En prolog, no necesitamos mencionar la forma en que se puede resolver un problema, solo necesitamos mencionar cuál es el problema, para que Prolog lo resuelva automáticamente. Sin embargo, en Prolog se supone que debemos dar pistas como el método de solución.

En lenguaje Prolog básicamente tiene tres elementos diferentes -

**Hechos -** El hecho es predicado que es cierto, por ejemplo, si decimos, â ?? Tom es el hijo de Jackâ ??, entonces esto es un hecho.

**Reglas -** Las reglas son extinciones de hechos que contienen cláusulas condicionales. Para cumplir una regla, se deben cumplir estas condiciones. Por ejemplo, si definimos una regla como - 

```prolog

grandfather(X, Y) :- father(X, Z), parent(Z, Y)

```

Esto implica que para que X sea el abuelo de Y, Z debe ser padre de Y y X debe ser padre de Z

**Preguntas -** Y para ejecutar un programa de prólogo, necesitamos algunas preguntas, y esas preguntas pueden ser respondidas por los hechos y las reglas dadas.