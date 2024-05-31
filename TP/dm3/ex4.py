# C'est bien pour l'ex3 que je suis content d'avoir utilisé python ahahah

nb_mesures = int(input())
diff_max = float(input())

mesures = []

for _ in range(nb_mesures):
    mesures.append(float(input()))

def lissage(m: list, dm) -> tuple:
    n_m = [m[0]]
    is_inf = True

    for i in range(1, len(m)-1):
        n_m.append( ( m[i-1] + m[i+1] )/2 )

        is_inf = is_inf and (abs(n_m[i-1] - n_m[i]) < dm)

    n_m.append(m[len(m)-1])

    is_inf = is_inf and (abs(n_m[len(m)-2] - n_m[len(m)-1]) < dm)

    return n_m, is_inf

n = 0
is_inf = True

for i in range(1, len(mesures)):
    is_inf = is_inf and (abs(mesures[i-1]-mesures[i]) < diff_max)

while not is_inf:
    n += 1
    mesures, is_inf = lissage(mesures, diff_max)

print(n)