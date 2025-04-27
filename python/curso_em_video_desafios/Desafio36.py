print("\033[1;33;46m-=" * 50)

print("\033[1;97;46m Descobrir se pode financiar sua casa\n")

print("-=" * 20)
print("\033[1;36;46mAnalisador de financiamento \033[m")
print("-=" * 20)

anos = int(input("Digite em quanto anos quer pagar a casa: "))
salario = float(input("Digite seu salário: R$"))
valor_casa = float(input("Digite o valor da casa: R$"))

valor_mensal = valor_casa / (anos * 12)
minimo = (salario * 30) / 100

print(f" Para pagar uma casa de {valor_casa} o valor mensal a ser pago é R${valor_mensal:.2f} por {anos} anos")

if valor_mensal <= minimo:
    print(f"Consórcio aprovado")
else:
    print("Consórcio negado ")
