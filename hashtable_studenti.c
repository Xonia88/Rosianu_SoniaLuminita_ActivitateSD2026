#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Student Student;
typedef struct Nod Nod;
typedef struct HashTable HashTable;

struct Student {
	char* nume;
	int grupa;
	float medie;
};

struct Nod {
	Student info;
	Nod* next;
};

struct HashTable {
	int dimensiune;
	Nod** vector;
};

Student initStudent(const char* nume, int grupa, float medie) {
	Student s;
	s.grupa = grupa;
	s.medie = medie;

	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(s.nume, nume);

	return s;
}

void afisareStudent(Student s) {
	printf("\nStudentul %s (grupa %d) are media %.2f",
		s.nume, s.grupa, s.medie);
}

void afisareLista(Nod* cap) {
	while (cap != NULL) {
		afisareStudent(cap->info);
		cap = cap->next;
	}
}

void inserareLaSfarsit(Nod** cap, Student s) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = s;
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

int hash(int dim, int grupa) {
	return grupa % dim;
}

void inserareHashTable(HashTable ht, Student s) {
	if (ht.dimensiune > 0) {
		int poz = hash(ht.dimensiune, s.grupa);
		if (poz >= 0 && poz < ht.dimensiune) {
			inserareLaSfarsit(&(ht.vector[poz]), s);
		}
	}
}

void afisareHashTable(HashTable ht) {
	for (int i = 0; i < ht.dimensiune; i++) {
		printf("\nPozitie %d:", i);
		afisareLista(ht.vector[i]);
	}
}

float calculMediePrimaLista(HashTable ht) {
	float suma = 0;
	int nr = 0;

	Nod* cap = ht.vector[0];

	while (cap != NULL) {
		suma += cap->info.medie;
		nr++;
		cap = cap->next;
	}

	if (nr > 0) {
		return suma / nr;
	}
	return 0;
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

	inserareHashTable(ht, initStudent("Ana", 101, 8.5));
	inserareHashTable(ht, initStudent("Ion", 102, 7.2));
	inserareHashTable(ht, initStudent("Maria", 105, 9.1));

	afisareHashTable(ht);

	printf("\n\nMedia din prima lista: %.2f",
		calculMediePrimaLista(ht));

	dezalocareHashTable(ht);

	return 0;
}