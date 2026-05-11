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

Produs citireProdusDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	Produs p;

	if (fgets(buffer, 100, file) == NULL) {
		p.id = -1;
		return p;
	}

	char* aux;

	aux = strtok(buffer, sep);
	p.id = atoi(aux);

	p.pret = atof(strtok(NULL, sep));

	aux = strtok(NULL, sep);
	p.nume = (char*)malloc(strlen(aux) + 1);
	strcpy(p.nume, aux);

	aux = strtok(NULL, sep);
	p.categorie = (char*)malloc(strlen(aux) + 1);
	strcpy(p.categorie, aux);

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

Nod* citireArboreDinFisier(const char* numeFisier) {
	Nod* rad = NULL;
	FILE* f = fopen(numeFisier, "r");

	if (f) {
		while (1) {
			Produs p = citireProdusDinFisier(f);
			if (p.id == -1) break;
			adaugaProdusInArbore(&rad, p);
		}
	}

	fclose(f);
	return rad;
}

void afisarePreordine(Nod* rad) {
	if (rad) {
		afisareProdus(rad->info);
		afisarePreordine(rad->st);
		afisarePreordine(rad->dr);
	}
}

Produs getProdusByID(Nod* rad, int id) {
	Produs p;
	p.id = -1;

	if (rad) {
		if (rad->info.id == id) {
			p = rad->info;

			p.nume = (char*)malloc(strlen(rad->info.nume) + 1);
			strcpy(p.nume, rad->info.nume);

			p.categorie = (char*)malloc(strlen(rad->info.categorie) + 1);
			strcpy(p.categorie, rad->info.categorie);
		}

		if (id < rad->info.id) {
			p = getProdusByID(rad->st, id);
		}

		if (id > rad->info.id) {
			p = getProdusByID(rad->dr, id);
		}
	}

	return p;
}

int determinaNumarNoduri(Nod* rad) {
	if (rad) {
		return determinaNumarNoduri(rad->st) +
			determinaNumarNoduri(rad->dr) + 1;
	}
	return 0;
}

int maxim(int a, int b) {
	return (a > b ? a : b);
}

int calculeazaInaltimeArbore(Nod* rad) {
	if (rad) {
		return maxim(calculeazaInaltimeArbore(rad->st),
			calculeazaInaltimeArbore(rad->dr)) + 1;
	}
	return 0;
}

float calculeazaPretTotal(Nod* rad) {
	if (rad) {
		return rad->info.pret +
			calculeazaPretTotal(rad->st) +
			calculeazaPretTotal(rad->dr);
	}
	return 0;
}

float calculeazaPretCategorie(Nod* rad, const char* categorie) {
	if (rad) {
		float suma = calculeazaPretCategorie(rad->st, categorie) +
			calculeazaPretCategorie(rad->dr, categorie);

		if (strcmp(rad->info.categorie, categorie) == 0) {
			suma += rad->info.pret;
		}
		return suma;
	}
	return 0;
}

void dezalocareArbore(Nod** rad) {
	if (*rad) {
		dezalocareArbore(&(*rad)->st);
		dezalocareArbore(&(*rad)->dr);

		free((*rad)->info.nume);
		free((*rad)->info.categorie);

		free(*rad);
		*rad = NULL;
	}
}

int main() {

	Nod* rad = citireArboreDinFisier("produse.txt");

	printf("\nAfisare preordine:\n");
	afisarePreordine(rad);

	printf("\nProdus cautat:\n");
	afisareProdus(getProdusByID(rad, 2));

	printf("\nNr noduri: %d", determinaNumarNoduri(rad));
	printf("\nInaltime: %d", calculeazaInaltimeArbore(rad));
	printf("\nPret total: %.2f", calculeazaPretTotal(rad));
	printf("\nPret categorie IT: %.2f", calculeazaPretCategorie(rad, "IT"));

	dezalocareArbore(&rad);

	return 0;
}