#include <stdio.h>
#include <stdlib.h>
#include "fic_wave.h"

FILE    *abre_wave(const char *ficWave, float *fm) {
    FILE    *fpWave;
    int fm_read, channels, pcm;

    if ((fpWave = fopen(ficWave, "r")) == NULL) return NULL;
    if(fseek(fpWave,24,SEEK_SET) < 0) return NULL;
    fread(&fm_read,4,1,fpWave);
    if(fseek(fpWave,22,SEEK_SET) < 0) return NULL;
    fread(&channels,2,1,fpWave);
    if(fseek(fpWave,16,SEEK_SET) < 0) return NULL;
    fread(&pcm,4,1,fpWave);
    if (fseek(fpWave, 44, SEEK_SET) < 0) return NULL;
    *fm = fm_read;
    printf("Frecuencia de muestreo: %d \n", fm_read);
    printf("Numero de canales: %d \n", channels);
    printf("PCM: %d \n", pcm);
    if (pcm != 16){
        printf("El formato de fichero wave no es el adecuado. (PCM es %d, deveria ser 16)\n", pcm); 
        exit(0);
    }
    else if (channels != 1){
        printf("El formato de fichero wave no es el adecuado. (Hay %d canales, deveria haber 1)\n", channels); 
        exit(0);
    }
    return fpWave;
}

size_t   lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
    return fread(x, size, nmemb, fpWave);
}

void    cierra_wave(FILE *fpWave) {
    fclose(fpWave);
}
