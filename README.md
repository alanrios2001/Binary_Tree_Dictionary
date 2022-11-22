# Binary_Tree
A code that by the following commands you can store a input word, with its morphological classification and translates, into a binary tree structure.

Use the following commands:

INSERT NEW OBJECT:
Press "i" and enter, on next line type the word you want to store and hit enter, on next line, type the morphological classification ("s" = substantive or "a" = adjective or "v" = verb), hit enter, on next line, type the number of translates, press enter, now, just type the translate and hit enter how many times you put the number of translates. (If the word you want to store, a "palavra ja existente: " message followed by the word will be displayed, otherwise, a "palavra inserida no dicionario: " message followed by the word will be returned).

LIST WORDS:
Type "l", hit enter, type ("c" = growing or "d" = descending).

LIST TRANSLATES:
Type "t" hit enter, on next line, type the word you wanna see the translates stored, if the word was not stored yet, you are goingo to see a "palavra inexistente no dicionario: " message followed by the searched word. Otherwise, you are going to see a "traducoes da palavra: " message, followed by the searched word, and on next lines, the translates gonna be displayed, if it exist.

LIST WORDS PER MORPHOLOGICAL CLASS:
Type "a", hit enter, then type ("s" = substantive or "a" = adjective or "v" = verb), hit enter, and press ("c" = growing or "d" = descending), hit enter, you will see the words by morphological class typed.

SEARCH WORD MORPHOLOGICAL CLASS:
Type "c", hit enter, type the word you wanna check the morphological class. If the word doesnt exists a "palavra inexistente no dicionario: " message followed by the word will be displayed, otherwise, a "classe da palavra: " followed by the word and ":", followed by the morphological class message will be displayed.

REMOVE WORD:
Type "r", hit enter, type the word you would like to remove from binary tree structure. If the word doesnt exists on structure, a "palavra inexistente no dicionario: " message followed by the word typed will be displayed, otherwise, you will get a "palavra removida: " message followed by the removed word.

PRINT TREE:
Just press "p" and hit enter, you will see all the nodes on the following print structure:

"chave: exemple fesq: exemple_left fdir: exemple_right"

"chave: exemple_left fesq: nil fdir: nil"
 
"chave: exemple_right fesq: nil fdir: nil"

Whose "chave" means the key of the node, fesq means the left branch from the key, and fdir means the right branch from the key.

END COMANDS:
Just press "e" and hit enter, the program gonna be stopped.
