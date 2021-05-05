# minishell

L’objectif de ce projet est de créer un simple shell. Ca sera votre propre
petit bash, ou zsh. Vous en apprendrez beaucoup sur les process et les file descriptors.

- norme
- les bonus : _bonus.[c/h]

External functs. printf, malloc, free, write, open, read, close,
fork, wait, waitpid, wait3, wait4, signal, kill,
exit, getcwd, chdir, stat, lstat, fstat, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, errno, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs




Votre shell doit :
• Ne pas utiliser plus d’une variable globale et vous devrez justifier son utilisation.
• Afficher un prompt en l’attente d’une nouvelle commande
• Chercher et lancer le bon executable (basé sur une variable d’environnement PATH
ou en utilisant un path absolu), comme dans bash
• Vous devez implémenter les builtins suivants :
	◦ echo et l’option ’-n’
	◦ cd uniquement avec un chemin absolu ou relatif
	◦ pwd sans aucune option
	◦ export sans aucune option
	◦ unset sans aucune option
	◦ env sans aucune option ni argument
	◦ exit sans aucune option
• ; dans la ligne de commande doit séparer les commandes
• ’ et " doivent marcher comme dans bash, à l’exception du multiligne.
• Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des
aggrégations de fd
• Pipes | doivent marcher comme dans bash à l’exception du multiligne.
• Les variables d’environnement ($ suivi de caractères) doivent marcher comme dans
bash.
• $? doit marcher comme dans bash
• ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
• en utilisant termcap (man tgetent pour voir des exemples) Touches haut et bas
pour naviguer dans l’historique de commandes, que nous pouvons ensuite éditer
(inline, pas dans l’historique)


Partie Bonus
• Si la partie obligatoire n’est pas complète, vous n’avez pas accès aux bonus
• Vous n’avez pas a faire tous les bonus
• Redirection “<<” comme dans bash
• Historique et édition de ligne avance en utilisant termcaps (man tgetent pour voir
des exemples)
◦ Éditer la ligne ou le curseur est placé
◦ Déplacer le curseur vers la gauche ou la droite pour éditer la ligne à un endroit
spécifique. Évidemment, les caractères ajoutés doivent être rajoutés au milieu
de ceux existants, comme dans bash.
◦ Copier, couper et coller tout ou une partie d’une ligne à l’aide d’une séquence
de touches de votre choix
◦ Se déplacer de mot en mot à l’aide des touches CTRL+gauche et CTRL+droite
◦ Aller directement au début ou à la fin de la ligne en utilisant les touches home
et end
◦ Écrire ET éditer une commande sur plusieurs lignes. Dans cette situation, nous
adorerions que CTRL+haut et CTRL + bas permettent de se déplacer entre les
lignes tout en restant dans la même colonne, ou la plus appropriée.
• && et || avec les parenthèses pour les priorités, comme dans bash
• wildcard * comme dans bash