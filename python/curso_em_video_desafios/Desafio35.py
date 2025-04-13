print("-=" * 20)
print("\033[1;36;46mAnalisador de triângulo\033[m")
print("-=" * 20)

r1 = int(input("Digite um segmento d3 reta: "))
r2 = int(input("Digite outro segmento de reta: "))
r3 = int(input("Digite mais um segmento  de reta: "))

if r1 < r2 + r3 and r2 < r1 +r3 and r3 < r1 + r2:
    print("É um triângulo")

else:
    print("Não é um triângulo")
