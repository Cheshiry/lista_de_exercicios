print("Sequência de Fibonacci")
print("-"*50)

contador = int(input("Digite um número: "))

contador = 1
i = 0
lista = [0,1]

while contador >= i :

    lista.append(lista[0] + lista[1] )

    print(lista, end = " → " )
    
    i += 1

print("Fim")

print("=+"*20)
