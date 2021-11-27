OPTIMISATION POSSIBLE: si on avait le temps:

lexer : ne pas dup tout et juste garder le pointeur de début et la longueur.
peut poser des probleme donc a adapter sur le parser.

TEST : 

export TEST="s -l"
l$TEST"a"
> $TEST

> t$USER

> $INEXIST$INEXIST

> t$INEXIST$USER

> t$INEXIST$USER" pouet "

 l"s"" ""-""l""a"
bash: ls -la : commande introuvable

l"s" "-""l"a

ls$INEXIST -l

l$INEXIST's' -l

ls"" -l

""'l'"s" ""

mini@debian:~$ export TEST=-d''""test
mini@debian:~$ echo $TEST 
-dtest

 "$USER $ $SDFSDFSDFDFSDF $$"


 HEREDOC

> creat << test  < inexist > dontcreat << test

 << '' cat
 << "" cat
 << 't'e"est" cat
 << " " cat
  << "t"'e'st'' cat
    $USER

ERROR : 
/ ou n'importe quel repertoire.

minishell: /: Is a directory
lvirgini@minishell:/mnt/nfs/homes/lvirgini/42/minishell$ echo $?
126

