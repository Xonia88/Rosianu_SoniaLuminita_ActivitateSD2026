#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Medicament {
	int id;
	int stoc;
	float pret;
	char* denumire;
	char* producator;
	unsigned char tip;

};

typedef struct Medicament Medicament;

struct Nod{
	Medicament info;
	struct Nod* st;
	struct Nod* dr;

};

typedef struct Nod Nod;

Medicament citireMedicamentDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Medicament m;

	aux = strtok(buffer, sep);
	m.id = atoi(aux);

	m.stoc = atoi(strtok(NULL, sep));
	m.pret = atoi(strtok(NULL, sep));


	aux = strtok(NULL, sep);
	m.denumire = (char*)malloc(strlen(aux) + 1);
	strcpy(m.denumire, aux);

	aux = strtok(NULL, sep);
	m.producator = (char*)malloc(strlen(aux) + 1);
	strcpy(m.producator, aux);

	m.tip = *strtok(NULL, sep);

	return m;
}


void afisareMedicament(Medicament m) {
	printf("Id: %d\n", m.id);
	printf("Stoc: %d\n", m.stoc);
	printf("Pret: %.2f\n", m.pret);
	printf("Denumire: %s\n", m.denumire);
	printf("Producator: %s\n", m.producator);
	printf("Tip: %c\n\n", m.tip);
}

void adaugaMedicamentInArbore(Nod** rad, Medicament mNou) {
	if (*rad == NULL) {
		Nod* nod = malloc(sizeof(Nod));
		nod->info = mNou;
		nod->st = NULL;
		nod->dr = NULL;
		*rad = nod;
	}
	else {
		if ((*rad)->info.id > mNou.id) {
			adaugaMedicamentInArbore(&((*rad)->st), mNou);
		}
		if ((*rad)->info.id < mNou.id) {
			adaugaMedicamentInArbore(&((*rad)->dr), mNou);
		}
	}
}

Nod* citireArboreMedicamenteDinFisier(const char* numeFisier) {
	Nod* rad = NULL;
	FILE* f = fopen(numeFisier, "r");

	if (f) {
		while (!feof(f)) {
			Medicament m = citireMedicamentDinFisier(f);
			adaugaMedicamentInArbore(&rad, m);
		}
	}

	fclose(f);
	return rad;
}

void afisarePreordine(Nod* rad) {
	if (rad) {
		afisareMedicament(rad->info);
		afisarePreordine(rad->st);
		afisarePreordine(rad->dr);
	}
}

void dezalocareArbore(Nod** rad) {
	if (*rad) {
		dezalocareArbore(&(*rad)->st);
		dezalocareArbore(&(*rad)->dr);
		free((*rad)->info.denumire);
		free((*rad)->info.producator);
		free(*rad);
		*rad = NULL;
	}
}

Medicament getMedicamentByID(Nod* rad, int id) {
	Medicament m;
	m.id = -1;

	if (rad) {
		if (rad->info.id == id) {
			m = rad->info;
			m.denumire = (char*)malloc(strlen(rad->info.denumire) + 1);
			strcpy(m.denumire, rad->info.denumire);

			m.producator = (char*)malloc(strlen(rad->info.producator) + 1);
			strcpy(m.producator, rad->info.producator);
		}

		if (id < rad->info.id) {
			m = getMedicamentByID(rad->st, id);
		}
		if (id > rad->info.id) {
			m = getMedicamentByID(rad->dr, id);
		}
	}

	return m;
}

int determinaNumarNoduri(Nod* rad) {
	if (rad) {
		return determinaNumarNoduri(rad->st) +
			+determinaNumarNoduri(rad->dr) + 1;
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
			+calculeazaPretTotal(rad->st) +
			+calculeazaPretTotal(rad->dr);
	}
	return 0;
}

float calculeazaPretMedicamenteProducator(Nod* rad, const char* producator) {
	if (rad) {
		float suma = calculeazaPretMedicamenteProducator(rad->st, producator) +
			+calculeazaPretMedicamenteProducator(rad->dr, producator);

		if (strcmp(rad->info.producator, producator) == 0) {
			suma += rad->info.pret;
		}
		return suma;
	}
	return 0;
}

int main() {
	Nod* rad = citireArboreMedicamenteDinFisier("medicamente.txt");

	afisarePreordine(rad);

	printf("Medicament cautat:");
	afisareMedicament(getMedicamentByID(rad, 2));

	printf("Numar noduri:%d\n", determinaNumarNoduri(rad));
	printf("Inaltime arbore:%d\n", calculeazaInaltimeArbore(rad));
	printf("Pret total:%.2f\n", calculeazaPretTotal(rad));
	printf("Suma preturilor medicamentelor unui producator:%.2f\n",
		calculeazaPretMedicamenteProducator(rad, "Bayer"));

	dezalocareArbore(&rad);

	return 0;
}
