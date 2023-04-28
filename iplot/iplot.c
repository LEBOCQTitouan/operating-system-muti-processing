//
// Created by Titouan LEBOCQ on 28/04/2023.
//

#include "iplot.h"

void routine_upper_bound(int *upper_bound) {
    do {
        printf("Choose an upper bound (strictly superior to 0) : ");
        scanf("%d", upper_bound);
    } while (*upper_bound <= 0);
}

void routine_upper_lower_bound(int *upper_bound, int *lower_bound) {
    do {
        printf("Choose an upper bound : ");
        scanf("%d", upper_bound);
        printf("Choose a lower bound : ");
        scanf("%d", lower_bound);
    } while (*upper_bound <= *lower_bound);
}

void create_config_file(int upper_bound, int lower_bound){
    FILE *file = fopen(CONFIG_FILE, "w");
    fprintf(file, "set samples 500\n");
    fprintf(file, "plot [x=%d:%d] sin(x)/x smooth csplines\n", lower_bound, upper_bound);
    fclose(file);
}

void display_routine() {
    execlp("gnuplot", "gnuplot", "-persist",CONFIG_FILE, NULL);
}
