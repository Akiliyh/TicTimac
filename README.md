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

# Menu

Dans le fichier menu permet de choisir le mode de jeu du morpion entre 2 joueurs et IA. Si l'utilisateur entre une autre option alors nous lui redemandons le mode de jeu.

# Player

Dans notre fichier `player.cpp` nous demandons à l'utilisateur son nom ainsi que son symbole associé pour pouvoir l'afficher dans notre vector `board`. Si l'utilisateur autant forcené soit-il entre un `string` en tant que symbole nous utilisons uniquement la première lettre comme symbole.

# Vérification

Dans notre fichier vérification et le namespace `Verif::` nous examinons quelle position est gagnante ou nulle. Le code vérifie les cases de notre vector `board` et retourne un vainceur si 3 cases sont alignés entre lignes, colonnes et diagonales.

> [!NOTE]  
>  Cette fonction est appelée uniquement après 5 rounds de jeu, le nombre de round le plus bas avant une position gagnante.

# Game

Ici apparaît les mécaniques de jeu intéressantes. [TODO]

# AI

Mon intelligence artificielle, reprend d'abord l'algorithme `minimax` et ensuite applique un élagage `alpha-beta`. Le code reprend la logique de cet algorithme connu sur wikipédia. Le premier round si l'intelligence joue doit être un coin de la case de tableau noté dans un array, "source" wikipédia. Ainsi évitant d'utilisant un algorithme complexe pour le premier coup.
