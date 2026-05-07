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

void adaugaProdusInArbore(Nod** rad, Produs pNou) {
	if (*rad == NULL) {
		Nod* nod = (Nod*)malloc(sizeof(Nod));
		nod->info = pNou;
		nod->st = NULL;
		nod->dr = NULL;
		*rad = nod;
	}
	else {
		if ((*rad)->info.id > pNou.id) {
			adaugaProdusInArbore(&((*rad)->st), pNou);
		}
		if ((*rad)->info.id < pNou.id) {
			adaugaProdusInArbore(&((*rad)->dr), pNou);
		}
	}
}
void afisarePreordine(Nod* rad) {
	if (rad) {
		afisareProdus(rad->info);
		afisarePreordine(rad->st);
		afisarePreordine(rad->dr);
	}
}
int main() {

	Nod* rad = NULL;

	adaugaProdusInArbore(&rad, initProdus(2, 200, "Mouse", "IT"));
	adaugaProdusInArbore(&rad, initProdus(1, 3500, "Laptop", "IT"));
	adaugaProdusInArbore(&rad, initProdus(3, 5000, "Telefon", "Mobile"));

	printf("\nAfisare preordine:\n");
	afisarePreordine(rad);

	return 0;
}