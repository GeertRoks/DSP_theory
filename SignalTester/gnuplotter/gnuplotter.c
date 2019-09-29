#include "gnuplotter.h"

FILE* open_gnu_plot_file()
{
    const char* name="FloatSignal";
    FILE* gnuplot_pipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplot_pipe, "set title '%s'\n", name);
    fprintf(gnuplot_pipe, "set pointsize 0.01\n");
    fprintf(gnuplot_pipe, "plot '-'\n");

    return gnuplot_pipe;
}


void print_to_gnu_plot(float x, float y, FILE* gnuplot_pipe)
{
    fprintf(gnuplot_pipe, "%f %f\n", x, y);
}


void refresh_gnu_plot(FILE* gnuplot_pipe)
{
  fprintf(gnuplot_pipe, "e\n");
  // refresh can probably be omitted
  fprintf(gnuplot_pipe, "refresh\n");
}
