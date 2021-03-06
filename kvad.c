#include <stdio.h>
#include <stdlib.h>
#include <cmath>


int vvod (double* a, double* b, double* c)
{
    char ac[256] = {};
    char bc[256] = {};
    char cc[256] = {};

    int j = 3;
    printf ("enter 3 arguments\n");
    scanf ("%s %s %s", ac, bc, cc);

    *a = atof (ac);
    *b = atof (bc);
    *c = atof (cc);


    for (int i = 0; i < 256; i++)
    {

        if (! ( ( (ac[i] >= 48) && (ac[i] <= 57) || (ac[i] == '\0') || (ac[i] == '.') || (ac[i] == '-')) &&
                ( (bc[i] >= 48) && (bc[i] <= 57) || (bc[i] == '\0') || (bc[i] == '.') || (bc[i] == '-')) &&
                ( (cc[i] >= 48) && (cc[i] <= 57) || (cc[i] == '\0') || (cc[i] == '.') || (cc[i] == '-'))) ||
                ( (*a == 0.000000) && (*b == 0.000000) && (*c == 0.000000)))
        {
            j = 2;

        }
    }

    return j;

}

void resh (double* a, double* b, double* c)
{
    int r = 228;
    int sroot = 228;
    int froot = 228;

    if (*a == 0)
    {
        if (*b == 0)
        {
            printf ("This isn`t an equation\n") ;
        }
        else
        {
            if (*c != 0)
            {
                printf ("This is lineal equation, root is: %f\n", (- (*b)) / *c) ;
            }
            else
            {
                printf ("This is lineal equation, root is:\n0\n") ;
            }
        }
    }
    else
    {
        double d = (*b) * (*b) - 4 * (*a) * (*c);

        if (d > 0)
        {
            printf ("Ur equation have 2 real roots\n%f\n", (- (*b) + sqrt (d)) / (2 * (*a)));
            printf ("Ur equation have 2 real roots\n%f\n", (- (*b) - sqrt (d)) / (2 * (*a)));
        }

        if (d == 0)
        {
            printf ("Ur equation have 1 real root\n%f\n", (- (*b) + sqrt (d)) / (2 * (*a)));
        }

        if (d < 0)
        {
            {
                printf ("Ur equation have no real roots\n");
            }

        }
    }
}

int main()
{

    double a = 0;
    double b = 0;
    double c = 0;
    double froot = 228;
    double sroot = 228;
    char x[1] = {};

    int j = 228;

    printf ("Welcome to square equations solver v1.337\n");

    while (1)
    {
        switch (j)
        {
            case 0:
                {
                    return 0;
                }

            case 1:
                {

                    j = vvod (&a, &b, &c);

                    break;
                }

            case 2:
                {

                    printf ("Wrong input, try again\n");
                    j = 228;
                    break;
                }

            case 3:
                {
                    resh (&a, &b, &c);
                    j = 228;
                    break;
                }

            default:
                {
                    printf ("enter 1 to solve new equation or 0 to exit\n");
                    scanf ("%s", x);

                    j = 2;

                    if ( (x[0] >= 48) && (x[0] <= 57))
                    {
                        if (x[0] == '0' || x[0] == '1')
                        {
                            j = x[0] - '0';

                        }
                    }

                }
        }
    }

}

