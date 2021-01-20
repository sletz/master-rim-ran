
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur de créneau */

float* table_square;
int table_size_square;
int phase_square;

/* Création et remplissage de la table avec un période du signal */
void init_square(int sample_rate, int freq)
{
    table_size_square = (int)((float)sample_rate / (float)freq);
    
    /* Alloue dynamiquement une table. */
    table_square = (float*)malloc(table_size_square * sizeof(float));
    
    /* Remplit la table */
    // A FINIR

    /* Initialise la phase */
    phase_square = 0;
}

void destroy_square()
{
    /* Desalloue le tableau. */
    free(table_square);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_square(float* output, int nframes)
{
    int i;
    for (i = 0 ; i < nframes; i++) {
        output[i] = table_square[phase_square];  
        phase_square = phase_square + 1;
        if (phase_square == table_size_square) {
            phase_square = 0;
        }
    }
}

void display_table()
{
    // A FINIR
}

int main()
{
   // A FINIR
}
