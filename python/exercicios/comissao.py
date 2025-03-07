corretor = 0
i = 0

for corretor in range(3):
    if corretor < 3:

        nome = input("Digite o nome do corretor: ")
        valor_vendido = float(input("Digite o valor de vendas do mês: "))

        if valor_vendido >= 50000:
            valor_vendido_e_comissao = (valor_vendido +  (valor_vendido * 0.12))

        elif valor_vendido <= 49999 and valor_vendido >= 30000:
            valor_vendido_e_comissao = ((valor_vendido * 0.095) + valor_vendido)

        elif valor_vendido < 30000:
            valor_vendido_e_comissao = ((valor_vendido * 0.07) + valor_vendido)

    print(f"O contador {nome}, ganhou R${valor_vendido_e_comissao} esse mês.\n")

    corretor =+ 1


#########################################################

""" 
corretor = 0
i = 0

while i <= corretor:

    nome = input("Digite o nome do corretor: ")
    valor_vendido = float(input("Digite o valor de vendas do mês: "))

    if valor_vendido >= 50000:
        valor_vendido_e_comissao = (valor_vendido +  (valor_vendido * 0.12))
    
    elif valor_vendido <= 49999 or valor_vendido >= 30000:
        valor_vendido_e_comissao = ((valor_vendido * 0.095) + valor_vendido)

    else:
        valor_vendido_e_comissao = ((valor_vendido * 0.07) + valor_vendido)

    print(f"O contador {nome}, ganhou R${valor_vendido_e_comissao} esse mês.\n")

    i =+ 1
 """