#include <stdio.h>
#include <string.h> 

#define MAX_PERSONNES 100


struct Adresse {
    char rue[50];
    char ville[50];
    char codePostale[20];
};


struct Personne {
    char nom[50];
    int age; 
    struct Adresse adresse;  
};


void creePersonne(struct Personne *P);
void affichPersonne(const struct Personne *P);
void mettreAjourPersonne(struct Personne *P);
void supprimerPersonne(struct Personne personnes[], int *nbrPersonne);

int main() {
    struct Personne personnes[MAX_PERSONNES];
    int nbrPersonne = 0;
    int choix;
    
    do {
        printf("\nMenu\n");
        printf("1. Créer une personne\n");
        printf("2. Afficher une personne\n");
        printf("3. Mettre à jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);
        getchar();  

        switch (choix) {
            case 1:
                if (nbrPersonne < MAX_PERSONNES) {
                    creePersonne(&personnes[nbrPersonne]);
                    nbrPersonne++;
                } else {
                    printf("Limite de personnes atteinte.\n");
                }
                break;

            case 2:
                for (int i = 0; i < nbrPersonne; i++) {
                    affichPersonne(&personnes[i]);
                }
                break;

            case 3:
                printf("Entrez l'indice de la personne à mettre à jour (0 à %d): ", nbrPersonne - 1);
                int indMAJ;
                scanf("%d", &indMAJ);
                if (indMAJ >= 0 && indMAJ < nbrPersonne) {
                    mettreAjourPersonne(&personnes[indMAJ]);
                } else {
                    printf("Index invalide.\n");
                }
                break;

            case 4:
                supprimerPersonne(personnes, &nbrPersonne);
                break;

            case 5:
                printf("Au revoir!\n");
                break;

            default:
                printf("Option invalide.\n");
        }
    } while (choix != 5);

    return 0;
}


void creePersonne(struct Personne *P) {
    printf("Entrez le nom: ");
    scanf(" %[^\n]", P->nom);
    printf("Entrez l'âge: ");
    scanf("%d", &P->age);
    printf("Entrez la rue: ");
    scanf(" %[^\n]", P->adresse.rue);
    printf("Entrez la ville: ");
    scanf(" %[^\n]", P->adresse.ville);
    printf("Entrez le code postal: ");
    scanf(" %[^\n]", P->adresse.codePostale);
}


void affichPersonne(const struct Personne *P) {
    printf("Nom: %s, Âge: %d, Adresse: %s, %s, %s\n", 
           P->nom, P->age, P->adresse.rue, P->adresse.ville, P->adresse.codePostale);
}


void mettreAjourPersonne(struct Personne *P) {
    printf("Entrez le nouvel âge: ");
    scanf("%d", &P->age);
    printf("Entrez la nouvelle rue: ");
    scanf(" %[^\n]", P->adresse.rue);
    printf("Entrez la nouvelle ville: ");
    scanf(" %[^\n]", P->adresse.ville);
    printf("Entrez le nouveau code postal: ");
    scanf(" %[^\n]", P->adresse.codePostale);
}


void supprimerPersonne(struct Personne personnes[], int *nbrPersonne) {
    printf("Entrez l'indice de la personne à supprimer (0 à %d): ", *nbrPersonne - 1);
    int indSup;
    scanf("%d", &indSup);
    
    if (indSup >= 0 && indSup < *nbrPersonne) {
        
        for (int i = indSup; i < *nbrPersonne - 1; i++) {
            personnes[i] = personnes[i + 1];
        }
        (*nbrPersonne)--;  
        printf("Personne supprimée avec succès!\n");
    } else {
        printf("Index invalide.\n");
    }
}

