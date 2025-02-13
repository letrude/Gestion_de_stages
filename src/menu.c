#include "menu.h"
#include "etudiants.h"
#include "candidatures.h"

int menuPrincipal(void)
{
    char choix[10];

    printf("Bienvenue dans le Gestionnaire de stage !\n");

    while (1)
    {
        printf("\nE.\t Menu étudiants\n");
        printf("R.\t Menu responsable\n");
        printf("Q.\t Quitter\n\n");
        printf("Votre choix: ");

        fgets(choix, sizeof(choix), stdin);

        choix[strcspn(choix, "\n")] = 0;

        if (strlen(choix) == 1)
        {
            if (choix[0] == 'E' || choix[0] == 'e')
                return 1;
            else if (choix[0] == 'R' || choix[0] == 'r')
                return 2;
            else if (choix[0] == 'Q' || choix[0] == 'q')
                return 0;
            else
                printf("Choix incorrect, veuillez resaisir.\n");
        }
        else
            printf("Choix incorrect, veuillez resaisir.\n");
    }
}

void menuEtu(int tabR[], int tabD[], int tabPourvu[], int *tlog, int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tabNB[], int tabRef[], int *tloge, int numEtu, float tabNote[])
{
    char choix[10], pris[10];
    int dept, refACandidater, i, refASupprimer, trouve = 0;

    printf("Bienvenue dans la section étudiant!\n\n");

    while (1)
    {
        printf("P.\t Voir les stages non pourvus.\n");
        printf("S.\t Stages candidatés ou accepté.\n");
        printf("R.\t Stages selon le numéro ou le département.\n");
        printf("A.\t Postuler à un stage.\n");
        printf("E.\t Retirer une candidature.\n");
        printf("V.\t Voir sa note.\n");
        printf("M.\t Voir la moyenne de tous les étudiants.\n");
        printf("Q.\t Quitter\n\n");
        printf("Votre choix: ");

        fgets(choix, sizeof(choix), stdin);

        choix[strcspn(choix, "\n")] = 0;

        sauvegardeFichier(tabNB, tabRef, tabNote, *tloge);
        sauvegardeStages(tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3, *tlog);

        if (strlen(choix) == 1)
        {
            if (choix[0] == 'P' || choix[0] == 'p')
            {
                printf("\n");
                afficherStageNonPourvu(tabR, tabD, tabPourvu, *tlog);
                printf("\n");
            }
            else if (choix[0] == 'S' || choix[0] == 's')
            {
                printf(" \nStage(s) candidaté(s) : \n\n");
                rechercheStageParEtu(numEtu, tabCand1, tabCand2, tabCand3, tabR, *tlog);
                printf("\nStage accepté : \n\n");
                rechercheStagesAccepté(tabNB, tabRef, *tloge, numEtu);
            }
            else if (choix[0] == 'R' || choix[0] == 'r')
            {
                printf("N.\t Stages selon le numéro.\n");
                printf("D.\t Stages selon le département.\n");
                printf("Q.\t Quitter\n\n");
                printf("Votre choix: ");
                fgets(pris, sizeof(pris), stdin);
                pris[strcspn(pris, "\n")] = 0;
                if (pris[0] == 'N' || pris[0] == 'n')
                {
                    int ref;
                    printf("Saisir la référence du stage: ");
                    scanf(" %d%*c", &ref);
                    int index = rechercheStage(tabR, ref, *tlog);
                    printf("\n");
                    if (index >= 0)
                    {
                        afficherInfoStage(index, tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3);
                        printf("\n");
                    }
                    else
                    {
                        printf("\n");
                        fprintf(stderr, "Référence de stage introuvable\nVeuillez saisir une référence valide.\n");
                        continue;
                    }
                }
                else if (pris[0] == 'D' || pris[0] == 'd')
                {
                    printf("Quel departement chercher : ");
                    scanf(" %d%*c", &dept);
                    printf("\n");
                    afficherStagesDept(dept, tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3, *tlog);
                    printf("\n");
                }
                else if (pris[0] == 'Q' || pris[0] == 'q')
                {
                    return;
                }
            }
            else if (choix[0] == 'A' || choix[0] == 'a')
            {
                printf("\n");
                afficherReferencesDisponibles(tabR, tabPourvu, tabNumC, *tlog);
                printf("\nA quel stage candidater ?");
                scanf(" %d%*c", &refACandidater);
                if (rechercheStage(tabR, refACandidater, *tlog) == -1)
                {
                    fprintf(stderr, "\nCe stage n'existe pas !\n\n");
                    continue;
                }
                for (i = 0; tabR[i] != refACandidater; i++)
                {
                }
                if (tabPourvu[i] == 1)
                {
                    fprintf(stderr, "\nStage déjà pourvu !\n\n");
                }
                else if (aUnStage(tabNB, tabRef, numEtu, *tloge) == 1)
                {
                    fprintf(stderr, "\nVous êtes déjà accepté dans un stage !\n\n");
                }
                else if (tabNumC[i] == 3)
                {
                    fprintf(stderr, "\nStage Complet !\n\n");
                }
                else if (nombreDeCandidatures(tabCand1, tabCand2, tabCand3, numEtu, *tlog) == 3)
                {
                    fprintf(stderr, "\nVous avez fais trop de candidatures !\n\n");
                }
                else if (tabCand1[i] == numEtu || tabCand2[i] == numEtu || tabCand3[i] == numEtu)
                {
                    fprintf(stderr, "\nDéjà inscrit !\n\n");
                }
                else if (tabNumC[i] == 2)
                {
                    tabNumC[i]++;
                    tabCand3[i] = numEtu;
                    printf("\nCandidature mise en ligne !\n\n");
                }
                else if (tabNumC[i] == 1)
                {
                    tabNumC[i]++;
                    tabCand2[i] = numEtu;
                    printf("\nCandidature mise en ligne !\n\n");
                }
                else if (tabNumC[i] == 0)
                {
                    tabNumC[i]++;
                    tabCand1[i] = numEtu;
                    printf("\nCandidature mise en ligne !\n\n");
                }
            }
            else if (choix[0] == 'E' || choix[0] == 'e')
            {
                printf("\n");
                trouve = rechercheStageParEtu(numEtu, tabCand1, tabCand2, tabCand3, tabR, *tlog);
                printf("\n");
                if (trouve == 0)
                {
                    if (aUnStage(tabNB, tabRef, numEtu, *tloge) == 1)
                    {
                        fprintf(stderr, "\nVous êtes déjà accepté dans un stage !\n\n");
                    }
                    else
                    {
                        fprintf(stderr, "\nVous n'avez postulé à aucun stage !\n\n");
                    }
                    continue;
                }
                printf("A quel stage retirer la candidature ?");
                scanf(" %d%*c", &refASupprimer);
                if (rechercheStage(tabR, refASupprimer, *tlog) == -1)
                {
                    fprintf(stderr, "\nCe stage n'existe pas !\n\n");
                    continue;
                }
                for (i = 0; tabR[i] != refASupprimer; i++)
                {
                }
                if (tabCand1[i] != numEtu && tabCand2[i] != numEtu && tabCand3[i] != numEtu)
                {
                    fprintf(stderr, "\nVous avez choisi un stage pour lequel vous n'avez pas candidaté !\n\n");
                }
                else if (tabCand3[i] == numEtu)
                {
                    tabNumC[i]--;
                    printf("\nLa suppression a bien fonctionnée !\n\n");
                }
                else if (tabCand2[i] == numEtu)
                {
                    tabCand2[i] = tabCand3[i];
                    tabNumC[i]--;
                    printf("\nLa suppression a bien fonctionnée !\n\n");
                }
                else if (tabCand1[i] == numEtu)
                {
                    tabCand1[i] = tabCand2[i];
                    tabCand2[i] = tabCand3[i];
                    tabNumC[i]--;
                    printf("\nLa suppression a bien fonctionnée !\n\n");
                }
            }
            else if (choix[0] == 'V' || choix[0] == 'v')
            {
                for (i = 0; i < *tloge; i++)
                {
                    if (tabNB[i] == numEtu)
                    {
                        if (tabNote[i] == -1)
                        {
                            fprintf(stderr, "\nVous n'avez pas encore de note\n\n");
                        }
                        else
                        {
                            printf("\nVotre note est : %.2f\n\n", tabNote[i]);
                        }
                    }
                }
            }
            else if (choix[0] == 'M' || choix[0] == 'm') 
            {
                printf("\n");
                afficheNotes(tabNB, tabNote, *tloge);
                printf("\n");
            }
            else if (choix[0] == 'Q' || choix[0] == 'q')
            {
                return;
            }
            else
            {
                fprintf(stderr, "\nChoix incorrect, veuillez resaisir.\n\n");
            }
        }
        else
        {
            fprintf(stderr, "\nChoix incorrect, veuillez resaisir.\n\n");
        }
    }
}

void menuResponsable(int tabR[], int tabD[], int tabPourvu[], int tabRefEtu[], int tabEtu[], float tabNoteEtu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tabReferences[], float tabNote1[], float tabNote2[], float tabNote3[], int *tlogS, int *tlogE, int *cpt)
{
    int dept;
    char choix[10];

    printf("Bienvenue dans la section Responsable !\n");

    while (1)
    {
        printf("\n\tP. Afficher les stages pourvu\n");
        printf("\tN. Afficher les stages non pourvu\n");
        printf("\tE. Afficher la liste des étudiants sans stages\n");
        printf("\tI. Afficher les informations disponibles sur un stage\n");
        printf("\tR. Recherche de stage(s) selon la référence ou le département\n");
        printf("\tA. Affecter un étudiant à un stage\n");
        printf("\tS. Saisir les notes d'un stage\n");
        printf("\tL. Ajouter une offre de stage\n");
        printf("\tJ. Ajouter un étudiant\n");
        printf("\tM. Voir la moyenne de tous les étudiants.\n");
        printf("\tQ. Quitter\n\n");
        printf("Votre choix: ");

        fgets(choix, sizeof(choix), stdin);

        choix[strcspn(choix, "\n")] = 0;

        if (strlen(choix) == 1)
        {
            if (choix[0] == 'P' || choix[0] == 'p')
            {
                printf("\n");
                afficherStagePourvu(tabR, tabD, tabPourvu, tabRefEtu, tabEtu, *tlogS, *tlogE);
            }
            else if (choix[0] == 'N' || choix[0] == 'n')
            {
                printf("\n");
                afficherStageNonPourvu(tabR, tabD, tabPourvu, *tlogS);
            }
            else if (choix[0] == 'E' || choix[0] == 'e')
            {
                printf("\n");
                pasDeStage(tabEtu, tabRefEtu, *tlogE);
            }
            else if (choix[0] == 'I' || choix[0] == 'i')
            {
                int ref;
                printf("Saisir la référence du stage: ");
                scanf("%d%*c", &ref);
                printf("\n");
                int index = rechercheStage(tabR, ref, *tlogS);
                if (index >= 0)
                    afficherInfoStage(index, tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3);
                else
                {
                    fprintf(stderr, "Référence de stage introuvable\nVeuillez saisir une référence valide.\n");
                    continue;
                }
            }
            else if (choix[0] == 'R' || choix[0] == 'r')
            {
                printf("\tN. Stages selon le numéro\n");
                printf("\tD. Stages selon le département\n");
                printf("\tQ. Quitter\n\n");
                printf("Votre choix: ");
                fgets(choix, sizeof(choix), stdin);
                choix[strcspn(choix, "\n")] = 0;
                printf("\n");
                if (choix[0] == 'N' || choix[0] == 'n')
                {
                    int ref;

                    afficherReferences(tabR, tabPourvu, *tlogS);
                    printf("\n");

                    printf("Saisir la référence du stage: ");
                    scanf("%d%*c", &ref);
                    printf("\n");
                    int index = rechercheStage(tabR, ref, *tlogS);
                    if (index >= 0)
                        afficherInfoStage(index, tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3);
                    else
                    {
                        fprintf(stderr, "Référence de stage introuvable\nVeuillez saisir une référence valide.\n");
                        continue;
                    }
                }
                else if (choix[0] == 'D' || choix[0] == 'd')
                {
                    printf("Saisir le numéro de département: ");
                    scanf("%d%*c", &dept);
                    printf("\n");
                    afficherStagesDept(dept, tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3, *tlogS);
                    printf("\n");
                }
                else if (choix[0] == 'Q' || choix[0] == 'q')
                {
                    return;
                }
            }
            else if (choix[0] == 'A' || choix[0] == 'a')
            {
                int ref, index, etu;
                printf("\n");
                afficherReferences(tabR, tabPourvu, *tlogS);
                printf("\n");
                printf("Saisir la référence du stage a pourvoir: ");
                scanf("%d%*c", &ref);
                printf("\n");
                index = rechercheStage(tabR, ref, *tlogS);
                if (index == -1)
                {
                    fprintf(stderr, "Référence introuvable.\nVeuillez saisir une référence de stage valide.\n");
                    continue;
                }
                afficherInfoStage(index, tabR, tabD, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3);
                printf("\n");
                printf("Saisir le numéro de l'étudiant à affecter au stage: ");
                scanf("%d%*c", &etu);
                stagePourvu(etu, index, tabPourvu, tabNumC, tabCand1, tabCand2, tabCand3, *tlogS);
                affectation(tabEtu, tabRefEtu, *tlogE, etu, ref);
                printf("\nL'affectation est fini !\n\n");
            }
            else if (choix[0] == 'S' || choix[0] == 's')
            {
                int etu, index, nbNotes;
                printf("\n");
                afficherEtudiants(tabEtu, tabRefEtu, tabNoteEtu, *tlogE);
                printf("\n");
                printf("Saisir un numéro d'étudiant: ");
                scanf("%d%*c", &etu);

                if (rechercheEtu(tabEtu, *tlogE, etu) == -1)
                {
                    fprintf(stderr, "Numéro d'étudiant introuvable\nVeuillez saisir un numéro valide\n");
                    continue;
                }

                if(tabNoteEtu[rechercheEtu(tabEtu, *tlogE, etu)] > -1)
                {
                    fprintf(stderr, "Moyenne déjà entrée\n");
                    continue;
                }

                if(tabRefEtu[rechercheEtu(tabEtu, *tlogE, etu)] < 0)
                {
                    fprintf(stderr, "Cet étudiant n'a pas de stage\nImpossible de rentrer une note\n");
                    continue;
                }

                index = rechercheEtu(tabReferences, *cpt, etu);

                if (index == -1)
                {
                    tabReferences[*cpt] = etu;

                    nbNotes = saisirNotes(tabNote1, tabNote2, tabNote3, *cpt);

                    if (nbNotes < 3)
                        printf("Stage en cours\n");
                    else
                    {
                        afficherNotesTriees(tabNote1[*cpt], tabNote2[*cpt], tabNote3[*cpt]);
                        moyenne(tabEtu, tabNoteEtu, etu, tabNote1[*cpt], tabNote2[*cpt], tabNote3[*cpt], *tlogE);
                    }
                    (*cpt)++;
                }
                else
                {
                    if (tabNote1[index] < 0 || tabNote1[index] > 20)
                    {
                        printf("Saisir la note d'entreprise: ");
                        scanf("%f%*c", &tabNote1[index]);
                    }
                    if (tabNote2[index] < 0 || tabNote2[index] > 20)
                    {
                        printf("Saisir note de rapport: ");
                        scanf("%f%*c", &tabNote2[index]);
                    }
                    if (tabNote3[index] < 0 || tabNote3[index] > 20)
                    {
                        printf("Saisir note de soutenance: ");
                        scanf("%f%*c", &tabNote3[index]);
                    }

                    if (tabNote1[index] >= 0 && tabNote2[index] >= 0 && tabNote3[index] >= 0 && tabNote1[index] <= 20 && tabNote2[index] <= 20 && tabNote3[index] <= 20)
                        moyenne(tabEtu, tabNoteEtu, etu, tabNote1[index], tabNote2[index], tabNote3[index], *tlogE);
                }
            }
            else if (choix[0] == 'L' || choix[0] == 'l')
            {
                int ref, dept;
                printf("Saisir le numéro de la référence: ");
                scanf("%d%*c", &ref);
                printf("Saisir le département: ");
                scanf("%d%*c", &dept);

                if (rechercheStage(tabR, ref, *tlogS) > -1)
                {
                    fprintf(stderr, "Référence déjà présente\n");
                    continue;
                }

                tabR[*tlogS] = ref;
                tabD[*tlogS] = dept;
                tabPourvu[*tlogS] = 0;
                tabNumC[*tlogS] = 0;
                (*tlogS)++;
                printf("\nAjout du stage effectué !\n\n");
            }
            else if (choix[0] == 'J' || choix[0] == 'j')
            {
                int num;
                printf("Saisir le numéro de l'étudiant: ");
                scanf("%d%*c", &num);

                if (rechercheEtu(tabEtu, *tlogE, num) > -1)
                {
                    fprintf(stderr, "Numéro étudiant déjà présent\n");
                    continue;
                }

                tabEtu[*tlogE] = num;
                tabRefEtu[*tlogE] = -1;
                tabNoteEtu[*tlogE] = -1;
                (*tlogE)++;
                printf("\nAjout de l'étudiant effectué !\n\n");
            }
            else if (choix[0] == 'M' || choix[0] == 'm') {
                printf("\n");
                afficheNotes(tabEtu, tabNoteEtu, *tlogE);
            }
            else if (choix[0] == 'Q' || choix[0] == 'q')
                return;
            else
                fprintf(stderr, "Choix incorrect, veuillez resaisir.\n");
        }
        else
            fprintf(stderr, "Choix incorrect, veuillez resaisir.\n");
    }
}