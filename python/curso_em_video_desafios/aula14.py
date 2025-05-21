'''
while quando não sabe quantas vezes repetir.

enquanto nao (chegar na) maçã faça.
while not apple:

'''

c = 1

while c < 10:
    print(c)
    c += 1

n = 1
r = "S"

while r == "S":
    num = int(input("Digite um valor: "))
    r = str(input("Quer continuar? [S/N]")).upper()

print("Fim")

par = impar = 0

while n != 0:
    num = int(input("Digite um valor: "))
    if n != 0:
        if n% 2 == 0:
            par +=1
        else:
            impar +=1

print("Fim")