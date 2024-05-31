# Oui en python car je suis en vacances et que je veux faire ça le plus vite possible

def input_int(prompt = "", split = " "):
    return [int(e) for e in input(prompt).split(split)]

nb_livres, nb_jours = input_int()


# {idx: time_remaining}
books_unavaible = {}

for i in range(nb_jours):
    nb_clients = int(input())

    for book_idx in list(books_unavaible.keys()):
        books_unavaible[book_idx] -= 1
        if books_unavaible[book_idx] == 0:
            books_unavaible.pop(book_idx)

    for c in range(nb_clients):
        book_idx, time = input_int()
        if book_idx in books_unavaible:
            print("0")
        else:
            books_unavaible[book_idx] = time
            print("1")