//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Farmacie Farmacie;
//typedef struct Nod Nod;
//typedef struct HashTable HashTable;
//
//struct Farmacie {
//	char* nume;
//	int nrAngajati;
//	float adaos;
//};
//
//struct Nod {
//	Farmacie info;
//	Nod* next;
//};
//
//struct HashTable {
//	int dimensiune;
//	Nod** vector;
//};
//
//Farmacie initFarmacie(const char* nume, int nrAngajati, float adaos) {
//	Farmacie f;
//	f.nrAngajati = nrAngajati;
//	f.adaos = adaos;
//
//	f.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(f.nume, nume);
//
//	return f;
//}
//
//void afisareFarmacie(Farmacie f) {
//	printf("\nFarmacia %s are %d angajati si adaos %.2f",
//		f.nume, f.nrAngajati, f.adaos);
//}
//
//void afisareLista(Nod* cap) {
//	while (cap) {
//		afisareFarmacie(cap->info);
//		cap = cap->next;
//	}
//}
//
//void inserare(Nod** cap, Farmacie f) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;
//	nou->next = NULL;
//
//	if (*cap == NULL) {
//		*cap = nou;
//	}
//	else {
//		Nod* temp = *cap;
//		while (temp->next) {
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
//int hash(int dim, int nrAngajati) {
//	return nrAngajati % dim;
//}
//
//void inserareHT(HashTable ht, Farmacie f) {
//	int poz = hash(ht.dimensiune, f.nrAngajati);
//	inserare(&(ht.vector[poz]), f);
//}
//
//void afisareHT(HashTable ht) {
//	for (int i = 0; i < ht.dimensiune; i++) {
//		printf("\nPozitie %d:", i);
//		afisareLista(ht.vector[i]);
//	}
//}
//
//int totalAngajatiPoz0(HashTable ht) {
//	int suma = 0;
//	Nod* temp = ht.vector[0];
//
//	while (temp) {
//		suma += temp->info.nrAngajati;
//		temp = temp->next;
//	}
//
//	return suma;
//}
//
//Farmacie minAngajati(HashTable ht) {
//	Farmacie min;
//	min.nrAngajati = 99999;
//
//	for (int i = 0; i < ht.dimensiune; i++) {
//		Nod* temp = ht.vector[i];
//		while (temp) {
//			if (temp->info.nrAngajati < min.nrAngajati) {
//				min = temp->info;
//			}
//			temp = temp->next;
//		}
//	}
//	return min;
//}
//
//Farmacie cautaDupaNume(HashTable ht, const char* nume) {
//	Farmacie rez;
//	rez.nume = NULL;
//
//	for (int i = 0; i < ht.dimensiune; i++) {
//		Nod* temp = ht.vector[i];
//		while (temp) {
//			if (strcmp(temp->info.nume, nume) == 0) {
//				rez = temp->info;
//
//				rez.nume = (char*)malloc(strlen(temp->info.nume) + 1);
//				strcpy(rez.nume, temp->info.nume);
//
//				return rez;
//			}
//			temp = temp->next;
//		}
//	}
//	return rez;
//}
//
//void dezalocareLista(Nod** cap) {
//	while (*cap) {
//		free((*cap)->info.nume);
//		Nod* aux = *cap;
//		*cap = (*cap)->next;
//		free(aux);
//	}
//}
//
//void dezalocareHT(HashTable ht) {
//	for (int i = 0; i < ht.dimensiune; i++) {
//		dezalocareLista(&(ht.vector[i]));
//	}
//	free(ht.vector);
//}
//
//int main() {
//
//	HashTable ht = initHashTable(4);
//
//	inserareHT(ht, initFarmacie("Catena", 10, 20));
//	inserareHT(ht, initFarmacie("HelpNet", 7, 25));
//	inserareHT(ht, initFarmacie("Dona", 5, 15));
//	inserareHT(ht, initFarmacie("Sensiblu", 12, 30));
//	inserareHT(ht, initFarmacie("Tei", 6, 18));
//
//	afisareHT(ht);
//
//	printf("\nTotal angajati poz 0: %d",
//		totalAngajatiPoz0(ht));
//
//	printf("\nFarmacia cu nr minim de angajati:");
//	afisareFarmacie(minAngajati(ht));
//
//	printf("\nCautare dupa nume:");
//	afisareFarmacie(cautaDupaNume(ht, "Dona"));
//
//	dezalocareHT(ht);
//
//	return 0;
//}