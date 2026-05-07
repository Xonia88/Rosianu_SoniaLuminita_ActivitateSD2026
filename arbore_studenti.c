//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraStudent {
//	int id;
//	int varsta;
//	float medie;
//	char* nume;
//	char* facultate;
//	unsigned char grupa;
//};
//typedef struct StructuraStudent Student;
//
//struct Nod {
//	Student info;
//	struct Nod* st;
//	struct Nod* dr;
//};
//typedef struct Nod Nod;
//
//Student citireStudentDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	char* aux;
//
//	Student s;
//
//	if (fgets(buffer, 100, file) == NULL) {
//		s.id = -1;
//		return s;
//	}
//
//	aux = strtok(buffer, sep);
//	s.id = atoi(aux);
//	s.varsta = atoi(strtok(NULL, sep));
//	s.medie = (float)atof(strtok(NULL, sep));
//
//	aux = strtok(NULL, sep);
//	s.nume = (char*)malloc(strlen(aux) + 1);
//	strcpy(s.nume, aux);
//
//	aux = strtok(NULL, sep);
//	s.facultate = (char*)malloc(strlen(aux) + 1);
//	strcpy(s.facultate, aux);
//
//	s.grupa = *strtok(NULL, sep);
//
//	return s;
//}
//
//void afisareStudent(Student s) {
//	printf("Id: %d\n", s.id);
//	printf("Varsta: %d\n", s.varsta);
//	printf("Medie: %.2f\n", s.medie);
//	printf("Nume: %s\n", s.nume);
//	printf("Facultate: %s\n", s.facultate);
//	printf("Grupa: %c\n\n", s.grupa);
//}
//
//void adaugaStudentInArbore(Nod** rad, Student sNou) {
//	if (*rad == NULL) {
//		Nod* nod = (Nod*)malloc(sizeof(Nod));
//		nod->info = sNou;
//		nod->st = NULL;
//		nod->dr = NULL;
//		*rad = nod;
//	}
//	else {
//		if ((*rad)->info.id > sNou.id) {
//			adaugaStudentInArbore(&((*rad)->st), sNou);
//		}
//		if ((*rad)->info.id < sNou.id) {
//			adaugaStudentInArbore(&((*rad)->dr), sNou);
//		}
//	}
//}
//
//Nod* citireArboreDinFisier(const char* numeFisier) {
//	Nod* rad = NULL;
//	FILE* f = fopen(numeFisier, "r");
//
//	if (f) {
//		while (1) {
//			Student s = citireStudentDinFisier(f);
//			if (s.id == -1) break;
//			adaugaStudentInArbore(&rad, s);
//		}
//	}
//	fclose(f);
//	return rad;
//}
//
//void afisareInordine(Nod* rad) {
//	if (rad) {
//		afisareInordine(rad->st);
//		afisareStudent(rad->info);
//		afisareInordine(rad->dr);
//	}
//}
//
//void afisarePreordine(Nod* rad) {
//	if (rad) {
//		afisareStudent(rad->info);
//		afisarePreordine(rad->st);
//		afisarePreordine(rad->dr);
//	}
//}
//
//void dezalocareArbore(Nod** rad) {
//	if (*rad) {
//		dezalocareArbore(&(*rad)->st);
//		dezalocareArbore(&(*rad)->dr);
//		free((*rad)->info.nume);
//		free((*rad)->info.facultate);
//		free(*rad);
//		*rad = NULL;
//	}
//}
//
//Student getStudentByID(Nod* rad, int id) {
//	Student s;
//	s.id = -1;
//
//	if (rad) {
//		if (rad->info.id == id) {
//			s = rad->info;
//			s.nume = (char*)malloc(strlen(rad->info.nume) + 1);
//			strcpy(s.nume, rad->info.nume);
//			s.facultate = (char*)malloc(strlen(rad->info.facultate) + 1);
//			strcpy(s.facultate, rad->info.facultate);
//		}
//		if (id < rad->info.id) {
//			s = getStudentByID(rad->st, id);
//		}
//		if (id > rad->info.id) {
//			s = getStudentByID(rad->dr, id);
//		}
//	}
//	return s;
//}
//
//int determinaNumarNoduri(Nod* rad) {
//	if (rad) {
//		return determinaNumarNoduri(rad->st) +
//			determinaNumarNoduri(rad->dr) + 1;
//	}
//	return 0;
//}
//
//int maxim(int a, int b) {
//	return (a > b ? a : b);
//}
//
//int calculeazaInaltime(Nod* rad) {
//	if (rad) {
//		return maxim(calculeazaInaltime(rad->st),
//			calculeazaInaltime(rad->dr)) + 1;
//	}
//	return 0;
//}
//
//float calculeazaMedieTotala(Nod* rad) {
//	if (rad) {
//		return rad->info.medie +
//			calculeazaMedieTotala(rad->st) +
//			calculeazaMedieTotala(rad->dr);
//	}
//	return 0;
//}
//
//float calculeazaMediiFacultate(Nod* rad, const char* facultate) {
//	if (rad) {
//		float suma = calculeazaMediiFacultate(rad->st, facultate) +
//			calculeazaMediiFacultate(rad->dr, facultate);
//
//		if (strcmp(rad->info.facultate, facultate) == 0) {
//			suma += rad->info.medie;
//		}
//		return suma;
//	}
//	return 0;
//}
//
//int main() {
//	Nod* rad = citireArboreDinFisier("studenti.txt");
//
//	printf("Preordine:\n");
//	afisarePreordine(rad);
//
//	printf("Student cautat:\n");
//	afisareStudent(getStudentByID(rad, 2));
//
//	printf("Nr noduri: %d\n", determinaNumarNoduri(rad));
//	printf("Inaltime: %d\n", calculeazaInaltime(rad));
//	printf("Suma medii: %.2f\n", calculeazaMedieTotala(rad));
//	printf("Suma medii ASE: %.2f\n",
//		calculeazaMediiFacultate(rad, "ASE"));
//
//	dezalocareArbore(&rad);
//
//	return 0;
//}