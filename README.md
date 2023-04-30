# Operating system : process handling


## Installation

### Dependencies

* [gnuplot]("http://www.gnuplot.info/") : for displaying the results
* [cmake]("https://cmake.org/") / [make]("https://www.gnu.org/software/make/manual/make.html") : for compiling the project

### Compilation

#### Using cmake

```bash
$ mkdir build
$ cmake -S . -B build
```

#### Using make

```bash
$ make
```

## Project description

This project is an introduction to process handling in C. It contains a few examples of how to use the
`fork()`, `wait()`, `exec()` and `kill()` functions.

The goal of this program is to ask one or two numbers to the user (upper and lower bounds and if no lower bound is given
, the lower bound is set to 0) and then display the sine of all the numbers between the lower and upper bounds (given a
sample rate of 500).

The display is done using gnuplot. The parent process is responsible for asking the user for the bounds and the child 
process is responsible for sending them to gnuplot.