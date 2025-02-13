/**
 * \file candidatures.h
 * \author Gabriel COUDEL-KOUMBA
 * \date 15/10/2024
 * \brief Fonctions permettant de gérer les candidatures
 */


#ifndef CANDIDATURES_H
#define CANDIDATURES_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "etudiants.h"

#define TAILLE_MAX 100

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction de chargement des données d'un fichier d'offres de stages dans les tableaux correspondants, chaque indice etant attribuer à un stage
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tmax taille physique des tableaux
 * \return la taille logique des tableaux
 */
int chargementStages(int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tmax);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction de sauvegarde des données dans fichier d'offres de stages à partir des tableaux correspondants
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tlog taille logique des tableaux
 */
void sauvegardeStages(int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction de recherche d'un stage par sa référence
 * \param tabR tableau d'entier contenant les références des stages
 * \param ref référence du stage recherché
 * \param tlog taille logique des tableaux
 * \return l'indice du stage recherché ou -1 s'il n'est pas trouvé
 */
int rechercheStage(int tabR[], int ref, int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction d'affichage des stages ayant été attribués
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabRefEtu tableau d'entier contenant les références des stages auxquels un étudiant est affecté
 * \param tabEtu tableau d'entier contenant les numéros d'étudiants
 * \param tlog taille logique des tableaux
 * \param tlogE taille logique des tableaux étudiants
 */
void afficherStagePourvu(int tabR[], int tabD[], int tabPourvu[], int tabRefEtu[], int tabEtu[], int tlog, int tlogE);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction d'affichage des stages n'ayant pas été attribués
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tlog taille logique des tableaux
 */
void afficherStageNonPourvu(int tabR[], int tabD[], int tabPourvu[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction d'affichage des informations d'un stage 
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 */
void afficherInfoStage(int index, int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[]);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction d'affichage des stages en fonction d'un département spécifique
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabD tableau d'entier contenant les départements des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tlog taille logique des tableaux
 */
void afficherStagesDept(int dept, int tabR[], int tabD[], int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction d'affichage de la liste des références de stage disponible
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tlog taille logique des tableaux
 */
void afficherReferences(int tabR[], int tabPourvu[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction calculant le nombre de candidatures faites par un étudiant
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param numEtu numéro de l'étudiant recherché
 * \param tlog taille logique des tableaux
 * \return le nombre de candidatures faites
 */
int nombreDeCandidatures(int tabCand1[], int tabCand2[], int tabCand3[], int numEtu, int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction permettant de connaitre le nombre de candidats candidatant à un stage spécifique
 * \param index la position dans les tableaux du stage choisi
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \return le nombre de candidats à un stage
 */
int nombreDeCandidats(int index, int tabNumC[]);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction affichant les références de stages auxquelles un candidat a postuler
 * \param numEtu numéro de l'étudiant recherché
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tabRef tableau d'entier contenant les références des stages
 * \param tlog la taille logique du tableau
 * \return renvoie 1 si l'étudiant a au moins un stage, 0 sinon
 */
int rechercheStageParEtu(int numEtu, int tabCand1[], int tabCand2[], int tabCand3[], int tabRef[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction ajoutant un candidat à la liste des candidatures d'un stage
 * \param numCand le numéro de l'étudiant
 * \param index la position du stage auquel l'étudiant veut candidater
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand le tableau d'entier dans lequel l'étudiant doit être ajouté
 */
void candidature(int numCand, int index, int tabNumC[], int tabCand[]);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction retirant la candidature d'un étudiant
 * \param numCand le numéro de l'étudiant
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tlog la taille logique du tableau
 */
void suppressionCandidatures(int numCand, int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction passant un stage de non pourvu (0) à pourvu (1) et supprimant les autres candidatures de l'étudiant choisit
 * \param numCand le numéro de l'étudiant
 * \param index la position du stage pourvu
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tabCand1 tableau d'entier contenant le numéro du 1er étudiant ayant candidaterau stage
 * \param tabCand2 tableau d'entier contenant le numéro du 2e étudiant ayant candidaterau stage
 * \param tabCand3 tableau d'entier contenant le numéro du 3e étudiant ayant candidaterau stage
 * \param tlog taille logique des tableaux
*/
void stagePourvu(int numCand, int index, int tabPourvu[], int tabNumC[], int tabCand1[], int tabCand2[], int tabCand3[], int tlog);

/**
 * \author Ange GRIMAUD
 * \brief affiche tous les stages pour lesquels l'élève peut candidater
 * \param tabR tableau d'entier contenant les références des stages
 * \param tabPourvu tableau d'entier permettant de savoir si le stage a été pourvu (1) ou non (0)
 * \param tabNumC tableau d'entier contenant le nombre d'étudiants ayant candidater à chacun des stages
 * \param tlog taille logique des tableaux
 */
void afficherReferencesDisponibles(int tabR[], int tabPourvu[], int tabNumC[], int tlog);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction de saisie des notes d'un stage
 * \param tabNote1 tableau de flottant contenant la 1ére note des étudiants
 * \param tabNote2 tableau de flottant contenant la 2e note des étudiants
 * \param tabNote3 tableau de flottant contenant la 3e note des étudiants
 * \param index la position de l'étudiant recherché
 * \return le nombre de notes saisies
 */
int saisirNotes(float tabNote1[], float tabNote2[], float tabNote3[], int index);

/**
 * \author Gabriel COUDEL-KOUMBA
 * \brief fonction d'affichage des notes en ordre décroissant
 * \param note1 note d’entreprise
 * \param note2 note du rapport
 * \param note3 note de soutenance
 */
void afficherNotesTriees(float note1, float note2, float note3);

#endif