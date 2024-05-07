# WordBendMastermind

## Description
WordBendMastermind is a C program that plays a word-guessing game against a human opponent. Unlike traditional word-guessing games, where one player chooses a secret word and the other player guesses letters to uncover it, WordBendMastermind bends the rules by allowing the player to choose from a set of words, revealing letters strategically to keep the opponent guessing.

## How to Use
1. Compile the program using a C compiler. For example:
gcc -o WordBendMastermind WordBendMastermind.c

2. Run the compiled program with the following command-line arguments:
./WordBendMastermind dictionary.txt <word_length> <number_of_guesses>

- `dictionary.txt`: The file containing the list of words to be used in the game. Each word should be on a separate line.
- `<word_length>`: The length of the words to be used in the game.
- `<number_of_guesses>`: The maximum number of guesses allowed for the player.

## Gameplay
1. The program will prompt the player to guess a letter.
2. The player must enter a single letter that they have not guessed before. The program will re-prompt until a valid letter is entered.
3. Based on the guessed letter, the program will partition the words in the dictionary into categories.
4. The program will choose a word category and remove words that do not belong to that category. If the category does not contain any instances of the guessed letter, the player loses a guess.
5. The game continues until the player runs out of guesses or correctly guesses the word.

## Sample Run
./WordBendMastermind dictionary.txt 6 10
______ Enter letter: a
Guess 1/10, Words Left 3595, Letters used = a
______ Enter letter: 4
4 is not a letter
______ Enter letter: e
Guess 2/10, Words Left 1154, Letters used = ae
___e Enter letter: e
e already used
___e Enter letter: i
Guess 3/10, Words Left 643, Letters used = aei
___e Enter letter: o
Guess 4/10, Words Left 259, Letters used = aeio
o__e Enter letter: u
Guess 5/10, Words Left 209, Letters used = aeiou
o__e Enter letter: b
Guess 6/10, Words Left 175, Letters used = aeioub
o__e Enter letter: g
Guess 7/10, Words Left 151, Letters used = aeioubg
o__e Enter letter: d
Guess 8/10, Words Left 79, Letters used = aeioubgd
o__e Enter letter: r
Guess 9/10, Words Left 32, Letters used = aeioubgdr
_o__er Enter letter: t
Guess 10/10, Words Left 18, Letters used = aeioubgdrt
Word was confer
