# CADENAS
## Problemario 8 - Programacion 1

 1. Escriba un programa que lea una frase, y a continuación visualice cada palabra de la frase en una línea distinta, seguido del número de letras que compone cada palabra.

2. Escriba un programa en C que dada una cadena de caracteres permita sustituir todas las ocurrencias de una subcadena. Ejemplo:

- **Cadena**: Este problema es más interesante que el problema anterior.
- **Vieja Subcadena**: problema 
- **Nueva Subcadena**: programa 
- **Cadena Resultado**: Este programa es más interesante que el programa anterior.

	El programa debe contar con una función que reciba una cadena de caracteres y una palabra, deberá sustituir cada aparición de la palabra por una nueva, pasada también como parámetro. El prototipo adecuado podría ser:

    `int buscarReemplazar(char frase[], char viejaCadena[], char nuevaCadena[]);`

La función devolverá el número de reemplazos de ‘viejaCadena’ en frase.

3. Escriba un programa para jugar al ahorcado. El programa debe elegir una palabra (que pueda codificarse directamente en el programa) y mostrar lo siguiente:

`Adivine la palabra: XXXXX`

Cada X representa a una letra. Si el usuario adivina correctamente, el programa debe mostrar: **¡Felicidades! Usted pudo adivinar mi palabra. ¿Desea jugar otra vez? Sí/No**

Debe introducir la respuesta Sí o No apropiada. Si el usuario no adivina correctamente, debe mostrarse la parte del cuerpo apropiada. Después de 7 intentos fallidos, el usuario debe ser colgado. La pantalla debe verse así:

	```
	  +---+
	  |   |
	  O   |
	 /|\  |
	 / \  |
	      |
	=========
	```

4. Escriba un programa que determine si dos cadenas introducidas por teclado son anagramas. Se considera que dos cadenas son anagramas si contienen exactamente los mismos caracteres, ya sea en el mismo o en diferente orden: ignorar los blancos y considerar que mayúsculas y minúsculas son iguales.

5.  Escriba un programa que lea una cadena e imprima la cadena en minúsculas también y mayúsculas.

