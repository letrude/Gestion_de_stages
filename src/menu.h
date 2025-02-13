/**
 * \file menu.h
 * \author Gabriel COUDEL-KOUMBA/Ange GRIMAUD
 * \date 06/11/2024
 * \brief Fonctions des menus
 */

#include <stdio.h>
#include <string.h>

#ifndef MENU_H
#define MENU_H

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction de gestion des menus
 */
int menuPrincipal(void);

/**
 * \author Ange GRIMAUD
 * \brief fonction de gestion du menu étudiant
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tlog la taille logique des tableaux de candidature
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tloge la taille logique des tableaux de étudiant
 * \param numEtu le numéro de l'étudiant
 * \param tabNote tableau de flotants contenant les notes des élèves
 */
void menuEtu(int tabR[], int tabD[], int tabPourvu[], int *tlog, int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tabNB[], int tabRef[], int *tloge, int numEtu, float tabNote[]);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction de gestion du menu responsable
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabEtu tableau d'entiers contenant les numéros étudiants
 * \param tabRefEtu tableau d'entiers contenant les références des stages des élèves
 * \param tabNoteEtu tableau de flotants contenant les notes des élèves
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tabReferences tableau d'entier contenant les références des étudiants auxquels ont a ajouté au moins une note lors de cette utilisation du programme
 * \param tabNote1 tableau de flottant contenant la 1ére note des étudiants
 * \param tabNote2 tableau de flottant contenant la 2e note des étudiants
 * \param tabNote3 tableau de flottant contenant la 3e note des étudiants
 * \param cpt compteur d'étudiants auxquels ont a ajouté au moins une note lors de cette utilisation du programme
 * \param tlogE taille logique des tableaux étudiants
 * \param tlogS taille logique des tableaux candidatures
 */
void menuResponsable(int tabR[], int tabD[], int tabPourvu[], int tabRefEtu[], int tabEtu[], float tabNoteEtu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tabReferences[], float tabNote1[], float tabNote2[], float tabNote3[], int *tlogS, int *tlogE, int *cpt);

#endif