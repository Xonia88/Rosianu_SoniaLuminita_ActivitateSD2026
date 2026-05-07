#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produs {
	int id;
	float pret;
	char* nume;
	char* categorie;
};
typedef struct Produs Produs;

struct Nod {
	Produs info;
	struct Nod* st;
	struct Nod* dr;
};
typedef struct Nod Nod;

Produs initProdus(int id, float pret, const char* nume, const char* categorie) {
	Produs p;
	p.id = id;
	p.pret = pret;

	p.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(p.nume, nume);

	p.categorie = (char*)malloc(strlen(categorie) + 1);
	strcpy(p.categorie, categorie);

	return p;
}

void afisareProdus(Produs p) {
	printf("\nId: %d", p.id);
	printf("\nPret: %.2f", p.pret);
	printf("\nNume: %s", p.nume);
	printf("\nCategorie: %s\n", p.categorie);
}

int main() {

	Produs p1 = initProdus(1, 3500, "Laptop", "IT");
	Produs p2 = initProdus(2, 200, "Mouse", "IT");

	afisareProdus(p1);
	afisareProdus(p2);

	free(p1.nume);
	free(p1.categorie);
	free(p2.nume);
	free(p2.categorie);

	return 0;
}