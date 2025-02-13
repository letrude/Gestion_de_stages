#include "candidatures.h"
#include "etudiants.h"
#include "menu.h"

void globale(void)
{
    int choixP, tlogS, tlogE, numEtu, cpt = 0;

    int tabRefStages[TAILLE_MAX], tabDept[TAILLE_MAX], tabNumCandStages[TAILLE_MAX] = {0}, tabPourvu[TAILLE_MAX];
    int tabEtudiantNumeroEtudiant[TAILLE_MAX], tabEtudiantReferenceStage[TAILLE_MAX];
    float tabEtudiantNote[TAILLE_MAX];
    int tabCandidat1[TAILLE_MAX] = {0}, tabCandidat2[TAILLE_MAX] = {0}, tabCandidat3[TAILLE_MAX] = {0};
    int tabReferences[TAILLE_MAX];
    float tabNote1[TAILLE_MAX] = {-2}, tabNote2[TAILLE_MAX] = {-2}, tabNote3[TAILLE_MAX] = {-2};

    tlogS = chargementStages(tabRefStages, tabDept, tabPourvu, tabNumCandStages, tabCandidat1, tabCandidat2, tabCandidat3, TAILLE_MAX);
    tlogE = chargementEtudiants(tabEtudiantNumeroEtudiant, tabEtudiantReferenceStage, tabEtudiantNote);

    choixP = menuPrincipal();

    while (choixP != 0)
    {
        if (choixP == 1)
        {
            printf("Veuillez saisir votre numéro d'étudiant: ");
            scanf("%d%*c", &numEtu);
            if (rechercheEtu(tabEtudiantNumeroEtudiant, tlogE, numEtu) != -1)
                menuEtu(tabRefStages, tabDept, tabPourvu, &tlogS, tabNumCandStages, tabCandidat1, tabCandidat2, tabCandidat3, tabEtudiantNumeroEtudiant, tabEtudiantReferenceStage, &tlogE, numEtu, tabEtudiantNote);
            else
                printf("Numéro d'étudiant inconnu\nVeuillez saisir un numéro valide\n");
        }
        else if (choixP == 2)
        {
            menuResponsable(tabRefStages, tabDept, tabPourvu, tabEtudiantReferenceStage, tabEtudiantNumeroEtudiant, tabEtudiantNote, tabNumCandStages, tabCandidat1, tabCandidat2, tabCandidat3, tabReferences, tabNote1, tabNote2, tabNote3,  &tlogS, &tlogE, &cpt);
        }
        choixP = menuPrincipal();
    }

    printf("Sauvegarde des données...\n");
    sauvegardeFichier(tabEtudiantNumeroEtudiant, tabEtudiantReferenceStage, tabEtudiantNote, tlogE);
    sauvegardeStages(tabRefStages, tabDept, tabPourvu, tabNumCandStages, tabCandidat1, tabCandidat2, tabCandidat3, tlogS);
    printf("Fermeture.\n");
}

int main(void)
{
    globale();
    return 0;
}