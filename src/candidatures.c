#include "candidatures.h"

int chargementStages(int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tmax)
{
    int ref, dept, pourvu, nbEtu, tlog = 0;
    int candidat1 = 0, candidat2 = 0, candidat3 = 0;
    FILE *fic;

    fic = fopen("fichiers/offresDeStages.don", "r");

    if (fic == NULL)
    {
        perror("Erreur de lecture du fichier\n");
        exit(1);
    }

    while ((fscanf(fic, "%d %d", &ref, &dept)) == 2)
    {
        if (tlog == TAILLE_MAX)
        {
            fprintf(stderr, "tableau trop petit\n");
            fclose(fic);
            exit(1);
        }

        fscanf(fic, "%d", &pourvu);
        if (pourvu > 0)
        {
            tabR[tlog] = ref;
            tabD[tlog] = dept;
            tabPourvu[tlog] = pourvu;
            tabNumC[tlog] = 0;
            tlog++;
            continue;
        }

        candidat1 = candidat2 = candidat3 = 0;

        fscanf(fic, "%d", &nbEtu);
        if (nbEtu > 0)
        {
            if (nbEtu == 1)
                fscanf(fic, "%d", &candidat1);
            else if (nbEtu == 2)
            {
                fscanf(fic, "%d", &candidat1);
                fscanf(fic, "%d", &candidat2);
            }
            else
            {
                fscanf(fic, "%d", &candidat1);
                fscanf(fic, "%d", &candidat2);
                fscanf(fic, "%d", &candidat3);
            }
        }

        tabR[tlog] = ref;
        tabD[tlog] = dept;
        tabPourvu[tlog] = pourvu;
        tabNumC[tlog] = nbEtu;
        tabCand1[tlog] = candidat1;
        tabCand2[tlog] = candidat2;
        tabCand3[tlog] = candidat3;

        tlog++;
    }

    fclose(fic);
    return tlog;
}

void sauvegardeStages(int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog)
{
    FILE *fic;

    fic = fopen("fichiers/offresDeStages.don", "w");

    for (int i = 0; i < tlog; i++)
    {
        if (i == (tlog - 1))
        {
            if (tabPourvu[i] == 0)
                fprintf(fic, "%d %d\n%d\n%d", tabR[i], tabD[i], tabPourvu[i], tabNumC[i]);
            else
                fprintf(fic, "%d %d\n%d", tabR[i], tabD[i], tabPourvu[i]);
        }
        else
        {
            if (tabPourvu[i] == 0)
                fprintf(fic, "%d %d\n%d\n%d\n", tabR[i], tabD[i], tabPourvu[i], tabNumC[i]);

            else
                fprintf(fic, "%d %d\n%d\n", tabR[i], tabD[i], tabPourvu[i]);
        }
        if (tabNumC[i] > 0)
        {
            if (tabNumC[i] == 1)
                fprintf(fic, "%d\n", tabCand1[i]);
            else if (tabNumC[i] == 2)
                fprintf(fic, "%d\n%d\n", tabCand1[i], tabCand2[i]);
            else
                fprintf(fic, "%d\n%d\n%d\n", tabCand1[i], tabCand2[i], tabCand3[i]);
        }
    }

    fclose(fic);
}

int rechercheStage(int tabR[], int ref, int tlog)
{
    int index = 0;

    while (index != tlog)
    {
        if (ref == tabR[index])
        {
            return index;
        }

        index++;
    }
    return -1;
}

void afficherStagePourvu(int tabR[], int tabD[], int tabPourvu[], int tabRefEtu[], int tabEtu[], int tlog, int tlogE)
{
    int index;
    printf("Liste des stages pourvu\n");
    for (int i = 0; i < tlog; i++)
    {
        if (tabPourvu[i] != 0)
        {
            printf("Stage référence : %d\tDépartement : %d\n", tabR[i], tabD[i]);
            index = rechercheEtuParStage(tabR[i], tabRefEtu, tlogE);
            printf("Etudiant affecté: %d\n", tabEtu[index]);
        }
    }
}

void afficherStageNonPourvu(int tabR[], int tabD[], int tabPourvu[], int tlog)
{
    printf("Liste des stages non pourvu\n");
    for (int i = 0; i < tlog; i++)
    {
        if (tabPourvu[i] != 1)
        {
            printf("Stage référence : %d\tDépartement : %d\n", tabR[i], tabD[i]);
        }
    }
}

void afficherInfoStage(int index, int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[])
{
    printf("Stage référence : %d\tDepartement : %d\n", tabR[index], tabD[index]);
    if (tabPourvu[index] == 1)
    {
        printf("Stage pourvu : oui\n");
        return;
    }
    else
        printf("Stage pourvu : non\nNombre de candidats : %d\n", tabNumC[index]);
    if (tabNumC[index] > 0)
    {
        if (tabNumC[index] == 1)
            printf("Candidat 1 : %d\n", tabCand1[index]);
        else if (tabNumC[index] == 2)
            printf("Candidat 1 : %d\nCandidat 2 : %d\n", tabCand1[index], tabCand2[index]);
        else
            printf("Candidat 1 : %d\nCandidat 2: %d\nCandidat 3 : %d\n", tabCand1[index], tabCand2[index], tabCand3[index]);
    }
}

void afficherStagesDept(int dept, int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog)
{
    for (int i = 0; i < tlog; i++)
    {
        if (dept == tabD[i])
        {
            printf("Stage : %d\tDept : %d\n", tabR[i], tabD[i]);
            if (tabPourvu[i] == 1)
            {
                printf("Stage pourvu : oui\n");
                return;
            }
            else
                printf("Stage pourvu : non\nNombre de candidats : %d\n", tabNumC[i]);
            if (tabNumC[i] > 0)
            {
                if (tabNumC[i] == 1)
                    printf("Candidat 1 : %d\n", tabCand1[i]);
                else if (tabNumC[i] == 2)
                    printf("Candidat 1 : %d\nCandidat 2 : %d\n", tabCand1[i], tabCand2[i]);
                else
                    printf("Candidat 1 : %d\nCandidat 2: %d\nCandidat 3 : %d\n", tabCand1[i], tabCand2[i], tabCand3[i]);
            }
        }
    }
}

void afficherReferences(int tabR[], int tabPourvu[], int tlog)
{
    for (int i = 0; i < tlog; i++)
    {
        if (tabPourvu[i] != 1)
            printf("Référence: %d\n", tabR[i]);
    }
}

int nombreDeCandidatures(int tabCand1[], int tabCand2[], int tabCand3[], int numEtu, int tlog)
{
    int cpt = 0;
    for (int i = 0; i < tlog; i++)
    {
        if (tabCand1[i] == numEtu || tabCand2[i] == numEtu || tabCand3[i] == numEtu)
        {
            cpt++;
        }
    }
    return cpt;
}

int nombreDeCandidats(int index, int tabNumC[])
{
    return tabNumC[index];
}

int rechercheStageParEtu(int numEtu, int tabCand1[], int tabCand2[], int tabCand3[], int tabRef[], int tlog)
{
    int cpt = 1, trouve = 0;
    for (int i = 0; i < tlog; i++)
    {
        if (tabCand1[i] == numEtu || tabCand2[i] == numEtu || tabCand3[i] == numEtu)
        {
            printf("%d. Référence: %d\n", cpt, tabRef[i]);
            trouve = 1;
            cpt++;
        }
    }
    if (trouve == 0)
    {
        printf("Aucun stage candidaté !\n");
        return trouve;
    }
    return trouve;
}

void candidature(int numCand, int index, int tabNumC[], int tabCand[])
{
    tabCand[index] = numCand;
    tabNumC[index]++;
}

void suppressionCandidatures(int numCand, int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog)
{
    for (int i = 0; i < tlog; i++)
    {
        if (tabCand1[i] == numCand)
        {
            tabCand1[i] = tabCand2[i];
            tabCand2[i] = tabCand3[i];
            tabCand3[i] = 0;
            tabNumC[i]--;
        }
        else if (tabCand2[i] == numCand)
        {
            tabCand2[i] = tabCand3[i];
            tabCand3[i] = 0;
            tabNumC[i]--;
        }
        else
        {
            tabCand3[i] = 0;
            tabNumC[i]--;
        }
    }
}

void stagePourvu(int numCand, int index, int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog)
{
    tabPourvu[index] = 1;
    tabNumC[index] = tabCand1[index] = tabCand2[index] = tabCand3[index] = 0;

    suppressionCandidatures(numCand, tabNumC, tabCand1, tabCand2, tabCand3, tlog);
}

void afficherReferencesDisponibles(int tabR[], int tabPourvu[], int tabNumC[], int tlog)
{
    for (int i = 0; i < tlog; i++)
    {
        if (tabPourvu[i] == 0 && tabNumC[i] < 3)
            printf("Référence: %d\n", tabR[i]);
    }
}

int saisirNotes(float tabNote1[], float tabNote2[], float tabNote3[], int index)
{
    float note;
    int count = 1;

    while (count <= 3)
    {
        printf("Saisir une note (-1 pour quitter): ");
        scanf(" %f%*c", &note);

        if (note == -1)
        {
            return count - 1;
        }

        switch (count)
        {
            case 1:
                tabNote1[index] = note;
                printf("Note 1 enregistrée: %.2f\n", tabNote1[index]);
                break;
            case 2:
                tabNote2[index] = note;
                printf("Note 2 enregistrée: %.2f\n", tabNote2[index]);
                break;
            case 3:
                tabNote3[index] = note;
                printf("Note 3 enregistrée: %.2f\n", tabNote3[index]);
                break;
        }

        count++;
    }

    return count - 1;
}

void afficherNotesTriees(float note1, float note2, float note3)
{
    float n1 = note1, n2 = note2, n3 = note3;

    if (n1 < n2)
    {
        float temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if (n1 < n3)
    {
        float temp = n1;
        n1 = n3;
        n3 = temp;
    }
    if (n2 < n3)
    {
        float temp = n2;
        n2 = n3;
        n3 = temp;
    }

    printf("Notes triées : %.2f, %.2f, %.2f\n", n1, n2, n3);
}