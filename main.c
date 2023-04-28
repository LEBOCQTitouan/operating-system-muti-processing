#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "iplot/iplot.h"

int main() {
    int upper_limit, lower_limit, choice = WANT_TO_CONTINUE;

    while (choice == WANT_TO_CONTINUE) {
        do {
            printf("Choose a display mode (1 : 0 to upper limit, 2: upper and lower limit) : ");
            scanf("%d", &choice);
        } while (choice != UPPER && choice != UPPER_LOWER);

        switch (choice) {
            case UPPER:
                lower_limit = 0;
                routine_upper_bound(&upper_limit);
                break;
            case UPPER_LOWER:
                routine_upper_lower_bound(&upper_limit, &lower_limit);
                break;
        }

        create_config_file(upper_limit, lower_limit);

        int pid = fork();
        if (pid == 0) { // child
            display_routine();
            exit(EXIT_SUCCESS);
        }

        do {
            printf("Do you want to continue ? (3 : Yes; 4 : No) ");
            scanf("%d", &choice);
        } while (choice != WANT_TO_CONTINUE && choice != WANT_TO_STOP);
    }

    wait(NULL);

    return EXIT_SUCCESS;
}