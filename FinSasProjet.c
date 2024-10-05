#include <stdio.h>
#include <string.h>

#define Max_reservations 100
#define Max_taille 50

struct Reservation {
    char nom[Max_taille];
    char prenom[Max_taille];
    char telephone[Max_taille];
    int age;
    char statut[Max_taille];
    char reference[Max_taille];
    char date[Max_taille]; // jour/mois/annee
};

struct Reservation reservations[Max_reservations] = {
    {"elkhader", "yassine", "0645044566", 19, "valide", "ID1", "13/11/2015"},
    {"tabali", "youssef", "0773295540", 27, "reporte", "ID2", "17/11/2015"},
    {"nejjari", "ahmed", "0723547687", 23, "annule", "ID3", "19/11/2015"},
    {"ahmed", "hammadi", "0653279088", 35, "traite", "ID4", "23/11/2015"},
    {"sabir", "naaim", "0698274305", 60, "valide", "ID5", "24/11/2015"},
    {"soussi", "allal", "0668329132", 38, "traite", "ID6", "28/11/2015"},
    {"aouni", "amin", "0678342323", 34, "reporte", "ID7", "13/2/2016"},
    {"touil", "adil", "060984703", 33, "traite", "ID8", "8/3/2016"},
    {"lkorfi", "abdl_ali", "0794302123", 15, "annule", "ID9", "17/3/2016"},
    {"salbi", "nabil", "0723954304", 90, "valide", "ID10", "20/3/2016"}
};

int num_reservations = 10;

// pour ajouter une reservation //
void ajouter() {
    printf("\n--<>----<>----<>----<>-- Ajoute reservation --<>----<>----<>----<>--\n");
    if (num_reservations < Max_reservations) {
        printf("Entrez le nom : ");
        fgets(reservations[num_reservations].nom, Max_taille, stdin);
        printf("Entrez le prenom : ");
        fgets(reservations[num_reservations].prenom, Max_taille, stdin);
        printf("Entrez le telephone : ");
        fgets(reservations[num_reservations].telephone, Max_taille, stdin);
        printf("Entrez l'age : ");
        scanf("%d", &reservations[num_reservations].age);
        getchar(); // pour consommer le caractere de nouvelle ligne restant //
        printf("Entrez le statut (valide, reporte, annule, traite) : ");
        fgets(reservations[num_reservations].statut, Max_taille, stdin);
        while (reservations[num_reservations].statut != "valide" || "reporte "||"annule"|| "traite")
        {
            printf("Veuillez entrer un des choix disponible (valide,reporte,annule,traite) :");
            fgets(reservations[num_reservations].statut, Max_taille, stdin);
            break;
        }
        

        sprintf(reservations[num_reservations].reference, "ID%d", num_reservations + 1);

        printf("Entrez la date : ");
        fgets(reservations[num_reservations].date, Max_taille, stdin);

        num_reservations++;
    } else {
        printf("\n- - - > Nombre maximum de reservations atteint ! < - - - \n");
    }
}

// pour modifier/supprimer une reservation
void modifier_suprimer_reservation() {
    char reference[10];
    printf("\n--<>----<>----<>----<>-- Modifier / supprimer une reservation --<>----<>----<>----<>--\n");
    printf("<-.-> Entrez la reference : ");
    fgets(reference, sizeof(reference), stdin);
    reference[strcspn(reference, "\n")] = 0; // pour la suppression de caractere de nouvelle ligne

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].reference, reference) == 0) {
            printf("\n- - - > Reservation a ete trouvee ! < - - - \n");
            printf("1). Modifier\n");
            printf("2). Supprimer\n");
            int choix;
            scanf("%d", &choix);
            getchar(); // pour consommer le caractere de nouvelle ligne 

            if (choix == 1) {
                printf("<-.-> Entrez le nouveau nom - - - > ");
                fgets(reservations[i].nom, Max_taille, stdin);
                
                printf("<-.-> Entrez le nouveau prenom - - - > ");
                fgets(reservations[i].prenom, Max_taille, stdin);
                
                printf("<-.-> Entrez le nouveau telephone - - - > ");
                fgets(reservations[i].telephone, Max_taille, stdin);
              
                printf("<-.-> Entrez le nouvel age - - - > ");
                scanf("%d", &reservations[i].age);
                getchar(); // pour consommer le caractere de nouvelle ligne 

                printf("<-.-> Entrez le nouveau statut (valide, reporte, annule, traite) - - - > ");
                fgets(reservations[i].statut, Max_taille, stdin);

                printf("<-.-> Entrez la nouvelle date - - - > ");
                fgets(reservations[i].date, Max_taille, stdin);
                
            } else if (choix == 2) {
                for (int j = i; j < num_reservations - 1; j++) {
                    reservations[j] = reservations[j + 1];
                }
                num_reservations--;
                printf("\n- - - > Reservation supprimee ! < - - -\n");
            }
            return; // quittation apres le traitement de nouvelles donnees
        }
    }
    printf("\n- - - > Reservation non trouvee ! < - - -\n");
}


// pour afficher les details de reservation
void afficher() {
    char reference[10];
    printf("\n--<>----<>----<>----<>-- Affichage de reservation avec details --<>----<>----<>----<>--\n");
    printf("<-.-> Entrez la reference : ");
    fgets(reference, 10, stdin);
    reference[strlen(reference) - 1] = '\0';

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].reference, reference) == 0) {
            printf("Details de la reservation :\n");
            printf("<-.-> Nom : %s\n", reservations[i].nom);
            printf("<-.-> Prenom : %s\n", reservations[i].prenom);
            printf("<-.-> Telephone : %s\n", reservations[i].telephone);
            printf("<-.-> Age : %d\n", reservations[i].age);
            printf("<-.-> Statut : %s\n", reservations[i].statut);
            printf("<-.-> Reference : %s\n", reservations[i].reference);
            printf("<-.-> Date : %s\n", reservations[i].date);
            return;
        }
    }
    printf("Reservation non trouvee !\n");
}

// pour trier les reservations par nom
void trier_par_nom() {
    printf("\n--<>----<>----<>----<>-- Triage de reservations par nom a ete effectue --<>----<>----<>----<>--\n");
    for (int i = 0; i < num_reservations - 1; i++) {
        for (int j = i + 1; j < num_reservations; j++) {
            if (strcmp(reservations[i].nom, reservations[j].nom) > 0) {
                struct Reservation temp = reservations[i]; 
                reservations[i] = reservations[j];
                reservations[j] = temp;
            }
        }
    }
}

// pour trier les reservations par statut
void trier_par_statut() {
    printf("\n--<>----<>----<>-- Triage de reservations par statut a ete effectue --<>----<>----<>--\n");
    for (int i = 0; i < num_reservations - 1; i++) {
        for (int j = i + 1; j < num_reservations; j++) {
            if (strcmp(reservations[i].statut, reservations[j].statut) > 0) {
                struct Reservation temp = reservations[i]; 
                reservations[i] = reservations[j];
                reservations[j] = temp;
            }
        }
    }
}

// pour rechercher des reservations par reference
void rechercher_par_reference() {
    char reference[10];
    printf("\n--<>----<>----<>----<>-- Recherche de reservation par reference ( ID ) --<>----<>----<>----<>--\n");
    printf("<-.-> Entrez la reference : ");
    fgets(reference, 10, stdin);
    reference[strlen(reference) - 1] = '\0';

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].reference, reference) == 0) {
            printf("Reservation trouvee !\n");
            printf("<-.-> Nom : %s\n", reservations[i].nom);
            printf("<-.-> Prenom : %s\n", reservations[i].prenom);
            printf("<-.-> Telephone : %s\n", reservations[i].telephone);
            printf("<-.-> Age : %d\n", reservations[i].age);
            printf("<-.-> Statut : %s\n", reservations[i].statut);
            printf("<-.-> Reference : %s\n", reservations[i].reference);
            printf("<-.-> Date : %s\n", reservations[i].date);
            return;
        }
    }
    printf("\nReservation non trouvee !\n");
}

// pour rechercher des reservations par nom
//  pour rechercher des reservations par nom
void rechercher_par_nom() {
    char nom[Max_taille];
    printf("\n--<>----<>----<>----<>-- Recherche de reservation par nom --<>----<>----<>----<>--\n");
    printf("<-.-> Entrez le nom : ");
    fgets(nom, Max_taille, stdin);
    nom[strcspn(nom, "\n")] = 0; // pour consommer le caractere de nouvelle ligne

    int trouve = 0;//en l'initialise et en le donne 0, si la reservation a aete trouve, il va affecter trouve=1

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].nom, nom) == 0) {
            printf("Reservation trouvee !\n");
            printf("<-.-> Prenom : %s\n", reservations[i].prenom);
            printf("<-.-> Telephone : %s\n", reservations[i].telephone);
            printf("<-.-> Age : %d\n", reservations[i].age);
            printf("<-.-> Statut : %s\n", reservations[i].statut);
            printf("<-.-> Reference : %s\n", reservations[i].reference);
            printf("<-.-> Date : %s\n", reservations[i].date);
            trouve = 1; // s'il a trouve reserv-par-nom
        }
    }

    if (!trouve) {
        printf("\n- - - - > Reservation non trouvee ! < - - - -\n");
    }
}


// pour la calculation des statistiques
void calculer_statistiques() {
    reservations->age;
    int s = 0; // la somme 
    for ( int i = 0; i < num_reservations; i++)
    {
        s += reservations[i].age;
    }
    float moyen_age = s/num_reservations ;
    printf("Moyen d'age : %.2f\n",moyen_age);
    int tranche_0_18 = 0;
    int tranche_19_35 = 0;
    int tranche36plus = 0;
    
    for ( int i = 0; i < num_reservations; i++)
    {
        if (reservations[i].age>0 && reservations[i].age <=18 )
        {
            tranche_0_18++;
        }
        else if (reservations[i].age>=19 && reservations[i].age <=35 )
        {
            tranche_19_35++;
        }
        else if (reservations[i].age > 35 )
        {
            tranche36plus++;
        }
    }
    printf("\n- - - - > Statistique de reservation par tranche d,age < - - - -\n");
    printf("les reservations entre 0 et 18 : %d\n",tranche_0_18);
    printf("les reservations entre 19 et 35 : %d\n",tranche_19_35);
    printf("les reservations entre 36++ : %d\n",tranche36plus);
    
    for (int  i = 0; i < num_reservations; i++)
    {
        
    }
    


}

// pour l'affichage de la liste des reservations
void afficher_liste_reservations() {
    printf("\n--<>----<>----<>----<>-- Liste des reservations --<>----<>----<>----<>--\n\n");
    for (int i = 0; i < num_reservations; i++) {
    printf("\n--<>----<>----<>----<>----<>----<>----<>----<>----<>----<>----<>----<>--\n");
        printf("Nom : %s\nPrenom : %s\nTelephone : %s\nAge : %d\nStatut: %s\nReference: %s\nDate: %s\n",
                reservations[i].nom, reservations[i].prenom,
               reservations[i].telephone, reservations[i].age,
               reservations[i].statut, reservations[i].reference, reservations[i].date);
        printf("\n--<>----<>----<>----<>----<>----<>----<>----<>----<>----<>----<>----<>--\n");
    }
}

// fonction principale
int main() {
    int choix;
    do {
        printf("\n--<>----<>----<>--  Getion des reservations dentaire --<>----<>----<>--\n");
        printf("\n--<>----<>----<>----<>--         Menu:         --<>----<>----<>----<>--\n");
        printf("1). Ajouter reservation\n");
        printf("2). Modifier ou supprimer reservation\n");
        printf("3). Afficher details reservation\n");
        printf("4). Trier reservations par nom\n");
        printf("5). Trier reservations par statut\n");
        printf("6). Rechercher reservation par reference\n");
        printf("7). Rechercher reservation par nom\n");
        printf("8). Calculer statistiques\n");
        printf("9). Afficher la liste des reservations.\n");
        printf("0). Quitter\n");
        printf("\n-<>----<>----<>----<>-    Entrez votre choix:    -<>----<>----<>----<>-\nchoix : ");
        scanf("%d", &choix);
        getchar(); // pour consommer le caractere de nouvelle ligne 

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                modifier_suprimer_reservation();
                break;
            case 3:
                afficher();
                break;
            case 4:
                trier_par_nom();
                break;
            case 5:
                trier_par_statut();
                break;
            case 6:
                rechercher_par_reference();
                break;
            case 7:
                rechercher_par_nom();
                break;
            case 8:
                calculer_statistiques();
                break;
            case 9:
                afficher_liste_reservations();
                break;
            case 0:
                printf("<^-^>---+---<^-^>---+---<^-^>    A la prochaine fois    <^-^>---+---<^-^>---+---<^-^> \n");
                break;
            default:
                printf("- - - - > Choix invalide! Veuillez entrer un des options disponible < - - - -\n");
        }
    } while (choix != 0);
    return 0;
}
