num = (int(input("Digite um numero: ")),
int(input("Digite outro numero: ")),
int(input("Digite mais um numero: ")),
int(input("Digite o ultimo numero: ")),
)
print("-="*50)

print(num)
#o valor 9 apaeceu?
nove = num.count(9)

if nove == 0:
    print("Não tem nove.")
else:
    print(f"O nove apareceu {nove}x")
#o valor 3 apareceu na posição
try:
    localizar_num = num.index(3)
    print(f"O número 3 apareceu na {localizar_num+1} posição")

except ValueError:
    print("O numero 3 não apareceu.")
#valor par
print("Os valores pares digitados: ( ",end="")
for p in num:
    if p % 2 == 0: 
        print(p, end=" ")
print(")\n")
print("-="*50)