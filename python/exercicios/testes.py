MAIOR_IDADE = 18
TERCEIRA_IDADE = 65
age = int(input("Informe a sua idade:\n"))

if age >= MAIOR_IDADE and age < TERCEIRA_IDADE:
    print("Maior de idade, já pode dirigir!")

elif age >= TERCEIRA_IDADE:
    print ("Pode dirigir apenas com autorização dp médico.")

else:
    print("Menor de idade, não pode dirigir!")

saldo = 2000
saque = 500

status = "Sucesso" if saldo >= saque else "False"

print(f"{status}! Ao realizar saque!")