 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur sinus */

float* table_sinus;
int table_size_sinus;
int phase_sinus;

/* Création et remplissage de la table avec un période du signal */
void init_sinus(int sample_rate, int freq)
{
    table_size_sinus = (int)((float)sample_rate / (float)freq);
    
    /* Alloue dynamiquement une table. */
    table_sinus = (float*)malloc(table_size_sinus * sizeof(float));
    
    /* Remplit la table */
    int i;
    for (i = 0; i < table_size_sinus; i++) {
        table_sinus[i] = (float)sin(((float)i / (float)table_size_sinus) * M_PI * 2.);
    }
    
    /* Initialise la phase */
    phase_sinus = 0;
}

void destroy_sinus()
{
    /* Desalloue le tableau. */
    free(table_sinus);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_sinus(float* output, int nframes)
{
    int i;
    for (i = 0 ; i < nframes; i++) {
        output[i] = table_sinus[phase_sinus];  
        phase_sinus = phase_sinus + 1; 
        if (phase_sinus == table_size_sinus) {
            phase_sinus = 0;
        }
    }
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_sinus()
{
    float sample = table_sinus[phase_sinus];
    phase_sinus = phase_sinus + 1;
    if (phase_sinus == table_size_sinus) {
        phase_sinus = 0;
    }
    return sample;
}

void display_table()
{
    // A FINIR
}

int main()
{
    init_sinus(44100, 500);
    display_table();
}
