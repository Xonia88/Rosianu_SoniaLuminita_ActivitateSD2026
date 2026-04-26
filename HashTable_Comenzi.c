//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Comanda Comanda;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//
//struct Comanda {
//	char* client;
//	int idComanda;
//	float valoare;
//};
//
//struct Nod {
//	Comanda info;
//	Nod* next;
//};
//
//struct HashTable {
//	int dimensiune;
//	Nod** vector;
//};
//
//Comanda initComanda(const char* client, int idComanda, float valoare) {
//	Comanda c;
//	c.idComanda = idComanda;
//	c.valoare = valoare;
//
//	c.client = (char*)malloc(sizeof(char) * (strlen(client) + 1));
//	strcpy(c.client, client);
//
//	return c;
//}
//
//void afisareComanda(Comanda c) {
//	printf("\nComanda clientului %s (id %d) are valoarea %.2f",
//		c.client, c.idComanda, c.valoare);
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareComanda(cap->info);
//		cap = cap->next;
//	}
//}
//
//void inserareLaSfarsit(Nod** cap, Comanda c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = c;
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
//void inserareHashTable(HashTable ht, Comanda c) {
//	if (ht.dimensiune > 0) {
//		int poz = hash(ht.dimensiune, c.idComanda);
//		if (poz >= 0 && poz < ht.dimensiune) {
//			inserareLaSfarsit(&(ht.vector[poz]), c);
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
//float valoareMaximaPozitia1(HashTable ht) {
//	float max = 0;
//	Nod* cap = ht.vector[1];
//
//	while (cap != NULL) {
//		if (cap->info.valoare > max) {
//			max = cap->info.valoare;
//		}
//		cap = cap->next;
//	}
//
//	return max;
//}
//
//void dezalocareLista(Nod** cap) {
//	while (*cap != NULL) {
//		free((*cap)->info.client);
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
//	inserareHashTable(ht, initComanda("Ana", 10, 250));
//	inserareHashTable(ht, initComanda("Ion", 15, 400));
//	inserareHashTable(ht, initComanda("Maria", 21, 600));
//
//	afisareHashTable(ht);
//
//	printf("\n\nValoarea maxima din pozitia 1: %.2f",
//		valoareMaximaPozitia1(ht));
//
//	dezalocareHashTable(ht);
//
//	return 0;
//}