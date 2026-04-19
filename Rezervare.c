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

Rezervare copiazaRezervare(Rezervare r) {
	return creareRezervare(r.id, r.numeClient, r.nrLocuri, r.preturi);
}

void afisareVector(Rezervare* v, int n) {
	for (int i = 0; i < n; i++) {
		afisareRezervare(v[i]);
	}
}

Rezervare* filtreazaRezervari(Rezervare* v, int n, float prag, int* dimNou) {
	*dimNou = 0;
	for (int i = 0; i < n; i++) {
		if (calculeazaTotal(v[i]) > prag) {
			(*dimNou)++;
		}
	}

	Rezervare* vNou = (Rezervare*)malloc(sizeof(Rezervare) * (*dimNou));

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (calculeazaTotal(v[i]) > prag) {
			vNou[k++] = copiazaRezervare(v[i]);
		}
	}

	return vNou;
}

Rezervare* mutaRezervari(Rezervare* v, int n, float prag, int* dimNou) {
	*dimNou = 0;
	for (int i = 0; i < n; i++) {
		if (calculeazaTotal(v[i]) < prag) {
			(*dimNou)++;
		}
	}

	Rezervare* vNou = (Rezervare*)malloc(sizeof(Rezervare) * (*dimNou));

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (calculeazaTotal(v[i]) < prag) {
			vNou[k++] = copiazaRezervare(v[i]);
		}
	}

	return vNou;
}

Rezervare* concateneazaVectori(Rezervare* v1, int n1, Rezervare* v2, int n2) {
	Rezervare* vNou = (Rezervare*)malloc(sizeof(Rezervare) * (n1 + n2));

	for (int i = 0; i < n1; i++) {
		vNou[i] = copiazaRezervare(v1[i]);
	}

	for (int i = 0; i < n2; i++) {
		vNou[n1 + i] = copiazaRezervare(v2[i]);
	}

	return vNou;
}

void dezalocareVector(Rezervare** v, int* n) {
	for (int i = 0; i < *n; i++) {
		dezalocare(&((*v)[i]));
	}
	free(*v);
	*v = NULL;
	*n = 0;
}

int main() {
	int n = 5;
	Rezervare* v = (Rezervare*)malloc(sizeof(Rezervare) * n);

	float p1[] = { 100, 100 };
	float p2[] = { 200, 200 };
	float p3[] = { 50, 50 };
	float p4[] = { 300 };
	float p5[] = { 150, 150 };

	v[0] = creareRezervare(1, "Ana", 2, p1);
	v[1] = creareRezervare(2, "Ion", 2, p2);
	v[2] = creareRezervare(3, "Maria", 2, p3);
	v[3] = creareRezervare(4, "Paul", 1, p4);
	v[4] = creareRezervare(5, "Elena", 2, p5);

	afisareVector(v, n);

	int dimFiltrat = 0;
	Rezervare* vFiltrat = filtreazaRezervari(v, n, 250, &dimFiltrat);
	afisareVector(vFiltrat, dimFiltrat);

	int dimMutat = 0;
	Rezervare* vMutat = mutaRezervari(v, n, 250, &dimMutat);
	afisareVector(vMutat, dimMutat);

	int dimConcat = dimFiltrat + dimMutat;
	Rezervare* vConcat = concateneazaVectori(vFiltrat, dimFiltrat, vMutat, dimMutat);
	afisareVector(vConcat, dimConcat);

	dezalocareVector(&v, &n);
	dezalocareVector(&vFiltrat, &dimFiltrat);
	dezalocareVector(&vMutat, &dimMutat);
	dezalocareVector(&vConcat, &dimConcat);

	return 0;
}