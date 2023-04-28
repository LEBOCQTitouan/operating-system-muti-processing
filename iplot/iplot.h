//
// Created by Titouan LEBOCQ on 26/04/2023.
//

#ifndef OPERATING_SYSTEM_PROCESS_HANDLING_IPLOT_H
#define OPERATING_SYSTEM_PROCESS_HANDLING_IPLOT_H

#include <stdio.h>
#include <unistd.h>

#define CONFIG_FILE "commandes.gp"

/**
 * Enum defining the possible user choices.
 */
enum user_choice {
    UPPER = 1,              // from 0 to upper bound
    UPPER_LOWER = 2,        // from lower to upper bound
    WANT_TO_CONTINUE = 3,   // user want to continue
    WANT_TO_STOP = 4        // user want to stop
};

/**
 * Routine used to get upper bound from user input (upper bound is strictly superior to 0).
 * @param upper_bound the pointer to the upper bound that has to be set
 */
void routine_upper_bound(int *upper_bound);

/**
 * Routine used to get upper and lower bound from user input.
 * @param upper_bound the pointer to the upper bound that has to be set
 * @param lower_bound the pointer to the lower bound that has to be set
 */
void routine_upper_lower_bound(int *upper_bound, int *lower_bound);

/**
 * Create a config file named CONFIG_FILE used to display curves in gnuplot.
 * @param upper_bound
 * @param lower_bound
 */
void create_config_file(int upper_bound, int lower_bound);

/**
 * Routine used to display the file created by create_config_file using gnuplot.
 */
void display_routine();

#endif //OPERATING_SYSTEM_PROCESS_HANDLING_IPLOT_H
