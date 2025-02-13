#include "etudiants.h"

int chargementEtudiants(int tabNumero[], int tabReference[], float tabNote[])
{
    int numero, reference, tailleLogique = 0;
    float note;
    FILE *fic;

    if ((fic = fopen("fichiers/etudiants.don", "r")) == NULL)
    {
        perror("erreur");
        exit(1);
    }

    while (fscanf(fic, "%d %d %f", &numero, &reference, &note) == 3)
    {
        if (tailleLogique == TAILLE_MAX)
        {
            fprintf(stderr, "tableau trop petit\n");
            exit(1);
        }
        tabNumero[tailleLogique] = numero;
        tabReference[tailleLogique] = reference;
        tabNote[tailleLogique] = note;
        tailleLogique++;
    }
    fclose(fic);
    return tailleLogique;
}

void sauvegardeFichier(int tabNB[], int tabRef[], float tabNote[], int tailleLog)
{
    FILE *f;

    f = fopen("fichiers/etudiants.don", "w");

    for (int i = 0; i < tailleLog; i++)
    {
        if (i == tailleLog - 1)
        {
            if (tabNote[i] == -1)
            {
                fprintf(f, "%d %d %.f", tabNB[i], tabRef[i], tabNote[i]);
            }
            else
            {
                fprintf(f, "%d %d %.2f", tabNB[i], tabRef[i], tabNote[i]);
            }
        }
        else
        {
            if (tabNote[i] == -1)
            {
                fprintf(f, "%d %d %.f\n", tabNB[i], tabRef[i], tabNote[i]);
            }
            else
            {
                fprintf(f, "%d %d %.2f\n", tabNB[i], tabRef[i], tabNote[i]);
            }
        }
    }
    fclose(f);
}

int rechercheEtu(int tabNB[], int tlog, int etu)
{
    for (int i = 0; i < tlog; i++)
    {
        if (etu == tabNB[i])
        {
            return i;
        }
    }
    return -1;
}

int rechercheEtuParStage(int ref, int tabRef[], int tlog)
{
    for (int i = 0; i < tlog; i++)
    {
        if (tabRef[i] == ref)
        {
            return i;
        }
    }
    return -1;
}

void pasDeStage(int tabNB[], int tabRef[], int tlog)
{
    int cpt = 1;
    printf("Liste des étudiants sans stage:\n");
    for (int i = 0; i < tlog; i++)
    {
        if (tabRef[i] == -1)
        {
            printf("%d. %d\n", cpt, tabNB[i]);
            cpt++;
        }
    }
}

void affectation(int tabNB[], int tabRef[], int tlog, int etu, int ref)
{
    int indice = rechercheEtu(tabNB, tlog, etu);
    if (indice == -1)
    {
        printf("étudiant pas trouvé\n");
        return;
    }
    tabRef[indice] = ref;
}

void moyenne(int tabNB[], float tabNote[], int etu, float note1, float note2, float note3, int tlog)
{
    float note = 0;
    int i;
    note = ((note1*2) + note2 + note3) / 4;
    i = rechercheEtu(tabNB, tlog, etu);
    if (i == -1)
    {
        fprintf(stderr, "étudiant pas trouvé\n");
        exit(1);
    }
    tabNote[i] = note;
}

void afficherEtudiants(int tabNB[], int tabRef[], float tabNote[], int tlog)
{
    int cpt = 1;
    for (int i = 0; i < tlog; i++)
    {
        if ((tabRef[i] > 0 && tabNote[i] < 0))
        {
            printf("%d. %d\n", cpt, tabNB[i]);
            cpt++;
        }
    }
}

void rechercheStagesAccepté(int tabNB[], int tabRef[], int tlog, int numEtu)
{
    int i = rechercheEtu(tabNB, tlog, numEtu);
    if (i == -1)
    {
        return;
    }
    if (tabRef[i] == -1)
    {
        printf("Aucun stage accepté !\n\n");
        return;
    }
    printf("Référence : %d\n\n", tabRef[i]);
}

int aUnStage(int tabNB[], int tabRef[], int numEtu, int tlog)
{
    for (int i = 0; i < tlog; i++)
    {
        if (tabNB[i] == numEtu)
        {
            if (tabRef[i] == -1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return -1;
}

void afficheNotes(int tabNB[], float tabNote[], int tlog)
{
    int tabN[tlog], tempI, tlogN = 0, tlogS = 0, minIndex;
    float tabNO[tlog], temp;

    int tabEtuNegatif[tlog];

    for (int i = 0; i < tlog; i++)
    {
        if (tabNote[i] == -1)
        {
            tabEtuNegatif[tlogN] = tabNB[i];
            tlogN++;
        }
        else
        {
            tabN[tlogS] = tabNB[i];
            tabNO[tlogS] = tabNote[i];
            tlogS++;
            for (int k = 0; k < tlog - 1; k++)
            {
                minIndex = k;
                for (int j = k + 1; j < tlog; j++)
                {
                    if (tabNO[j] < tabNO[minIndex])
                    {
                        minIndex = j;
                    }
                }

                temp = tabNO[i];
                tabNO[i] = tabNO[minIndex];
                tabNO[minIndex] = temp;

                tempI = tabN[i];
                tabN[i] = tabN[minIndex];
                tabN[minIndex] = tempI;
            }
        }
    }

    for (int i = 0; i < tlogS; i++){
        printf("Étudiant: %d\tnote: %.2f\n", tabN[i], tabNO[i]);
    }
    for (int i = 0; i < tlogN; i++){
        printf("Étudiant: %d\tnote: stage en cours\n", tabEtuNegatif[i]);
    }
}