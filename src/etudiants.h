/**
 * \file etudiants.h
 * \author Ange GRIMAUD
 * \date 15/10/2024
 * \brief Fonctions permettant de gérer les étudiants
 */


#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#define TAILLE_MAX 100

/**
 * \author Ange GRIMAUD
 * \brief fonction de chargement des données d'un fichier d'étudiants dans les tableaux correspondants
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tabNote tableau de flotants contenant les notes des élèves
 * \return la taille logique des tableaux
 */
int chargementEtudiants(int tabNB[], int tabRef[], float tabNote[]);

/**
 * \author Ange GRIMAUD
 * \brief fonction de sauvegarde des tableaux dans un fichier
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tabNote tableau de flotants contenant les notes des élèves
 * \param tailleLog taille logique des tableaux
 * \return la taille logique des tableaux
 */
void sauvegardeFichier(int tabNB[], int tabRef[], float tabNote[], int tailleLog);

/**
 * \author Ange GRIMAUD
 * \brief fonction de recherche d'un étudiant par son numéro
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tlog taille logique des tableaux
 * \param etu numéro de l'étudiant à rechercher
 * \return l'indice où se trouve le numéro de l'étudiant si on l'a trouvé, -1 sinon
 */
int rechercheEtu(int tabNB[], int tlog, int etu);

/**
 * \author Ange GRIMAUD
 * \brief fonction de recherche d'un étudiant par une référence de stage
 * \param ref référence de stage que l'on recherche
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tlog taille logique des tableaux
 * \return l'indice où se trouve la référence de stage si on l'a trouvé, -1 sinon
 */
int rechercheEtuParStage(int ref, int tabRef[], int tlog);

/**
 * \author Ange GRIMAUD
 * \brief fonction d'affichage des étudiants qui n'ont pas de stages
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tlog taille logique des tableaux
 */
void pasDeStage(int tabNB[], int tabRef[], int tlog);

/**
 * \author Ange GRIMAUD
 * \brief fonction qui affecte un stage à un étudiant donné
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tlog taille logique des tableaux
 * \param etu numéro de l'étudiant à rechercher
 * \param ref référence de stage que l'on recherche
 */
void affectation(int tabNB[], int tabRef[], int tlog, int etu, int ref);

/**
 * \author Ange GRIMAUD
 * \brief fonction qui prends 3 notes pour faire une moyenne et la rentrer dans le tableau
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabNote tableau de flotants contenant les notes des élèves
 * \param etu numéro de l'étudiant à rechercher
 * \param note1 première note de l'élève
 * \param note2 deuxième note de l'élève
 * \param note3 troisième note de l'élève
 * \param tlog taille logique des tableaux
 */
void moyenne(int tabNB[], float tabNote[], int etu, float note1, float note2, float note3, int tlog);

/**
 * \author Ange GRIMAUD
 * \brief fonction qui affiche les élèves ayant un stage mais n'ayant pas de note
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tabNote tableau de flotants contenant les notes des élèves
 * \param tlog taille logique des tableaux
 */
void afficherEtudiants(int tabNB[], int tabRef[], float tabNote[], int tlog);

/**
 * \author Ange GRIMAUD
 * \brief fonction qui affiche le stage qui est affecté à un élève donné
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param tlog taille logique des tableaux
 * \param numEtu numéro de l'étudiant à rechercher
*/
void rechercheStagesAccepté(int tabNB[], int tabRef[], int tlog, int numEtu);

/**
 * \author Ange GRIMAUD
 * \brief fonction qui renvoie si létudiant a un stage ou pas
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabRef tableau d'entiers contenant les références des stages des élèves
 * \param numEtu numéro de l'étudiant à rechercher
 * \param tlog taille logique des tableaux
 * \return renvoie 1 si l'étudiant a un stage, 0 sinon, si l'étudiant n'est pas là on renvoie -1
 */
int aUnStage(int tabNB[], int tabRef[], int numEtu, int tlog);

/**
 * \author Ange GRIMAUD / Gabriel COUDEL-KOUMBA
 * \brief fonction qui affiche les notes dans l'ordre décroissant
 * \param tabNB tableau d'entiers contenant les numéros étudiants
 * \param tabNote tableau de flotants contenant les notes des élèves
 * \param tlog taille logique des tableaux
 */
void afficheNotes(int tabNB[], float tabNote[], int tlog);

#endif