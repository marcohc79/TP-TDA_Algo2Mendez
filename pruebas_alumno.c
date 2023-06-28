#include "pa2m.h"
#include "src/lista.h"
#include "src/cola.h"
#include "src/pila.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TOPE 5

int elemento_es_d(void *_elemento, void *contexto)
{
	char *elemento = _elemento;
	if (elemento && *elemento == *(char *)contexto)
		return 0;
	return -1;
}

bool cantidad_elementos_iterados(void *elemento, void *contador)
{
	if (elemento && contador)
		(*(size_t *)contador)++;
	return true;
}

void pruebas_pilas_vacia_nula()
{
	pila_t *pila = pila_crear();
	char c = 'w';
	pa2m_afirmar(pila != NULL, "Pila creada.");
	pa2m_afirmar(pila_apilar(NULL, &c) == NULL, "Apilar en una pila nula.");
	pa2m_afirmar(pila_desapilar(NULL) == pila_desapilar(pila),
		     "Desapilar pila vacia o nula.");
	pa2m_afirmar(pila_tamanio(NULL) == pila_tamanio(pila),
		     "Sin tamanio pila vacia o nula..");
	pa2m_afirmar(pila_tope(NULL) == pila_tope(pila),
		     "Sin tope pila vacia o nula.");
	pa2m_afirmar(pila_vacia(NULL) == pila_vacia(pila), "Pila vacia");
	pila_destruir(pila);
}

void pruebas_generales_pila()
{
	pila_t *pila = pila_crear();
	char letras[5] = { 'a', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < TOPE; i++)
		pila_apilar(pila, &letras[i]);

	pa2m_afirmar(pila_tope(pila) == &letras[4],
		     "Ultimo elemento apilado es correcto correcto.");
	pa2m_afirmar(pila_tamanio(pila) == TOPE, "Tamanio correcto.");

	for (int i = 0; i < TOPE; i++)
		pa2m_afirmar(pila_desapilar(pila) == &letras[TOPE - 1 - i],
			     "Desapilando OK.");

	pa2m_afirmar(pila_desapilar(pila) == NULL, "Pila sin elementos.");
	pa2m_afirmar(pila_desapilar(pila_apilar(pila, &letras[2])) ==
			     &letras[2],
		     "Apilar y desapilar.");
	pila_destruir(pila);
}

void pruebas_cola_vacia_nula()
{
	cola_t *cola = cola_crear();
	char c = 'w';
	pa2m_afirmar(cola != NULL, "Cola creada.");
	pa2m_afirmar(cola_encolar(NULL, &c) == NULL, "Encolar en cola nula.");
	pa2m_afirmar(cola_desencolar(NULL) == cola_desencolar(cola),
		     "Desencolar en cola vacia o nula.");
	pa2m_afirmar(cola_frente(NULL) == cola_frente(cola),
		     "Cola sin frente.");
	pa2m_afirmar(cola_tamanio(NULL) == cola_tamanio(cola),
		     "Tamanio cola vacia o nula.");
	pa2m_afirmar(cola_vacia(NULL) == cola_vacia(cola),
		     "Cola nula vacia o nula.");
	cola_destruir(cola);
}

void pruebas_generales_cola()
{
	cola_t *cola = cola_crear();
	char letras[TOPE] = { 'a', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < TOPE; i++)
		cola_encolar(cola, &letras[i]);

	pa2m_afirmar(cola_tamanio(cola) == TOPE,
		     "Tamanio correcto luego de encolar");
	pa2m_afirmar(cola_vacia(cola) == false, "Cola no vacia.");
	pa2m_afirmar(cola_frente(cola) == &letras[0], "Frente de cola.");

	for (int i = 0; i < TOPE; i++) {
		pa2m_afirmar(cola_desencolar(cola) == &letras[i],
			     "Desencolamiento OK");
	}
	pa2m_afirmar(cola_desencolar(cola) == NULL,
		     "No hay mas elementos para desencolar.");
	pa2m_afirmar(cola_desencolar(cola_encolar(cola, &letras[0])) ==
			     &letras[0],
		     "Se encola y  desencola.");
	cola_destruir(cola);
}

void pruebas_lista_vacia_nula()
{
	lista_t *lista = lista_crear();
	char c = 'w';
	pa2m_afirmar(lista != NULL, "Lista creada.");
	pa2m_afirmar(lista_insertar(NULL, &c) ==
			     lista_insertar_en_posicion(NULL, &c, 0),
		     "No se puede insertar en una lista nula.");
	pa2m_afirmar(lista_quitar(NULL) == lista_quitar_de_posicion(NULL, 0),
		     "No se puede quitar en una lista nula.");
	pa2m_afirmar(lista_quitar(lista) == lista_quitar_de_posicion(lista, 0),
		     "No se puede quitar en una lista vacia.");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) ==
			     lista_elemento_en_posicion(NULL, 2),
		     "No hay elementos en lista vacia o nula.");
	lista_destruir(lista);
}

void pruebas_insercion_lista()
{
	lista_t *lista = lista_crear();
	char letras[TOPE] = { 'a', 'b', 'c', 'd', 'e' };
	char letras_2[TOPE + 2] = { 'g', 'a', 'h', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < TOPE; i++)
		lista_insertar(lista, &letras[i]);

	pa2m_afirmar(lista_tamanio(lista) == TOPE, "Tamanio correcto.");
	pa2m_afirmar(lista_primero(lista) == &letras[0], "Posicion inicial.");
	pa2m_afirmar(lista_ultimo(lista) == &letras[4], "Posicion final.");
	pa2m_afirmar(lista_primero(lista_insertar_en_posicion(
			     lista, &letras_2[0], 0)) == &letras_2[0],
		     "Se inserta al principio de la lista.");
	pa2m_afirmar(lista_insertar_en_posicion(lista, &letras_2[2], 2) != NULL,
		     "Se inserta en el medio de la lista.");
	pa2m_afirmar(lista_tamanio(lista) == (TOPE + 2), "Tamanio modificado.");

	for (size_t i = 0; i <= TOPE + 1; i++)
		pa2m_afirmar(*(char *)lista_elemento_en_posicion(lista, i) ==
				     letras_2[i],
			     "La insercion no modifico la posición.");

	lista_destruir(lista);
}

void pruebas_quitar_elementos_lista()
{
	lista_t *lista = lista_crear();
	char letras[TOPE] = { 'a', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < TOPE; i++)
		lista_insertar(lista, &letras[i]);

	pa2m_afirmar(lista_quitar(lista) == &letras[4],
		     "Se remueve el ultimo elemento.");
	pa2m_afirmar(lista_tamanio(lista) == (TOPE - 1),
		     "Se actualiza el tamanio de la lista.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 2) == &letras[2],
		     "Se remueve el elemento de la segunda posicion.");
	pa2m_afirmar(lista_tamanio(lista) == (TOPE - 2),
		     "Se actualiza el tamanio de la lista.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 0) == &letras[0],
		     "Se remueve el primer elemento.");
	pa2m_afirmar(lista_tamanio(lista) == (TOPE - 3),
		     "Se actualiza el tamanio de la lista.");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 9) == &letras[3],
		     "Se remueve elemento con posicion no existente.");
	pa2m_afirmar(lista_tamanio(lista) == (TOPE - 4),
		     "Se actualiza el tamanio de la lista.");

	pa2m_afirmar(lista_quitar(lista) == &letras[1],
		     "Se remueve el unico elemento.");
	pa2m_afirmar(lista_tamanio(lista) == (TOPE - 5),
		     "Se actualiza el tamanio de la lista.");

	pa2m_afirmar(lista_quitar(lista) == NULL,
		     "No se pueden quitar mas elementos.");
	pa2m_afirmar(lista_tamanio(lista) == 0,
		     "Se actualiza el tamanio de la lista.");

	lista_destruir(lista);
}

void pruebas_lista_destruir_todo()
{
	lista_t *lista = lista_crear();

	lista_insertar(lista, malloc(sizeof(int)));
	lista_insertar(lista, malloc(sizeof(int)));
	lista_insertar(lista, malloc(sizeof(int)));
	lista_insertar(lista, malloc(sizeof(int)));
	lista_insertar(lista, malloc(sizeof(int)));

	pa2m_afirmar(lista_tamanio(lista) == TOPE, "Se inserto correctamente.");
	lista_destruir_todo(lista, free);
}

void prueba_lista_buscar_elemento()
{
	lista_t *lista = lista_crear();
	char letras[TOPE] = { 'a', 'b', 'c', 'd', 'e' };
	char c = 'y';

	pa2m_afirmar(lista_buscar_elemento(lista, elemento_es_d, &letras[3]) ==
			     NULL,
		     "No se puede buscar en lista vacia.");

	for (int i = 0; i < TOPE; i++)
		lista_insertar(lista, &letras[i]);

	pa2m_afirmar(lista_buscar_elemento(NULL, elemento_es_d, &letras[3]) ==
			     NULL,
		     "No se puede buscar en lista nula.");
	pa2m_afirmar(lista_buscar_elemento(lista, NULL, &letras[3]) == NULL,
		     "No se puede buscar con lista nula.");

	pa2m_afirmar(lista_buscar_elemento(lista, elemento_es_d, &letras[4]) ==
			     &letras[4],
		     "Elemento encontrado.");
	pa2m_afirmar(lista_buscar_elemento(lista, elemento_es_d, &c) == NULL,
		     "No se puede encontrar el elemento.");
	lista_destruir(lista);
}

void pruebas_iterador_externo_lista_vacia_nula()
{
	lista_t *lista = lista_crear();
	lista_iterador_t *iterador = NULL;
	pa2m_afirmar((iterador = lista_iterador_crear(NULL)) == NULL,
		     "No se puede crear itirador con lista nulla.");
	pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL,
		     "Puede crear iterador con lista vacia.");
	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void pruebas_iterador_externo_lista()
{
	lista_t *lista = lista_crear();
	lista_iterador_t *iterador = NULL;
	size_t j = 0;
	char letras[TOPE] = { 'a', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < TOPE; i++)
		lista_insertar(lista, &letras[i]);

	printf("Elementos de la lista: \n");
	for (iterador = lista_iterador_crear(lista);
	     lista_iterador_tiene_siguiente(iterador);
	     lista_iterador_avanzar(iterador)) {
		pa2m_afirmar(*(char *)lista_iterador_elemento_actual(
				     iterador) == letras[j],
			     "Elemento de la lista OK.");
		j++;
	}
	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void pruebas_iterador_interno_lista_vacia_nula()
{
	size_t contexto = 0;
	pa2m_afirmar(lista_con_cada_elemento(NULL, cantidad_elementos_iterados,
					     &contexto) == 0,
		     "Lista nula.");

	lista_t *lista = lista_crear();

	pa2m_afirmar(lista_con_cada_elemento(lista, cantidad_elementos_iterados,
					     &contexto) == 0,
		     "Lista vacia.");
	pa2m_afirmar(lista_con_cada_elemento(lista, NULL, &contexto) == 0,
		     "Funcion nula.");
	lista_destruir(lista);
}

void pruebas_iterador_interno_lista()
{
	lista_t *lista = lista_crear();
	size_t contador = 0;
	char letras[TOPE] = { 'a', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < TOPE; i++)
		lista_insertar(lista, &letras[i]);

	pa2m_afirmar(lista_con_cada_elemento(lista, cantidad_elementos_iterados,
					     &contador) == TOPE,
		     "Se itero internamente con todos los elementos.");
	lista_destruir(lista);
}

void pruebas_para_lista()
{
	pa2m_nuevo_grupo("Pruebas lista vacia o nula.");
	pruebas_lista_vacia_nula();

	pa2m_nuevo_grupo("Pruebas de insercion de elementos en la lista.");
	pruebas_insercion_lista();

	pa2m_nuevo_grupo("Pruebas para quitar elementos en la lista.");
	pruebas_quitar_elementos_lista();

	pa2m_nuevo_grupo("Pruebas operacion destruir todo.");
	pruebas_lista_destruir_todo();

	pa2m_nuevo_grupo("Pruebas para lista buscar elemento.");
	prueba_lista_buscar_elemento();

	pa2m_nuevo_grupo("Pruebas iterador externo con lista vacia o nula.");
	pruebas_iterador_externo_lista_vacia_nula();

	pa2m_nuevo_grupo("Pruebas iterador externo con lista no nula o vacia.");
	pruebas_iterador_externo_lista();

	pa2m_nuevo_grupo(
		"Pruebas iterador interno con algun elemento nulo o vacio.");
	pruebas_iterador_interno_lista_vacia_nula();

	pa2m_nuevo_grupo("Pruebas iterador interno.");
	pruebas_iterador_interno_lista();
}

void pruebas_para_pila()
{
	pa2m_nuevo_grupo("Pruebas pila vacia o nula.");
	pruebas_pilas_vacia_nula();

	pa2m_nuevo_grupo("Pruebas generales pila.");
	pruebas_generales_pila();
}

void pruebas_para_cola()
{
	pa2m_nuevo_grupo("Prueba cola vacia o nula.");
	pruebas_cola_vacia_nula();

	pa2m_nuevo_grupo("Pruebas generales cola.");
	pruebas_generales_cola();
}
int main()
{
	pa2m_nuevo_grupo("PRUEBAS CON LA LISTA");
	pruebas_para_lista();
	pa2m_nuevo_grupo("PRUEBAS CON LA PILA");
	pruebas_para_pila();
	pa2m_nuevo_grupo("PRUEBAS CON LA COLA");
	pruebas_para_cola();

	return pa2m_mostrar_reporte();
}
