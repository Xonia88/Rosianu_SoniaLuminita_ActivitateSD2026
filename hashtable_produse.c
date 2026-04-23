#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Produs Produs;
typedef struct Nod Nod;
typedef struct HashTable HashTable;

struct Produs {
	char* nume;
	int cod;
	float pret;
};

struct Nod {
	Produs info;
	Nod* next;
};

struct HashTable {
	int dimensiune;
	Nod** vector;
};

Produs initProdus(const char* nume, int cod, float pret) {
	Produs p;
	p.cod = cod;
	p.pret = pret;
	p.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(p.nume, nume);
	return p;
}

void afisareProdus(Produs p) {
	printf("\nProdusul %s (cod %d) are pretul %.2f",
		p.nume, p.cod, p.pret);
}

void afisareLista(Nod* cap) {
	while (cap != NULL) {
		afisareProdus(cap->info);
		cap = cap->next;
	}
}

void inserareLaSfarsit(Nod** cap, Produs p) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = p;
	nou->next = NULL;

	if (*cap == NULL) {
		*cap = nou;
	}
	else {
		Nod* temp = *cap;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = nou;
	}
}

HashTable initHashTable(int dim) {
	HashTable ht;
	ht.dimensiune = dim;
	ht.vector = (Nod**)malloc(sizeof(Nod*) * dim);

	for (int i = 0; i < dim; i++) {
		ht.vector[i] = NULL;
	}

	return ht;
}

int hash(int dim, int cod) {
	return cod % dim;
}

void inserareHashTable(HashTable ht, Produs p) {
	if (ht.dimensiune > 0) {
		int poz = hash(ht.dimensiune, p.cod);
		if (poz >= 0 && poz < ht.dimensiune) {
			inserareLaSfarsit(&(ht.vector[poz]), p);
		}
	}
}

void afisareHashTable(HashTable ht) {
	for (int i = 0; i < ht.dimensiune; i++) {
		printf("\nPozitie %d:", i);
		afisareLista(ht.vector[i]);
	}
}

float sumaPreturiPozitia0(HashTable ht) {
	float suma = 0;
	Nod* cap = ht.vector[0];

	while (cap != NULL) {
		suma += cap->info.pret;
		cap = cap->next;
	}

	return suma;
}

void dezalocareLista(Nod** cap) {
	while (*cap != NULL) {
		free((*cap)->info.nume);
		Nod* temp = *cap;
		*cap = (*cap)->next;
		free(temp);
	}
}

void dezalocareHashTable(HashTable ht) {
	for (int i = 0; i < ht.dimensiune; i++) {
		dezalocareLista(&(ht.vector[i]));
	}
	free(ht.vector);
}

int main() {
	HashTable ht = initHashTable(4);

	inserareHashTable(ht, initProdus("Laptop", 10, 3500));
	inserareHashTable(ht, initProdus("Telefon", 15, 2000));
	inserareHashTable(ht, initProdus("Mouse", 22, 150));

	afisareHashTable(ht);

	printf("\n\nSuma preturilor din pozitia 0: %.2f",
		sumaPreturiPozitia0(ht));

	dezalocareHashTable(ht);

	return 0;
}