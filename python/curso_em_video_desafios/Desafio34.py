salario = float(input("Digite seu sálario: "))

if salario > 1250.00:
    novo_salario = (salario * 0.10) + salario
    print(f"{novo_salario:.2f}")
else:
    novo_salario = (salario * 0.15) + salario
    print(f"{novo_salario:.2f}")