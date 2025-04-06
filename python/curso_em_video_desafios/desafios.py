""" TODO: Crie uma função 'elementos_comuns' que receba duas listas de números inteiros separados por espaço:
def elementos_comuns(lista1, lista2):
  set1 = list(map(int, lista1))
  set2 = list(map(int, lista2))
  
  return list(set1.intersection(set2))

# Leitura das listas
lista1 = list(input().split())
lista2 = list(input().split())

# Verifica se todas os elementos das listas podem ser convertidos para inteiros
if all(item.isdigit() for item in lista1) and all(item.isdigit() for item in lista2):
    comuns = elementos_comuns(lista1, lista2)
    print(f"Elementos comuns às duas listas: {comuns}")
else:
    print("Entrada inválida.") 
"""

    # TODO: Crie uma função 'elementos_comuns' que receba duas listas de números inteiros separados por espaço:

def elementos_comuns(lista1, lista2):
  set1 = set(lista1)
  set2 = set(lista2)
  return list(set1.intersection(set2))

# Leitura das listas
lista1 = [4, 5, 6, 7, 8]
lista2 = [1, 2, 3, 4, 5]

# Verifica se todas os elementos das listas podem ser convertidos para inteiros
if all(item.is_integer for item in lista1) and all(item.is_integer for item in lista2):
    comuns = elementos_comuns(lista1, lista2)
    print(f"Elementos comuns às duas listas: {comuns}")
    
else:
    print("Entrada inválida.")