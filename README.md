# [TP3 Théorie des graphes - ECE Paris - Algorithme de Dijkstra](enonce/TD_TP_3.pdf)

## Objectif
Ce code a pour but de parcourir un multi-graphe et d'obtenir les chemins les plus cours entre chaque sommet et le sommet de départ.
Pour réaliser ceci nous devions utiliser l'algorithme de Dijkstra.

## Graphes
Nous avons créé deux graphes :
- [graphe normal](graph.txt) qui contient le graph de base pouvant être retrouvé dans le [sujet](enonce/TD_TP_3.pdf)
- [graphe infini](graph.txt) qui est le même graphe que celui précédent mais avec un sommet non ateignable

Le [graphe infini](graph.txt) permet d'observer le comportement de l'algorithm lorsqu'il rencontre un sommet inateignable.

## Rapport

Le contre-rendu du Tp est trouvable [ici](rapport/TP3_Theorie_des_graphes.docx)

## Utilisation

### Visual Studio Code

Le projet à été créé pour être compilable sur Visual Studio Code. Le dossier [`.vscode`](.vscode) contient le fichier [`tasks.json`](.vscode/tasks.json). Ce fichier contient des tâches pour compiler et lancer le programme. Ce fichier peut nécessiter d'être modifier pour mettre le bon chemin pour le compilateur g++.
Le projet contient également le fichier [`launch.json`](.vscode/launch.json) pour lancer le projet en mode debug.

### Autre

Le projet peut être également utilisé avec d'autre editeur de texte. Il suffit de réutiliser le [`makefile`](makefile) pour compiler le projet. Si vous utilisez `MINGW` comme compilateur il suffit d'éxécuter la commande `mingw32-make` pour compiler le projet. Attention a bien être dans le dossier contenant le makefile lorsque vous éxécutez la commande.

## Algorithmes

- ***Algorithme de Dijkstra*** : En théorie des graphes, l'algorithme de Dijkstra sert à résoudre le problème du plus court chemin.
```
Dijkstra(G,Poids,sdeb) :
  Initialisation(G,sdeb)
  Q := ensemble de tous les nœuds
  tant que Q n'est pas un ensemble vide faire
    s1 := Trouve_min(Q)
    Q := Q privé de s1
    pour chaque nœud s2 voisin de s1 faire
      maj_distances(s1,s2)
    fin pour
  fin tant que
fin
```
## Sources

- Cours de Mme Palasi
- [Wikipedia - Algorithme de Dijkstra](https://fr.wikipedia.org/wiki/Algorithme_de_Dijkstra)
