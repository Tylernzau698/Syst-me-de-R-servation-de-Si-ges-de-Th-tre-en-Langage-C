#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int selection;
int seatsAvailable = 20;
int booking_ID = 1;
int i, j;

struct Show {
    char showname[50];
    char date[20];
    char time[10];
    char gate[10];
};

struct Seat {
    int seats;
    char name[50];
};

struct Show show = {"Avengers: Endgame", "2023-10-15", "18:00", "Porte 1"};
struct Seat choice[4][5];

void displaymenu();
void looping();
void booking();
void ticket();
void cancel();
void seat();
void records();
void exit_();

void displaymenu() {
    printf("\n");
    printf("\t  RESERVATION DE PLACES DE THÉÂTRE\n"
           "\t=============================\n"
           "\tMaintenant à laffiche : Avengers: Endgame\n"
           "\t=============================\n"
           "\n\t1=> RESERVER DES PLACES\n"
           "\n\t2=> ANNULER UNE RESERVATION\n"
           "\n\t3=> VOIR LES PLACES DISPONIBLES\n"
           "\n\t4=> VOIR LES ENREGISTREMENTS\n"
           "\n\t5=> QUITTER\n\n");
    printf("\t=============================\n");
    printf("\tVeuillez faire un choix : ");
    scanf("%d", &selection);
    looping();
    return;
}

void looping() {
    switch (selection) {
        case 1:
            booking();
            break;
        case 2:
            cancel();
            break;
        case 3:
            seat();
            break;
        case 4:
            records();
            break;
        case 5:
            exit_();
            break;
        default:
            printf("\tSélection invalide. Veuillez réessayer.\n");
    }
    return;
}

void booking() {
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("\n\tVeuillez entrer le numéro de siège : ");
            scanf("%d", &choice[i][j].seats);
            fflush(stdin);

            if (choice[i][j].seats <= seatsAvailable) {
                printf("\tVeuillez entrer le nom du client : ");
                scanf("%[^\n]", choice[i][j].name);
                fflush(stdin);
                ticket();
                booking_ID++;
            }
            seatsAvailable = seatsAvailable - choice[i][j].seats;

            system("pause");
            system("cls");
            displaymenu();
        }
    }
    if (seatsAvailable < 0) {
        printf("\n");
        printf("\tDÉSOLÉ, La séance est complète.\n");
        printf("\t=================FIN=================\n\n");
        displaymenu();
    }

    if (choice[i][j].seats > seatsAvailable) {
        printf("\n");
        printf("\tIl reste %d places disponibles.\n", seatsAvailable);
        displaymenu();
    }
    return;
}

void ticket() {
    printf("\n\n");
    printf("\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb SIÈGES RÉSERVÉS AU THÉÂTRE  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t===================================================================\n");
    printf("\t ID de réservation : %d \t\t\tNom du spectacle : %s\n", booking_ID, show.showname);
    printf("\t Client : %s\n", choice[i][j].name);
    printf("\t\t\t                              Date : %s\n", show.date);
    printf("\t                                              Heure : %s\n", show.time);
    printf("\t                                              Porte : %s\n", show.gate);
    printf("\t                                              Siège n° : %d%c  \n\n", i + 1, j + 65);
    printf("\t====================================================================\n");
    return;
}

void cancel() {
    char cancelcustomername[80];
    printf("Entrez le nom du client à annuler : ");
    scanf("%s", cancelcustomername);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (strcmp(choice[i][j].name, cancelcustomername) == 0) {
                choice[i][j].seats = 1;
                system("pause");
                system("cls");
                displaymenu();
                return;
            }
        }
    }
}

void seat() {
    printf("  A   B   C       D     E\n");
    for (j = 0; j < 5; j++) {
        printf("%d  ", booking_ID);
    }
    for (i = 0; i < 4; i++) {
        printf("\n");
        printf("%d\n", i + 1);
    }
    system("pause");
    system("cls");
    displaymenu();
    return;
}

void records() {
    printf("\t====================================\n");
    printf("\tAFFICHAGE DE TOUS LES ENREGISTREMENTS\n");
    printf("\t====================================\n");
    printf("\tPlaces disponibles restantes : %d \n", seatsAvailable);

    ticket();
    system("pause");
    system("cls");
    displaymenu();
    return;
}

void exit_() {
    printf("\tMerci d'avoir utilisé ce système.\n");
    exit(1);
    return;
}

int main() {
    displaymenu();
    return 0;
}