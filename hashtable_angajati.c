//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Angajat Angajat;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//
//struct Angajat {
//	char* nume;
//	int id;
//	float salariu;
//};
//
//struct Nod {
//	Angajat info;
//	Nod* next;
//};
//
//struct HashTable {
//	int dimensiune;
//	Nod** vector;
//};
//
//Angajat initAngajat(const char* nume, int id, float salariu) {
//	Angajat a;
//	a.id = id;
//	a.salariu = salariu;
//
//	a.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(a.nume, nume);
//
//	return a;
//}
//
//void afisareAngajat(Angajat a) {
//	printf("\nAngajatul %s (ID: %d) are salariul %.2f",
//		a.nume, a.id, a.salariu);
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareAngajat(cap->info);
//		cap = cap->next;
//	}
//}
//
//void inserareLaSfarsit(Nod** cap, Angajat a) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
//	nou->next = NULL;
//
//	if (*cap == NULL) {
//		*cap = nou;
//	}
//	else {
//		Nod* temp = *cap;
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//}
//
//HashTable initHashTable(int dim) {
//	HashTable ht;
//	ht.dimensiune = dim;
//	ht.vector = (Nod**)malloc(sizeof(Nod*) * dim);
//
//	for (int i = 0; i < dim; i++) {
//		ht.vector[i] = NULL;
//	}
//
//	return ht;
//}
//
//int hash(int dim, int id) {
//	return id % dim;
//}
//
//void inserareHashTable(HashTable ht, Angajat a) {
//	if (ht.dimensiune > 0) {
//		int poz = hash(ht.dimensiune, a.id);
//		if (poz >= 0 && poz < ht.dimensiune) {
//			inserareLaSfarsit(&(ht.vector[poz]), a);
//		}
//	}
//}
//
//void afisareHashTable(HashTable ht) {
//	for (int i = 0; i < ht.dimensiune; i++) {
//		printf("\nPozitie %d:", i);
//		afisareLista(ht.vector[i]);
//	}
//}
//
//float calculSalariiPrimaLista(HashTable ht) {
//	float suma = 0;
//	Nod* cap = ht.vector[0];
//
//	while (cap != NULL) {
//		suma += cap->info.salariu;
//		cap = cap->next;
//	}
//
//	return suma;
//}
//
//void dezalocareLista(Nod** cap) {
//	while (*cap != NULL) {
//		free((*cap)->info.nume);
//		Nod* temp = *cap;
//		*cap = (*cap)->next;
//		free(temp);
//	}
//}
//
//void dezalocareHashTable(HashTable ht) {
//	for (int i = 0; i < ht.dimensiune; i++) {
//		dezalocareLista(&(ht.vector[i]));
//	}
//	free(ht.vector);
//}
//
//int main() {
//	HashTable ht = initHashTable(4);
//
//	inserareHashTable(ht, initAngajat("Ana", 10, 3500));
//	inserareHashTable(ht, initAngajat("Ion", 15, 4200));
//	inserareHashTable(ht, initAngajat("Maria", 22, 3900));
//
//	afisareHashTable(ht);
//
//	printf("\n\nSuma salariilor din prima lista: %.2f",
//		calculSalariiPrimaLista(ht));
//
//	dezalocareHashTable(ht);
//
//	return 0;
//}