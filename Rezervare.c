#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rezervare {
	int id;
	char* numeClient;     
	int nrLocuri;
	float* preturi;       
} Rezervare;


Rezervare creareRezervare(int id, const char* numeClient, int nrLocuri, float* preturi) {
	Rezervare r;
	r.id = id;
	r.nrLocuri = nrLocuri;

	r.numeClient = (char*)malloc(strlen(numeClient) + 1);
	strcpy(r.numeClient, numeClient);

	r.preturi = (float*)malloc(sizeof(float) * nrLocuri);
	for (int i = 0; i < nrLocuri; i++) {
		r.preturi[i] = preturi[i];
	}

	return r;
}

void afisareRezervare(Rezervare r) {
	printf("\nID: %d", r.id);
	printf("\nClient: %s", r.numeClient);
	printf("\nNumar locuri: %d", r.nrLocuri);
	printf("\nPreturi: ");

	for (int i = 0; i < r.nrLocuri; i++) {
		printf("%.2f ", r.preturi[i]);
	}
	printf("\n");
}


float calculeazaTotal(Rezervare r) {
	float suma = 0;
	for (int i = 0; i < r.nrLocuri; i++) {
		suma += r.preturi[i];
	}
	return suma;
}

void modificaNumeClient(Rezervare* r, const char* numeNou) {
	free(r->numeClient);
	r->numeClient = (char*)malloc(strlen(numeNou) + 1);
	strcpy(r->numeClient, numeNou);
}

void dezalocare(Rezervare* r) {
	free(r->numeClient);
	free(r->preturi);
}

int main() {
	float preturi[] = { 100, 150, 200 };

	Rezervare r = creareRezervare(1, "Popescu Ion", 3, preturi);

	afisareRezervare(r);

	printf("Total rezervare: %.2f\n", calculeazaTotal(r));

	modificaNumeClient(&r, "Ionescu Ana");

	printf("\nDupa modificare:\n");
	afisareRezervare(r);

	dezalocare(&r);

	return 0;
}