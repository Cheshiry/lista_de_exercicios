"""29 desafio 
Leia a velocidade de um carro e se ultrapassar 80kh/h foi multado 

A multa custa 7, por km acima do limite """

velocidade = float(input("Digite a velocidade do carro: "))

if velocidade > 80:
    multa = (velocidade - 80) * 7
    print(f"Sua multa é {multa}")
else:
    print("Você está dentro do limite")
