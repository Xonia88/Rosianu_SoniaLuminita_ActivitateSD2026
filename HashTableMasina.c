#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>



//Exersare cod pentru lucrare practica dupa model seminar

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

void afisareMasina(Masina masina) {
	printf("Masina %d: %s, %d usi, %.2f RON, sofer: %s, serie: %c\n",
		masina.id, masina.model, masina.nrUsi,
		masina.pret, masina.numeSofer, masina.serie);
}

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";

	fgets(buffer, 100, file);

	char* aux;
	Masina m1;

	aux = strtok(buffer, sep);
	m1.id = atoi(aux);

	m1.nrUsi = atoi(strtok(NULL, sep));

	m1.pret = (float)atof(strtok(NULL, sep));

	aux = strtok(NULL, sep);
	m1.model = (char*)malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);

	return m1;
}

struct Nod {
	Masina masina;
	struct Nod* next;
};
typedef struct Nod Nod;

struct HashTable {
	int dim;
	Nod** tabela;
};
typedef struct HashTable HashTable;

HashTable initializareHashTable(int dimensiune) {
	HashTable ht;

	ht.dim = dimensiune;

	ht.tabela = (Nod**)malloc(sizeof(Nod*) * dimensiune);

	for (int i = 0; i < dimensiune; i++) {
		ht.tabela[i] = NULL;
	}

	return ht;
}

int calculeazaHash(const char* numeSofer, int dimensiune) {
	int suma = 0;

	if (numeSofer != NULL) {

		for (int i = 0; i < strlen(numeSofer); i++) {
			suma += numeSofer[i];
		}
	}

	return suma % dimensiune;
}

void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {

	Nod* nou = (Nod*)malloc(sizeof(Nod));

	nou->masina = masinaNoua;
	nou->next = NULL;

	if (*cap) {

		Nod* aux = *cap;

		while (aux->next) {
			aux = aux->next;
		}

		aux->next = nou;
	}
	else {

		*cap = nou;
	}
}

void inserareMasinaInTabela(HashTable hash, Masina masina) {

	int poz = calculeazaHash(masina.numeSofer, hash.dim);

	adaugaMasinaInLista(&(hash.tabela[poz]), masina);
}

HashTable citireMasiniDinFisierTabela(
	const char* numeFisier,
	int dimensiune) {

	HashTable ht = initializareHashTable(dimensiune);

	FILE* f = fopen(numeFisier, "r");

	if (f) {

		while (!feof(f)) {

			Masina m = citireMasinaDinFisier(f);

			if (m.id > 0) {

				inserareMasinaInTabela(ht, m);
			}
		}

		fclose(f);
	}

	return ht;
}

void afisareListaMasini(Nod* cap) {

	while (cap) {

		afisareMasina(cap->masina);

		cap = cap->next;
	}
}

void afisareTabelaDeMasini(HashTable ht) {

	for (int i = 0; i < ht.dim; i++) {

		if (ht.tabela[i] != NULL) {

			printf("Clusterul de pe pozitia %d:\n", i);

			afisareListaMasini(ht.tabela[i]);
		}
	}
}

Masina getMasinaPretMinim(HashTable ht) {

	Masina minim;

	minim.pret = FLT_MAX;

	for (int i = 0; i < ht.dim; i++) {

		Nod* p = ht.tabela[i];

		while (p) {

			if (p->masina.pret < minim.pret) {

				minim = p->masina;
			}

			p = p->next;
		}
	}

	return minim;
}

void dezalocareTabelaDeMasini(HashTable* ht) {

	for (int i = 0; i < ht->dim; i++) {

		Nod* p = ht->tabela[i];

		while (p) {

			Nod* aux = p;

			p = p->next;

			free(aux->masina.model);
			free(aux->masina.numeSofer);

			free(aux);
		}
	}

	free(ht->tabela);

	ht->tabela = NULL;
	ht->dim = 0;
}

int main() {

	HashTable ht =
		citireMasiniDinFisierTabela("masini.txt", 7);

	afisareTabelaDeMasini(ht);

	printf("\nMasina cu pret minim:\n");

	Masina minim = getMasinaPretMinim(ht);

	afisareMasina(minim);

	dezalocareTabelaDeMasini(&ht);

	return 0;
}