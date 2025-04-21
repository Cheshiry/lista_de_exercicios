print("\033[1;33;46m-=" * 50)

print("\033[1;97;46m Descobrir se pode financiar sua casa\n")

print("-=" * 20)
print("\033[1;36;46mAnalisador de financiamento \033[m")
print("-=" * 20)

anos = int(input("Digite em quanto anos quer pagar a casa: "))
salario = float(input("Digite seu salário: "))
valor_casa = float(input("Digite o valor da casa: "))

valor_mensal = valor_casa / (anos * 12)
salario_30p = (salario * 30) / 100

if valor_mensal <= salario_30p:
    print(f"Consórcio aprovado valor mensal a ser pago R${valor_mensal:.2f} por {anos} anos")
else:
    print("Consórcio negado ")
