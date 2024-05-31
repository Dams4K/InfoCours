def input_int(prompt = "", split = " "):
    return [int(e) for e in input(prompt).split(split)]

nb_grenouilles = int(input())
nb_tours = int(input())

distances = [0] * nb_grenouilles
b = [0] * nb_grenouilles

for tour in range(nb_tours):
    if tour > 0:
        distance_max = max(distances)
        if distances.count(distance_max) == 1: # si il y a deux grenouilles en tête, bah en fait aucune des deux n'est en tête
            grenouille = distances.index(distance_max)
            b[grenouille] += 1


    nb_grenouille, distance_saut = input_int()
    distances[nb_grenouille-1] += distance_saut
    

print(b.index(max(b))+1)