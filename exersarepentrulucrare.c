//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct Test {
//	char* materie;
//	int nrStudenti;
//	float medie;
//};
//
//typedef struct Test Test;
//
//struct Nod {
//	Test info;
//	struct Nod* next;
//
//};
//
//typedef struct Nod Nod;
//
//Test initTest(const char* materie, int nrStudenti, float medie) {
//
//	Test t;
//
//	t.nrStudenti = nrStudenti;
//	t.medie = medie;
//	t.materie = (char*)malloc(strlen(materie) + 1);
//	strcpy(t.materie, materie);
//
//	return t;
//
//}
//
//void afisareTest(Test t) {
//
//	printf("\n%s, %d, %.2f",
//		t.materie,
//		t.nrStudenti,
//		t.medie);
//}
//
//int main() {
//
//	Test t = initTest("SIE", 50, 7.9);
//
//	afisareTest(t);
//
//	free(t.materie);
//
//	return 0;
//
//}
