#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820

char *string_clone(const char *str, size_t length) {
    // length = 1812UL / 1UL = 1812

    /*
    El problema con esta implementación, es que el valor de la variable clon se encuentra en el stack, por lo que al hacer un return del output que es un puntero a clon, el valor del puntero ya no es valido
    */

    if (MAX_LENGTH <= length) {
        printf("The rope size is larger allowed: %u(MAX_LENGTH) < %lu(length)\n", MAX_LENGTH - 1u, length);
        exit(EXIT_FAILURE);
    }

    char *output = NULL;
    output = (char*)malloc(sizeof(char) * (length + 1u)); // (+ 1u) para añadir el '\0' al final
    if (output == NULL) {
        printf("Not enough memory\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < length; i++) {
        output[i] = str[i];
    }

    output[length] = '\0';

    return output;
}


int main(void) {
    char original[] = ""
        "______ time ago in a galaxy far, far away...\n\n\n"
        ANSI_BRGOLD
        "         _______..___________.     ___      .______             \n"
        "        /       ||           |    /   \\     |   _  \\          \n"
        "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
        "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
        "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
        "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
        "                                                                \n"
        "____    __    ____      ___      .______           _______.     \n"
        "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
        " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
        "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
        "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
        "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
        "\n\n\n"
        "                           Episode II \n\n"
        "                      ATTACK OF THE CLONES\n\n"
        "                There is  unrest in the Galactic\n"
        "                Senate. Several  thousand  solar\n"
        "                systems  have   declared   their\n"
        "                intentions to leave the Republic.\n\n"
        "                This      separatist     movement,\n"
        "                under  the   leadership   of  the\n"
        "                mysterious   Count   Dooku,   has\n"
        "                made it difficult for the limited\n"
        "                number   of   Jedi   Knights   to\n"
        "                maintain   peace   and  order  in\n"
        "                the galaxy.\n\n"
        "                Senator   Amidala,   the   former\n"
        "                Queen   of  Naboo,  is  returning\n"
        "                to  the  Galactic  Senate to vote\n"
        "                on the critical issue of creating\n"
        "                an    ARMY    OF   THE   REPUBLIC\n"
        "                to    assist    the   overwhelmed\n"
        "                Jedi....\n" ANSI_WHITE;
    char *copy = NULL;

    copy = string_clone(original, sizeof(original) / sizeof(*original));

    printf("Original:\n" ANSI_CYAN
        " %s\n", original);

    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';

    printf("Copia   :\n" ANSI_CYAN
        " %s\n", copy);

    free(copy);

    return EXIT_SUCCESS;
}
