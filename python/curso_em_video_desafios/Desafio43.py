from math import pow as quadrado


print("\033[1;36;46m*" * 100)
print("Calcule seu IMC: ")

#nome = str(input("Digite seu nome: ")).capitalize().
altura = float(input("Digite sua altura em centimetros: "))
altura = altura / 100
peso = float(input("Digite seu peso: "))
situacao = ""

imc = peso / (altura ** 2)

if imc < 18.5:
    situacao = "abaixo do peso"

elif 18.5 <= imc < 25:
    situacao = "peso ideal"

elif 25 <= imc < 30:
    situacao = "sobrepeso"
    
elif 30 <= imc < 40:
    situacao = "obesidade"

else:
    situacao = "obesidade morbida"

print(f"O paciente tem peso {peso:.2f} e altura {altura:.2f} seu imc é {round(imc, 2)} e sua situação é {situacao}")

print("*" * 100)