# SAE 1.01 : Gestion des stages

> ### Membres de l'équipe
> 
> Coudel-Koumba Gabriel<br>
> Grimaud Ange
>
> Groupe 3

## Information 
- Objectif : Cette SAÉ permet une première mise en pratique du développement autour d'un besoin client.
- Production : Code de l'application - Traces d'exécution des jeux d'essais. 
- Date de rendu : Vendredi 15/11/2024 
## Documentation
> commandes à entrer dans le terminal
### Fichier .pdf
- [Rapport_SAE1.01.pdf](https://codefirst.iut.uca.fr/git/gabriel.coudel-koumba/sae_1.01/src/branch/master/doc/Rapport_SAE1.01.pdf)
- Depuis la racine du répertoire : ``` cd doc/ ```
### Générer la documentation doxygen
- Depuis la racine du répertoire : ``` doxygen ``` puis ouvrir dans un navigateur ```html/index.html```
## Comment exécuter ?

> commandes à entrer dans un terminal

### Compiler 
``` make ```
### Éxecuter le projet
- Depuis la racine du répertoire: ``` ./bin/exe ```<br>
- Depuis ``` bin ``` en partant de la racine du répertoire: ``` cd bin/ ``` puis ```./exe ``` 
#### En utilisant ``` install ```
``` make install ``` puis ``` ./exe ```
### Nettoyer le projet
- Supprmier ``` bin ``` et  ```obj ``` en utilisant make clean: ``` make clean ```
- Supprimer l'éxecutable ``` make unistall ``` (uniquement si utilisation de ``` install ```): ``` uninstall ```