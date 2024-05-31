# Okkkk j'avoue j'ai fait une erreur, j'ai oublié que dans la vraie vie on commence de compte à partir de 0 mais trql

notes = ["a", "b", "c", "d", "e", "f", "g"]

morceau = input()
nouveau_morceau = ""

while len(morceau) != len(nouveau_morceau):
    nouveau_morceau = morceau

    for n in notes:
        morceau = morceau.replace(n*2, "")

print(morceau)