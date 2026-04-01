#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Restaurant Restaurant;

struct Restaurant {
	int id;
	char* nume;
	int nrProduse;
	float* preturi;
};

Restaurant initializareRestaurant(int id, const char* nume, int nrProduse, float* preturi) {
	Restaurant r;
	r.id = id;

	r.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(r.nume, nume);

	r.nrProduse = nrProduse;

	r.preturi = (float*)malloc(sizeof(float) * nrProduse);
	for (int i = 0; i < nrProduse; i++) {
		r.preturi[i] = preturi[i];
	}

	return r;
}

Restaurant citireRestaurant() {
	Restaurant r;

	printf("Id: ");
	scanf("%d", &r.id);

	char buffer[100];
	printf("Nume: ");
	scanf("%s", buffer);

	r.nume = (char*)malloc(strlen(buffer) + 1);
	strcpy(r.nume, buffer);

	printf("Numar produse: ");
	scanf("%d", &r.nrProduse);

	r.preturi = (float*)malloc(sizeof(float) * r.nrProduse);
	for (int i = 0; i < r.nrProduse; i++) {
		printf("Pret %d: ", i + 1);
		scanf("%f", &r.preturi[i]);
	}

	return r;
}

void afisareRestaurant(Restaurant r) {
	printf("\nId: %d", r.id);
	printf("\nNume: %s", r.nume);
	printf("\nNr produse: %d", r.nrProduse);

	printf("\nPreturi: ");
	for (int i = 0; i < r.nrProduse; i++) {
		printf("%.2f ", r.preturi[i]);
	}
	printf("\n");
}

float calculMedie(Restaurant r) {
	float suma = 0;
	for (int i = 0; i < r.nrProduse; i++) {
		suma += r.preturi[i];
	}
	if (r.nrProduse > 0) {
		return suma / r.nrProduse;
	}
	return 0;
}

void modificaNume(Restaurant* r, const char* numeNou) {
	free(r->nume);
	r->nume = (char*)malloc(strlen(numeNou) + 1);
	strcpy(r->nume, numeNou);
}

void dezalocare(Restaurant* r) {
	free(r->nume);
	free(r->preturi);
}

int main() {

	float preturi[] = { 25.5, 30.0, 15.75 };

	Restaurant r = initializareRestaurant(1, "Urban", 3, preturi);

	afisareRestaurant(r);

	printf("\nMedie: %.2f\n", calculMedie(r));

	modificaNume(&r, "Central");

	printf("\nDupa modificare:\n");
	afisareRestaurant(r);

	dezalocare(&r);

	return 0;
}