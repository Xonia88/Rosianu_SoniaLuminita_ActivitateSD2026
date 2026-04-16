//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Restaurant Restaurant;
//
//struct Restaurant {
//	int id;
//	char* nume;
//	int nrProduse;
//	float* preturi;
//};
//
//Restaurant initializareRestaurant(int id, const char* nume, int nrProduse, float* preturi) {
//	Restaurant r;
//	r.id = id;
//
//	r.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(r.nume, nume);
//
//	r.nrProduse = nrProduse;
//
//	r.preturi = (float*)malloc(sizeof(float) * nrProduse);
//	for (int i = 0; i < nrProduse; i++) {
//		r.preturi[i] = preturi[i];
//	}
//
//	return r;
//}
//
//Restaurant citireRestaurant() {
//	Restaurant r;
//
//	printf("Id: ");
//	scanf("%d", &r.id);
//
//	char buffer[100];
//	printf("Nume: ");
//	scanf("%s", buffer);
//
//	r.nume = (char*)malloc(strlen(buffer) + 1);
//	strcpy(r.nume, buffer);
//
//	printf("Numar produse: ");
//	scanf("%d", &r.nrProduse);
//
//	r.preturi = (float*)malloc(sizeof(float) * r.nrProduse);
//	for (int i = 0; i < r.nrProduse; i++) {
//		printf("Pret %d: ", i + 1);
//		scanf("%f", &r.preturi[i]);
//	}
//
//	return r;
//}
//
//void afisareRestaurant(Restaurant r) {
//	printf("\nId: %d", r.id);
//	printf("\nNume: %s", r.nume);
//	printf("\nNr produse: %d", r.nrProduse);
//
//	printf("\nPreturi: ");
//	for (int i = 0; i < r.nrProduse; i++) {
//		printf("%.2f ", r.preturi[i]);
//	}
//	printf("\n");
//}
//
//float calculMedie(Restaurant r) {
//	float suma = 0;
//	for (int i = 0; i < r.nrProduse; i++) {
//		suma += r.preturi[i];
//	}
//	if (r.nrProduse > 0) {
//		return suma / r.nrProduse;
//	}
//	return 0;
//}
//
//void modificaNume(Restaurant* r, const char* numeNou) {
//	free(r->nume);
//	r->nume = (char*)malloc(strlen(numeNou) + 1);
//	strcpy(r->nume, numeNou);
//}
//
//void dezalocare(Restaurant* r) {
//	free(r->nume);
//	free(r->preturi);
//}
//
//void afisareVector(Restaurant* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afisareRestaurant(vector[i]);
//	}
//}
//Restaurant copiazaRestaurant(Restaurant r) {
//	return initializareRestaurant(r.id, r.nume, r.nrProduse, r.preturi);
//}
//
//void copiazaRestaurante(Restaurant* vector, int nrElemente, int prag, Restaurant** vectorNou, int* dimNou) {
//	*dimNou = 0;
//
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].nrProduse > prag) {
//			(*dimNou)++;
//		}
//	}
//
//	*vectorNou = (Restaurant*)malloc(sizeof(Restaurant) * (*dimNou));
//
//	*dimNou = 0;
//
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].nrProduse > prag) {
//			(*vectorNou)[*dimNou] = copiazaRestaurant(vector[i]);
//			(*dimNou)++;
//		}
//	}
//}
//void mutaRestaurante(Restaurant** vector, int* nrElemente, float prag, Restaurant** vectorNou, int* dimNou) {
//	*dimNou = 0;
//
//	for (int i = 0; i < *nrElemente; i++) {
//		if ((*vector)[i].preturi[0] > prag) {
//			(*dimNou)++;
//		}
//	}
//
//	*vectorNou = (Restaurant*)malloc(sizeof(Restaurant) * (*dimNou));
//
//	int k = 0;
//	for (int i = 0; i < *nrElemente; i++) {
//		if ((*vector)[i].preturi[0] > prag) {
//			(*vectorNou)[k++] = copiazaRestaurant((*vector)[i]);
//		}
//	}
//}
//
//Restaurant* concateneazaVectori(Restaurant* v1, int n1, Restaurant* v2, int n2, int* dimNou) {
//	*dimNou = n1 + n2;
//
//	Restaurant* rezultat = (Restaurant*)malloc(sizeof(Restaurant) * (*dimNou));
//
//	for (int i = 0; i < n1; i++) {
//		rezultat[i] = copiazaRestaurant(v1[i]);
//	}
//
//	for (int i = 0; i < n2; i++) {
//		rezultat[n1 + i] = copiazaRestaurant(v2[i]);
//	}
//
//	return rezultat;
//}
//
//void dezalocareVector(Restaurant** vector, int* nrElemente) {
//	for (int i = 0; i < *nrElemente; i++) {
//		dezalocare(&(*vector)[i]);
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//
//Restaurant citireRestaurantDinFisier(FILE* f) {
//	char buffer[200];
//	char sep[3] = ",\n";
//
//	if (fgets(buffer, 200, f) == NULL) {
//		Restaurant r;
//		r.id = -1;
//		r.nume = NULL;
//		r.nrProduse = 0;
//		r.preturi = NULL;
//		return r;
//	}
//
//	char* token;
//	Restaurant r;
//
//	token = strtok(buffer, sep);
//	r.id = atoi(token);
//
//	token = strtok(NULL, sep);
//	r.nume = (char*)malloc(strlen(token) + 1);
//	strcpy(r.nume, token);
//
//	token = strtok(NULL, sep);
//	r.nrProduse = atoi(token);
//
//	r.preturi = (float*)malloc(sizeof(float) * r.nrProduse);
//
//	for (int i = 0; i < r.nrProduse; i++) {
//		token = strtok(NULL, sep);
//		r.preturi[i] = atof(token);
//	}
//
//	return r;
//}
//
//Restaurant* citireVectorDinFisier(const char* numeFisier, int* nrElemente) {
//	FILE* f = fopen(numeFisier, "r");
//
//	Restaurant* vector = NULL;
//	*nrElemente = 0;
//
//	while (1) {
//		Restaurant r = citireRestaurantDinFisier(f);
//
//		if (r.id == -1) {
//			break;
//		}
//
//		vector = (Restaurant*)realloc(vector, sizeof(Restaurant) * ((*nrElemente) + 1));
//		vector[*nrElemente] = r;
//		(*nrElemente)++;
//	}
//
//	fclose(f);
//	return vector;
//}
//
//void scrieRestaurantInFisier(FILE* f, Restaurant r) {
//	fprintf(f, "%d,%s,%d,", r.id, r.nume, r.nrProduse);
//
//	for (int i = 0; i < r.nrProduse; i++) {
//		fprintf(f, "%.2f", r.preturi[i]);
//		if (i < r.nrProduse - 1) {
//			fprintf(f, ",");
//		}
//	}
//
//	fprintf(f, "\n");
//}
//
//void scrieVectorInFisier(const char* numeFisier, Restaurant* vector, int nrElemente) {
//	FILE* f = fopen(numeFisier, "w");
//
//	for (int i = 0; i < nrElemente; i++) {
//		scrieRestaurantInFisier(f, vector[i]);
//	}
//
//	fclose(f);
//}
//
//Restaurant** creeazaMatrice(Restaurant* vector, int nrElemente, int* nrLinii, int** dimLinii) {
//
//	*nrLinii = 0;
//
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].nrProduse > *nrLinii) {
//			*nrLinii = vector[i].nrProduse;
//		}
//	}
//
//	Restaurant** matrice = (Restaurant**)malloc(sizeof(Restaurant*) * (*nrLinii));
//	*dimLinii = (int*)malloc(sizeof(int) * (*nrLinii));
//
//	for (int i = 0; i < *nrLinii; i++) {
//		matrice[i] = NULL;
//		(*dimLinii)[i] = 0;
//	}
//
//	for (int i = 0; i < nrElemente; i++) {
//		int linie = vector[i].nrProduse - 1;
//
//		matrice[linie] = (Restaurant*)realloc(matrice[linie],
//			sizeof(Restaurant) * ((*dimLinii)[linie] + 1));
//
//		matrice[linie][(*dimLinii)[linie]] = copiazaRestaurant(vector[i]);
//		(*dimLinii)[linie]++;
//	}
//
//	return matrice;
//}
//
//void afisareMatrice(Restaurant** matrice, int nrLinii, int* dimLinii) {
//	for (int i = 0; i < nrLinii; i++) {
//		printf("\nLinia %d:\n", i);
//		for (int j = 0; j < dimLinii[i]; j++) {
//			afisareRestaurant(matrice[i][j]);
//		}
//	}
//}
//
//
//void sorteazaMatrice(Restaurant** matrice, int nrLinii, int* dimLinii) {
//	for (int i = 0; i < nrLinii - 1; i++) {
//		for (int j = i + 1; j < nrLinii; j++) {
//			if (dimLinii[i] > dimLinii[j]) {
//
//				int tempDim = dimLinii[i];
//				dimLinii[i] = dimLinii[j];
//				dimLinii[j] = tempDim;
//
//				Restaurant* temp = matrice[i];
//				matrice[i] = matrice[j];
//				matrice[j] = temp;
//			}
//		}
//	}
//}
//
//void dezalocareMatrice(Restaurant*** matrice, int* nrLinii, int** dimLinii) {
//	for (int i = 0; i < *nrLinii; i++) {
//		for (int j = 0; j < (*dimLinii)[i]; j++) {
//			dezalocare(&(*matrice)[i][j]);
//		}
//		free((*matrice)[i]);
//	}
//
//	free(*matrice);
//	free(*dimLinii);
//
//	*matrice = NULL;
//	*dimLinii = NULL;
//	*nrLinii = 0;
//}
//
//typedef struct Nod {
//	Restaurant info;
//	struct Nod* next;
//} Nod;
//
//Nod* inserareFinal(Nod* cap, Restaurant r) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = copiazaRestaurant(r);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		return nou;
//	}
//
//	Nod* temp = cap;
//	while (temp->next != NULL) {
//		temp = temp->next;
//	}
//	temp->next = nou;
//
//	return cap;
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareRestaurant(cap->info);
//		cap = cap->next;
//	}
//}
//
//void dezalocareLista(Nod** cap) {
//	while (*cap != NULL) {
//		Nod* temp = *cap;
//		*cap = (*cap)->next;
//		dezalocare(&temp->info);
//		free(temp);
//	}
//}
//typedef struct NodDublu {
//	Restaurant info;
//	struct NodDublu* next;
//	struct NodDublu* prev;
//} NodDublu;
//
//NodDublu* inserareFinalDublu(NodDublu* cap, Restaurant r) {
//	NodDublu* nou = (NodDublu*)malloc(sizeof(NodDublu));
//	nou->info = copiazaRestaurant(r);
//	nou->next = NULL;
//	nou->prev = NULL;
//
//	if (cap == NULL) {
//		return nou;
//	}
//
//	NodDublu* temp = cap;
//	while (temp->next != NULL) {
//		temp = temp->next;
//	}
//
//	temp->next = nou;
//	nou->prev = temp;
//
//	return cap;
//}
//
//void afisareListaDubla(NodDublu* cap) {
//	while (cap != NULL) {
//		afisareRestaurant(cap->info);
//		cap = cap->next;
//	}
//}
//
//void afisareListaDublaInvers(NodDublu* cap) {
//	if (cap == NULL) return;
//
//	while (cap->next != NULL) {
//		cap = cap->next;
//	}
//
//	while (cap != NULL) {
//		afisareRestaurant(cap->info);
//		cap = cap->prev;
//	}
//}
//
//void dezalocareListaDubla(NodDublu** cap) {
//	while (*cap != NULL) {
//		NodDublu* temp = *cap;
//		*cap = (*cap)->next;
//		dezalocare(&temp->info);
//		free(temp);
//	}
//}
//NodDublu* stergePozitieDublu(NodDublu* cap, int poz) {
//	if (cap == NULL) return NULL;
//
//	NodDublu* temp = cap;
//	int index = 0;
//
//	while (temp != NULL && index < poz) {
//		temp = temp->next;
//		index++;
//	}
//
//	if (temp == NULL) return cap;
//
//	if (temp->prev == NULL) { // primul
//		cap = temp->next;
//		if (cap) cap->prev = NULL;
//	}
//	else {
//		temp->prev->next = temp->next;
//		if (temp->next) {
//			temp->next->prev = temp->prev;
//		}
//	}
//
//	dezalocare(&temp->info);
//	free(temp);
//
//	return cap;
//}
//
//NodDublu* inserareSortataDublu(NodDublu* cap, Restaurant r) {
//	NodDublu* nou = (NodDublu*)malloc(sizeof(NodDublu));
//	nou->info = copiazaRestaurant(r);
//	nou->next = NULL;
//	nou->prev = NULL;
//
//	if (cap == NULL || r.id < cap->info.id) {
//		nou->next = cap;
//		if (cap) cap->prev = nou;
//		return nou;
//	}
//
//	NodDublu* temp = cap;
//
//	while (temp->next != NULL && temp->next->info.id < r.id) {
//		temp = temp->next;
//	}
//
//	nou->next = temp->next;
//	nou->prev = temp;
//
//	if (temp->next) {
//		temp->next->prev = nou;
//	}
//
//	temp->next = nou;
//
//	return cap;
//}
//
//Nod* salvareInListaSimpla(NodDublu* cap, int prag) {
//	Nod* lista = NULL;
//
//	while (cap != NULL) {
//		if (cap->info.nrProduse > prag) {
//			lista = inserareFinal(lista, cap->info);
//		}
//		cap = cap->next;
//	}
//
//	return lista;
//}
//
//
//void swapPozitiiDublu(NodDublu* cap, int p1, int p2) {
//	if (p1 == p2) return;
//
//	NodDublu* n1 = NULL;
//	NodDublu* n2 = NULL;
//
//	int index = 0;
//
//	while (cap != NULL) {
//		if (index == p1) n1 = cap;
//		if (index == p2) n2 = cap;
//		cap = cap->next;
//		index++;
//	}
//
//	if (n1 && n2) {
//		Restaurant temp = n1->info;
//		n1->info = n2->info;
//		n2->info = temp;
//	}
//}
//
//typedef struct Cladire {
//	int id;
//	int anConstructie;
//	char* adresa;
//	float suprafata;
//} Cladire;
//
//typedef struct NodHash {
//	Cladire info;
//	struct NodHash* next;
//} NodHash;
//
//typedef struct HashTable {
//	NodHash** vector;
//	int dim;
//} HashTable;
//
//
//int functieHash(HashTable tabela, int an) {
//	return an % tabela.dim;
//}
//
//void inserareHash(HashTable tabela, Cladire c) {
//	int poz = functieHash(tabela, c.anConstructie);
//
//	NodHash* nou = (NodHash*)malloc(sizeof(NodHash));
//	nou->info = c;
//	nou->next = tabela.vector[poz];
//
//	tabela.vector[poz] = nou;
//}
//
//void afisareCluster(HashTable tabela, int an) {
//	int poz = functieHash(tabela, an);
//
//	NodHash* temp = tabela.vector[poz];
//
//	while (temp != NULL) {
//		if (temp->info.anConstructie == an) {
//			printf("\nId: %d", temp->info.id);
//			printf("\nAn: %d", temp->info.anConstructie);
//			printf("\nAdresa: %s", temp->info.adresa);
//			printf("\nSuprafata: %.2f\n", temp->info.suprafata);
//		}
//		temp = temp->next;
//	}
//}
//HashTable initializareHash(int dim) {
//	HashTable tabela;
//	tabela.dim = dim;
//	tabela.vector = (NodHash**)malloc(sizeof(NodHash*) * dim);
//
//	for (int i = 0; i < dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//
//	return tabela;
//}
//
//
//void stergeCladire(HashTable tabela, int id, int an) {
//	int poz = functieHash(tabela, an);
//
//	NodHash* temp = tabela.vector[poz];
//	NodHash* prev = NULL;
//
//	while (temp != NULL) {
//		if (temp->info.id == id && temp->info.anConstructie == an) {
//
//			if (prev == NULL) {
//				tabela.vector[poz] = temp->next;
//			}
//			else {
//				prev->next = temp->next;
//			}
//
//			free(temp);
//			return;
//		}
//
//		prev = temp;
//		temp = temp->next;
//	}
//}
//
//void stergeCladireDupaId(HashTable tabela, int id) {
//	for (int i = 0; i < tabela.dim; i++) {
//
//		NodHash* temp = tabela.vector[i];
//		NodHash* prev = NULL;
//
//		while (temp != NULL) {
//			if (temp->info.id == id) {
//
//				if (prev == NULL) {
//					tabela.vector[i] = temp->next;
//				}
//				else {
//					prev->next = temp->next;
//				}
//
//				free(temp);
//				return;
//			}
//
//			prev = temp;
//			temp = temp->next;
//		}
//	}
//}
//
//
//Cladire* salvareInVector(HashTable tabela, int an, int* dim) {
//	*dim = 0;
//
//	int poz = functieHash(tabela, an);
//	NodHash* temp = tabela.vector[poz];
//
//	while (temp != NULL) {
//		if (temp->info.anConstructie == an) {
//			(*dim)++;
//		}
//		temp = temp->next;
//	}
//
//	Cladire* vector = (Cladire*)malloc(sizeof(Cladire) * (*dim));
//
//	int k = 0;
//	temp = tabela.vector[poz];
//
//	while (temp != NULL) {
//		if (temp->info.anConstructie == an) {
//			vector[k++] = temp->info;
//		}
//		temp = temp->next;
//	}
//
//	return vector;
//}
//
//
//
//void modificaAn(HashTable tabela, int id, int anVechi, int anNou) {
//	int poz = functieHash(tabela, anVechi);
//
//	NodHash* temp = tabela.vector[poz];
//	NodHash* prev = NULL;
//
//	while (temp != NULL) {
//		if (temp->info.id == id) {
//
//			Cladire c = temp->info;
//
//			if (prev == NULL) {
//				tabela.vector[poz] = temp->next;
//			}
//			else {
//				prev->next = temp->next;
//			}
//
//			free(temp);
//
//			c.anConstructie = anNou;
//			inserareHash(tabela, c);
//
//			return;
//		}
//
//		prev = temp;
//		temp = temp->next;
//	}
//}
//
//typedef struct Pacient {
//	int id;
//	char* nume;
//	int gradUrgenta;
//} Pacient;
//
//
//Pacient initPacient(int id, const char* nume, int grad) {
//	Pacient p;
//	p.id = id;
//	p.gradUrgenta = grad;
//
//	p.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(p.nume, nume);
//
//	return p;
//}
//
//void afisarePacient(Pacient p) {
//	printf("\nPacient %d - %s - urgenta: %d", p.id, p.nume, p.gradUrgenta);
//}
//
//typedef struct Heap {
//	Pacient* vector;
//	int dim;
//} Heap;
//
//void inserareHeap(Heap* h, Pacient p) {
//	h->vector = (Pacient*)realloc(h->vector, sizeof(Pacient) * (h->dim + 1));
//	h->vector[h->dim] = p;
//	int i = h->dim;
//	h->dim++;
//
//	while (i > 0) {
//		int parinte = (i - 1) / 2;
//		if (h->vector[parinte].gradUrgenta < h->vector[i].gradUrgenta) {
//			Pacient aux = h->vector[parinte];
//			h->vector[parinte] = h->vector[i];
//			h->vector[i] = aux;
//			i = parinte;
//		}
//		else {
//			break;
//		}
//	}
//}
//
//
//
//Pacient extrageMax(Heap* h) {
//	Pacient p = h->vector[0];
//
//	h->vector[0] = h->vector[h->dim - 1];
//	h->dim--;
//
//	int i = 0;
//
//	while (1) {
//		int st = 2 * i + 1;
//		int dr = 2 * i + 2;
//		int max = i;
//
//		if (st < h->dim && h->vector[st].gradUrgenta > h->vector[max].gradUrgenta)
//			max = st;
//
//		if (dr < h->dim && h->vector[dr].gradUrgenta > h->vector[max].gradUrgenta)
//			max = dr;
//
//		if (max != i) {
//			Pacient aux = h->vector[i];
//			h->vector[i] = h->vector[max];
//			h->vector[max] = aux;
//			i = max;
//		}
//		else break;
//	}
//
//	return p;
//}
//
//void dezalocareHeap(Heap* h) {
//	for (int i = 0; i < h->dim; i++) {
//		free(h->vector[i].nume);
//	}
//	free(h->vector);
//	h->vector = NULL;
//	h->dim = 0;
//}
//
//
//int main() {
//
//	float preturi[] = { 25.5, 30.0, 15.75 };
//
//	Restaurant r = initializareRestaurant(1, "Urban", 3, preturi);
//
//	afisareRestaurant(r);
//
//	printf("\nMedie: %.2f\n", calculMedie(r));
//
//	modificaNume(&r, "Central");
//
//	printf("\nDupa modificare:\n");
//	afisareRestaurant(r);
//
//	dezalocare(&r);
//
//
//	int nr = 5;
//	Restaurant* vector = (Restaurant*)malloc(sizeof(Restaurant) * nr);
//
//	float p1[] = { 10,20 };
//	float p2[] = { 15,25,35 };
//	float p3[] = { 12 };
//	float p4[] = { 50,60 };
//	float p5[] = { 5,7,9 };
//
//	vector[0] = initializareRestaurant(1, "A", 2, p1);
//	vector[1] = initializareRestaurant(2, "B", 3, p2);
//	vector[2] = initializareRestaurant(3, "C", 1, p3);
//	vector[3] = initializareRestaurant(4, "D", 2, p4);
//	vector[4] = initializareRestaurant(5, "E", 3, p5);
//
//	printf("\nVector initial:\n");
//	afisareVector(vector, nr);
//
//	Restaurant* filtrat = NULL;
//	int dimFiltrat = 0;
//
//	copiazaRestaurante(vector, nr, 2, &filtrat, &dimFiltrat);
//
//	printf("\nVector copiat:\n");
//	afisareVector(filtrat, dimFiltrat);
//
//
//	Restaurant* mutat = NULL;
//	int dimMutat = 0;
//
//	mutaRestaurante(&vector, &nr, 10, &mutat, &dimMutat);
//
//	printf("\nVector mutat:\n");
//	afisareVector(mutat, dimMutat);
//
//
//	int dimConcat = 0;
//	Restaurant* concatenat = concateneazaVectori(vector, nr, filtrat, dimFiltrat, &dimConcat);
//
//	printf("\nVector concatenat:\n");
//	afisareVector(concatenat, dimConcat);
//
//
//	dezalocareVector(&filtrat, &dimFiltrat);
//	dezalocareVector(&mutat, &dimMutat);
//	dezalocareVector(&concatenat, &dimConcat);
//	
//
//
//	int nrFisier = 0;
//	Restaurant* dinFisier = citireVectorDinFisier("restaurante.txt", &nrFisier);
//
//	printf("\nVector din fisier:\n");
//	afisareVector(dinFisier, nrFisier);
//
//	scrieVectorInFisier("output.txt", dinFisier, nrFisier);
//
//	dezalocareVector(&dinFisier, &nrFisier);
//
//
//	int nrLinii = 0;
//	int* dimLinii = NULL;
//
//	Restaurant** matrice = creeazaMatrice(vector, nr, &nrLinii, &dimLinii);
//
//	printf("\nMatrice initiala:\n");
//	afisareMatrice(matrice, nrLinii, dimLinii);
//
//	sorteazaMatrice(matrice, nrLinii, dimLinii);
//
//	printf("\nMatrice sortata:\n");
//	afisareMatrice(matrice, nrLinii, dimLinii);
//
//	dezalocareMatrice(&matrice, &nrLinii, &dimLinii);
//
//
//	
//
//
//
//
//	Nod* lista = NULL;
//
//	for (int i = 0; i < nr; i++) {
//		lista = inserareFinal(lista, vector[i]);
//	}
//
//	printf("\nLista:\n");
//	afisareLista(lista);
//
//	dezalocareLista(&lista);
//
//	NodDublu* listaD = NULL;
//
//	for (int i = 0; i < nr; i++) {
//		listaD = inserareFinalDublu(listaD, vector[i]);
//	}
//
//	printf("\nLista dubla:\n");
//	afisareListaDubla(listaD);
//
//	printf("\nLista dubla invers:\n");
//	afisareListaDublaInvers(listaD);
//
//	printf("\nStergere pozitie 2:\n");
//	listaD = stergePozitieDublu(listaD, 2);
//	afisareListaDubla(listaD);
//
//	printf("\nInserare sortata:\n");
//	Restaurant nou = initializareRestaurant(6, "Z", 2, p1);
//	listaD = inserareSortataDublu(listaD, nou);
//	afisareListaDubla(listaD);
//	dezalocare(&nou);
//
//	printf("\nSwap pozitii 0 si 2:\n");
//	swapPozitiiDublu(listaD, 0, 2);
//	afisareListaDubla(listaD);
//
//	printf("\nLista simpla din dubla:\n");
//	Nod* listaSimpla = salvareInListaSimpla(listaD, 2);
//	afisareLista(listaSimpla);
//	dezalocareLista(&listaSimpla);
//
//
//	dezalocareListaDubla(&listaD);
//
//
//	dezalocareVector(&vector, &nr);
//
//	HashTable tabela = initializareHash(5);
//
//	Cladire c1 = { 1, 1990, "A", 50 };
//	Cladire c2 = { 2, 1980, "B", 70 };
//	Cladire c3 = { 3, 1990, "C", 60 };
//
//	inserareHash(tabela, c1);
//	inserareHash(tabela, c2);
//	inserareHash(tabela, c3);
//
//	printf("\nCluster 1990:\n");
//	afisareCluster(tabela, 1990);
//
//	printf("\nStergere id 1 din 1990:\n");
//	stergeCladire(tabela, 1, 1990);
//	afisareCluster(tabela, 1990);
//
//	printf("\nStergere dupa id 2:\n");
//	stergeCladireDupaId(tabela, 2);
//	afisareCluster(tabela, 1980);
//
//	printf("\nVector din cluster 1990:\n");
//	int dim = 0;
//	Cladire* v = salvareInVector(tabela, 1990, &dim);
//
//	for (int i = 0; i < dim; i++) {
//		printf("\nId: %d", v[i].id);
//		printf("\nAn: %d", v[i].anConstructie);
//		printf("\nAdresa: %s", v[i].adresa);
//		printf("\nSuprafata: %.2f\n", v[i].suprafata);
//	}
//
//	free(v);
//
//	printf("\nModificare an pentru id 3:\n");
//	modificaAn(tabela, 3, 1990, 2000);
//	afisareCluster(tabela, 2000);
//	Heap heap;
//	heap.vector = NULL;
//	heap.dim = 0;
//
//	inserareHeap(&heap, initPacient(1, "Ion", 5));
//	inserareHeap(&heap, initPacient(2, "Ana", 9));
//	inserareHeap(&heap, initPacient(3, "Mihai", 3));
//
//	printf("\nHeap (extragere ordine urgenta):\n");
//
//	while (heap.dim > 0) {
//		Pacient p = extrageMax(&heap);
//		afisarePacient(p);
//		free(p.nume);
//	}
//
//	dezalocareHeap(&heap);
//
//	return 0;
//}