nume = [10, 20, 30, 40, 50]
soma = 0
i = 0

for num in nume:
    soma = nume[i] + soma
    
    i=i+1

media = soma/ len(nume)
print("", media)

gastos_joao = [300, 500, 200, 800]
gastos_pedro = [200, 400, 500, 700]

gastos_joao = sum(gastos_joao)
gastos_pedro = sum(gastos_pedro)

print("",gastos_joao)
print("",gastos_pedro)

if gastos_pedro > gastos_joao:
    print("Pedro gastostou mais")

elif gastos_joao > gastos_pedro:
    print("João gastostou mais")

else:
    print("Os dois gastaram iguais")


palavras = ["python", "asimov", "código", "web", "programação"]

maior = []
menor