/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar2.h"
#include <stdio.h>

char CC2;
boolean EOP2;

// static FILE * pita;
static int retval2;

void START2() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC2 adalah karakter pertama pada pita. Jika CC2 != MARK maka EOP2 akan padam (false).
          Jika CC2 = MARK maka EOP2 akan menyala (true) */

	/* Algoritma */
	// pita = fopen("../File/pitakar.txt","r");
	ADV2();
}

void ADV2() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC2, CC2 != MARK
   F.S. : CC2 adalah karakter berikutnya dari CC2 yang lama,
          CC2 mungkin = MARK.
		  Jika  CC2 = MARK maka EOP2 akan menyala (true) */

	/* Algoritma */
	retval2 = fscanf(stdin,"%c",&CC2);
	EOP2 = (CC2 == MARK2);
	if (EOP2) {
       // fclose(pita);
      // printf("TEST EOF\n");
 	}
}
