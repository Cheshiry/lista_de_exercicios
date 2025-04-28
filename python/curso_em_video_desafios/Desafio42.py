print("-=" * 20)
print("\033[1;36;46mAnalisador de triângulo\033[m")
print("\033[-=" * 20)

r1 = int(input("Digite um segmento de reta: "))
r2 = int(input("Digite outro segmento de reta: "))
r3 = int(input("Digite mais um segmento  de reta: "))

if r1 < r2 + r3 and r2 < r1 +r3 and r3 < r1 + r2:
    print("É um triângulo")

    if r1 == r2 == r3:
        print(f"Equilátero com lados {r1}, {r2} e {r3}")

    elif r1 == r3 or r2 == r3 or r1 == r2:
        print(f"Isósceles com lados {r1}, {r2} e {r3}")
    
    else:
        print(f"Escaleno com lados {r1}, {r2} e {r3}")

else:
    print("Não é um triângulo")
'''
RESOLUÇÃO

#ESCALENO
r1 != r2 != r3 != r1

#ISOSCELES vai em else
'''