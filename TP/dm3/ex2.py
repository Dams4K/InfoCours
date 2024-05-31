# Ex1 ez à faire, on passe au deux
from string import ascii_lowercase

nb_letters = int(input())

def print_letters(nb, raw):
    size = (1 + 2 * (nb-1))
    letter = ascii_lowercase[nb_letters-nb]
    if raw in [1, size]:
        print(letter * size, end="")
    else:
        print(letter, end="")
        print_letters(nb-1, raw-1)
        print(letter, end="")


total_raws = (1 + 2 * (nb_letters-1))
for raw in range(total_raws):
    print_letters(nb_letters, raw+1)
    print("")