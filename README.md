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

# Player ❌

Dans notre fichier `player.cpp` nous demandons à l'utilisateur son nom ainsi que son symbole associé pour pouvoir l'afficher dans notre vector `board`. Si l'utilisateur autant forcené soit-il entre un `string` en tant que symbole nous utilisons uniquement la première lettre comme symbole. J'ai également ajouté un int wins dans la struct pour pouvoir afficher un head2head lorsque la partie est terminée et possède un vainceur !

# Vérification ⭕

Dans notre fichier vérification et le namespace `Verif::` nous examinons quelle position est gagnante ou nulle. Le code vérifie les cases de notre vector `board` et retourne un vainceur si 3 cases sont alignés entre lignes, colonnes et diagonales. La version modifiée ici est censé gérer les cas des 3 cases alignés dans des plateau plus grand, cependant il semble que dans certains cas, la vérification ne fonctionne pas. Nous définissons des boucles pour les colonnes et les lignes, si les collocateurs de lignes sont de même symbole alors la partie est terminée et nous définissons le vainqueur en fonction du symbole récupéré. De même pour les colonnes, en ce qui concerne les diagonales nous définissons si une case possède un symbole et que son collocatère de diagonale est du même symbole, pour cela nous calculons le symbole + 1 en ajoutant la taille du plateau ± 1 à l'index du premier symbole.

> [!NOTE]  
>  Cette fonction est appelée uniquement après 5 rounds de jeu, le nombre de round le plus bas avant une position gagnante.

# Game ❌

Ici apparaît les mécaniques de jeu intéressantes. [TODO]
Le plateau est défini ici par un vector car j'ai décidé d'implémenter la possibilité de changer la taille du plateau pour pimenter un peu plus lapartie ! Sinon précédemment pour un morpion classique j'utilisais un array d'une taille définie de 10 cases.

> [!IMPORTANT]  
> Vous vous demandez peut-être pourquoi j'ai utilisé un array de 10 cases pour un plateau de 3x3 ?... Parce que pourquoi pas ?
# AI ⭕

Mon intelligence artificielle, reprend d'abord l'algorithme `minimax` et ensuite applique un élagage `alpha-beta`. Le code reprend la logique de cet algorithme connu sur wikipédia. Le premier round si l'intelligence joue doit être un coin de la case de tableau noté dans un array, "source" wikipédia. Ainsi évitant d'utilisant un algorithme complexe pour le premier coup.

# Problème rencontré ❌

En ce qui concerne les problèmes rencontrés, j'en ai eu quelqu'uns principalement sur les améliorations que j'ai mises en place...