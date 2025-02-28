""" texto = input("Informe um texto: \n")

VOGAIS = "AEIOU"

for letra in texto:
    if letra.upper() in VOGAIS:
        print(letra, end="")
else:
    print("Fim") 

 """

""" def conta_vogais(texto):
  vogais = set("aeiouAEIOU")
  contador = 0
    # TODO: Defina um conjunto de vogais tanto minúsculas quanto maiúsculas:
    # TODO: Inicialize um contador para contar as vogais:
    # Iteramos pelos caracteres da string
    for char in texto:
        if char in vogais:
            # TODO: Verifique se o caractere atual é uma vogal e incremente o valor do contador:
            
    
return contador += 1

# Solicitamos ao usuário que insira uma string
texto = input()

# Chamamos a função conta_vogais e exibimos o resultado
resultado = conta_vogais(texto)
print(f"O número de vogais na string '{texto}' é: {resultado}") """


def conta_vogais(texto):
    vogais = set("aeiouAEIOU")
    contador = 0
    for char in texto:
        if char in vogais:
            return contador = contador + 1

# Solicitamos ao usuário que insira uma string
texto = input()

# Chamamos a função conta_vogais e exibimos o resultado
resultado = conta_vogais(texto)
print(f"O número de vogais na string '{texto}' é: {resultado}")