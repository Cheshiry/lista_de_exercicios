""" frase = str(input("Digite uma frase: "))
palavras = frase.split()
junto = "".join(palavras)
inverso = frase[::-1]
inverso = inverso.split()

print(f"A frase: {frase} e o inverso {inverso}")
if frase == inverso:
    print("É um  POLINDROMO!")
else:
    print("NÃO É UM POLINDROMO!") """

frase = str(input("Digite uma frase: "))
palavras = frase.split()
junto = "".join(palavras)
inverso = ""

for letra in range(len(junto) -1, -1, -1):
    inverso += junto[letra]
    
print(f"A frase: {junto} e o inverso {inverso}")

if inverso == junto:
    print("É um  PALÍNDROMO!")
else:
    print("NÃO É UM PALÍNDROMO!")
