#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* addSpace (char* String) {
    int i = 0;
    char* rString = (char*) calloc (strlen (String), sizeof (char));

    for (i; String[i] != '\0' ; i++) {
        if (String[i] == '_') {
            rString[i] = ' ';
        } else {
            rString[i] = String[i];
        }
    }

    rString[i] = '\0';

    return rString;
}

class node {
    private:
        char* def;
        node* left;
        node* right;
    public:
        node (char* in) {
            def = in;
            left = NULL;
            right = NULL;
        }
        void print() {
            if (left != NULL) {
                left->print();
            }

            printf ("\n%s\n", addSpace (def));

            if (right != NULL) {
                right->print();
            }
        }
        void addl (char* newdef) {
            assert (left == NULL);
            left = new node (newdef);
        }
        void addle () {
            assert (left == NULL);
            left = new node ("NULL");
        }
        void addr (char* newdef) {
            assert (right == NULL);
            right = new node (newdef);
        }
        void addre () {
            assert (right == NULL);
            right = new node ("NULL");
        }
        void removel() {
            assert (left != NULL);

            if (left->left != NULL) {
                left->removel();
            }

            if (left->right != NULL) {
                left->remover();
            }

            left = NULL;
            delete left;
        }
        void remover() {
            assert (right != NULL);

            if (right->left != NULL) {
                right->removel();
            }

            if (right->right != NULL) {
                right->remover();
            }

            right = NULL;
            delete right;
        }
        int  ifleaf () {
            if (left == NULL && right == NULL) {
                return 1;
            } else {
                return 0;
            }
        }
        void check() {
            char ans;
            printf ("\nYa pravilno ugadal y/n?\n");
            scanf ("%s", &ans);

            if (ans == 'n') {
                char* newd = (char*) calloc (32, sizeof (char));
                addl (def);
                char* nquestion = (char*) calloc (64, sizeof (char));
                printf ("\nVvedite imya zagadonnogo personazha (vmesto probela ispolzuyte '_')\n");
                scanf ("%s", newd);
                printf ("\nChem zagadannuy vami personaj otlichaetsa ot personaja: %s?\n", def);
                scanf ("%s", nquestion);
                def = nquestion;
                addr (newd);
                printf ("\nV sleduyushiy raz ya ne promahnus!\n");
            } else if (ans == 'y') {
                printf ("\nYa kak vsegda pobedil!");
            } else {
                check();
            }

        }
        void ask() {
            char ans;

            if (ifleaf() == 1) {
                printf ("\nVash personaj: ");
                print();
                check();
            } else {
                printf ("\nVash personaj %s y/n?\n", addSpace (def));
                scanf ("%s", &ans);

                if (ans == 'n') {
                    left->ask();
                } else if (ans == 'y') {
                    right->ask();
                } else {
                    ask();
                }

            }
        }
        void destruct (FILE* RouteToFile) {

            fprintf (RouteToFile, "(%s ", def);


            if ((left != NULL) && (right != NULL)) {

                left->destruct (RouteToFile);
                right->destruct (RouteToFile);


            }

            fprintf (RouteToFile, ")");


        }
        void construct (char* buf, int first) {
            int k = 1;

            if (buf[0] == '(') {

                if (first == 0) {
                    def = &buf[1];
                }

                char* buf1 = &buf[2 + strlen (&buf[1])];

                int i = 1;

                for (i = 1; k != 0; i++) {
                    if (buf1[i] == '(') {
                        k++;
                    }

                    if (buf1[i] == ')') {
                        k--;
                    }

                }

                char* buf2 = &buf1[i];

                if (buf1[0] == '(') {

                    if (buf1[0] == '(') {
                        addl ("NULL");
                    }

                    if (buf2[0] == '(') {
                        addr ("NULL");
                    }



                    left->construct (buf1, 0);
                    right->construct (buf2, 0);
                }


            }
        }

};

char* vvod () {

    FILE* RouteToFile = fopen ("data.txt", "rb");

    if (RouteToFile == NULL) {
        printf ("\nwrong route");
        exit (1);
    }

    fseek (RouteToFile, 0, SEEK_END);
    long FileSize = ftell (RouteToFile);
    fseek (RouteToFile, 0, SEEK_SET);


    char* buffer = (char*) malloc (sizeof (char) * (FileSize));

    if (buffer == NULL) {
        exit (2);
    }

    fread (buffer, 1, (FileSize), RouteToFile);

    for (int i = 1; i < FileSize; i++) {

        if (buffer[i] == ' ') {
            buffer[i] = '\0';

        }
    }


    fclose (RouteToFile);
    return buffer;
}



int main() {
    setlocale (LC_ALL, "Rus");
    node tree ("vymyshlenny");


    tree.construct (vvod(), 1);

    tree.ask();

    FILE* RouteToFile = fopen ("data.txt", "w");


    tree.destruct (RouteToFile);


    fclose (RouteToFile);
    return 0;
}
