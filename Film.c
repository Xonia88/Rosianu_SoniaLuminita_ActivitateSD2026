//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct Film {
//
//	int id;
//	char* titlu;
//
//}Film;
//
//typedef struct Nod {
//
//	Film info;
//
//	struct Nod* st;
//	struct Nod* dr;
//
//}Nod;
//
//Film creareFilm(int id, const char* titlu) {
//
//	Film f;
//
//	f.id = id;
//
//	f.titlu = (char*)malloc(strlen(titlu) + 1);
//
//	strcpy(f.titlu, titlu);
//
//	return f;
//}
//
//void inserare(Nod** rad, Film f) {
//
//	if (*rad == NULL) {
//
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//
//		nou->info = f;
//
//		nou->st = NULL;
//		nou->dr = NULL;
//
//		*rad = nou;
//	}
//	else {
//
//		if (f.id < (*rad)->info.id) {
//
//			inserare(&((*rad)->st), f);
//		}
//		else {
//
//			inserare(&((*rad)->dr), f);
//		}
//	}
//}
//
//void afisare(Nod* rad) {
//
//	if (rad != NULL) {
//
//		afisare(rad->st);
//
//		printf("\n%d %s",
//			rad->info.id,
//			rad->info.titlu);
//
//		afisare(rad->dr);
//	}
//}
//
//int main() {
//
//	Nod* rad = NULL;
//
//	inserare(&rad, creareFilm(5, "Titanic"));
//	inserare(&rad, creareFilm(2, "Avatar"));
//	inserare(&rad, creareFilm(8, "Joker"));
//
//	afisare(rad);
//
//	return 0;
//}