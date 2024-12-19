# TicTimac ❌⭕⭕⭕

> Par Guillaume Boucher ☕︎☕︎☕︎

Bienvenue sur mon projet de Morpion absolument incroyable.

Ce projet est décomposé en plusieurs fichiers avec `menu.cpp` servant de point d'entrée de notre programme. 

Le programme est composé des différents fichiers. 

- 💾 [Menu.cpp](/src/menu.cpp)
- 💾 [Game.cpp](/src/game.cpp)
- 💾 [Player.cpp](/src/player.cpp)
- 💾 [Verification.cpp](/src/verification.cpp) 
- 💾 [AI.cpp](/src/ai.cpp)

# Menu ⭕

Dans le fichier menu permet de choisir le mode de jeu du morpion entre 2 joueurs et IA. Si l'utilisateur entre une autre option alors nous lui redemandons le mode de jeu.

Ce fichier comporte également des données d'initialisation du morpion ainsi qu'un magnifique drapeau français.

# Player ❌

Dans notre fichier `player.cpp` nous demandons à l'utilisateur son nom ainsi que son symbole associé pour pouvoir l'afficher dans notre vector `board`. Si l'utilisateur autant forcené soit-il entre un `string` en tant que symbole, nous utilisons uniquement la première lettre comme symbole. J'ai également ajouté un int wins dans la struct pour pouvoir afficher un head2head lorsque la partie est terminée et possède un vainqueur !

# Vérification ⭕

Dans notre fichier vérification et le namespace `Verif::` nous examinons quelle position est gagnante ou nulle. Le code vérifie les cases de notre vector `board` et retourne un vainqueur si 3 cases sont alignées entre lignes, colonnes et diagonales. La version modifiée ici est censée gérer les cas des 3 cases alignés dans des plateau plus grand, cependant, il semble que dans certains cas, la vérification ne fonctionne pas. Nous définissons des boucles pour les colonnes et les lignes, si les colocataires de lignes sont de même symbole alors la partie est terminée et nous définissons le vainqueur en fonction du symbole récupéré. De même pour les colonnes, en ce qui concerne les diagonales, nous définissons si une case possède un symbole et que son colocataire de diagonale est du même symbole, pour cela, nous calculons le symbole + 1 en ajoutant la taille du plateau ± 1 à l'index du premier symbole.

L'indice `j` correspond à colonne et `i` à la ligne. `j` commence à 7 pour une grille de 3x3 et pour chaque itération diminue de la taille du tableau pour devenir 4 et enfin 1, `i` quant à lui s'incrémente de 1 en 1.

> [!NOTE]  
>  Cette fonction est appelée uniquement après 5 rounds de jeu, le nombre de rounds le plus bas avant une position gagnante.

# Game ❌

Ici, apparaissent les mécaniques de jeu intéressantes. Le plateau est défini ici par un vector, car j'ai décidé d'implémenter la possibilité de changer la taille du plateau pour pimenter un peu plus la partie ! Sinon précédemment pour un morpion classique, j'utilisais un array d'une taille définie de 10 cases. Pour guider le joueur à chaque round nous affichons une grille template de quel nombre à entrer pour cocher une case, suivant le pavé numérique pour base. Tant que le fichier `verification.cpp` et sa fonction `check_winner()` ne renvoie pas de vainqueur alors le jeu continue en comptant les tours. Le joueur commençant est défini de manière aléatoire.

> [!IMPORTANT]  
> Vous vous demandez peut-être pourquoi j'ai utilisé un array de 10 cases pour un plateau de 3x3 ?... Car le pavé numérique commence à 1 et pourquoi s'embêter à retirer 1 à chaque input quand on peut stocker une valeur supplémentaire inutile. 
> 
# AI ⭕

Mon intelligence artificielle, reprend d'abord l'algorithme `minimax` et ensuite applique un élagage `alpha-beta`. Le code reprend la logique de cet algorithme connu sur wikipédia. Le premier round, si l'intelligence joue, doit être un coin de la case de tableau noté dans un array, "source" wikipédia. Ainsi évitant d'utiliser un algorithme complexe pour le premier coup. Bien que fonctionnel, l'Intelligence Artificielle ne perdant jamais sur une grille de 3x3, celle-ci a tendance à avoir pitié de l'adversaire. L'IA même si elle a la possibilité de gagner en un coup, vous laisserai essayer d'arracher la nulle. Cela peut-être appelé bug, je me contenterai de la mention de "feature".

Trait à l'IA

```
|X|.|.|
|.|l|.|
|X|.|l|
```

Ici, l'intelligence artificielle va cocher la case 8 car elle adore jouer et préfère prolonger le fun.

# Problèmes rencontrés ❌

En ce qui concerne les problèmes rencontrés, j'en ai eu quelqu'uns, principalement sur les améliorations que j'ai mises en place. Premièrement, j'ai voulu améliorer mon intelligence artificielle qui premièrement cochait des cases non-vides aléatoires. Je me suis alors penché sur la logique intrinsèque et j'ai passé un certain temps avant de comprendre le concept et ensuite transcrire le pseudo-code de wikipédia dans mon projet. 

En deuxième point, j'ai eu du mal à mettre en place le fait d'augmenter la taille du plateau, les joueurs pouvaient placer leurs symboles correctement cependant la vérification de victoire ne marchait en aucun point, j'ai donc passé un certain temps là-dessus avant d'éventuellement abandonner. J'ai amélioré la vérification, mais celle-ci après certaines améliorations dans le but de fonctionner dans un cas global est devenu plus illisible (du fait d'un manque de commentaire) et il était alors compliqué de trouver les problèmes sous-jacents. 

`int grid_size {3};`

Vous pouvez modifier la valeur de `grid_size` dans le `menu.cpp` pour pouvoir jouer sur un morpion plus grand, l'IA ne marche plus si l'on change de taille car la vérification de victoire à tendance à ne pas fonctionner dans ce cas précis. Le problème ici est que la vérification ne prend pas en compte les cases cochées en dehors du plateau d'origine 3x3, j'ai voulu régler ce problème mais à chaque fois que je résolvais le problème pour que cela fonctionne dans un plateau 5x5 le plateau d'origine ne fonctionnait plus. Il faudrait réecrire complétement le fichier `verification.cpp` pour une écrire plus intuitive et une compatibilité décuplée.

---