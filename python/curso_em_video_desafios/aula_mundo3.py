lista = []
num = [8,6,67,9]
#num = num.sort()
lista.append("Ana")

lista.append("Bruno")
lista.append("Helis")
print(lista)
print(num)
print(*num,sep=",")#

if 88 in num:
    num.remove(88)
else:
    print("não tem")
print(len(num))


valores = [5, 9, 4]

for v in valores:
    print(f"{v}...")

for c,v in enumerate(valores):
    print(f"posião {c}\nValor{v}")