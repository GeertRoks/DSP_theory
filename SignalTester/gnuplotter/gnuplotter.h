#ifndef _H_GNU_PLOTTER_
#define _H_GNU_PLOTTER_

#include <stdlib.h>
#include <stdio.h>

FILE* open_gnu_plot_file();
void  print_to_gnu_plot(float x, float y, FILE* gnuplot_pipe);
void  refresh_gnu_plot(FILE* gnuplot_pipe);

#endif //_H_GNU_PLOTTER_
