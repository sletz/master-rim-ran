
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur de rampe */

float* table_rampe;
int table_size_rampe;
int phase_rampe;

/* Création et remplissage de la table avec un période du signal */
void init_rampe(int sample_rate, int freq)
{
    table_size_rampe = (int)((float)sample_rate / (float)freq);
    
    /* Alloue dynamiquement une table. */
    table_rampe = (float*)malloc(table_size_rampe * sizeof(float));
    
    /* Remplit la table */
    // A FINIR

    /* Initialise la phase */
    phase_rampe = 0;
}

void destroy_rampe()
{
    /* Desalloue le tableau. */
    free(table_rampe);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_rampe(float* output, int nframes)
{
    int i;
    for (i = 0 ; i < nframes; i++) {
        output[i] = table_rampe[phase_rampe];  
        phase_rampe = phase_rampe + 1;
        if (phase_rampe == table_size_rampe) {
            phase_rampe = 0;
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
