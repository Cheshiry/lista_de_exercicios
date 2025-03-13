def somar(a, b):
    return a + b

def subtrair(a, b):
    return a - b

def exibir_result(a, b, funcao):
    resultado = funcao(a, b)
    print(resultado)

exibir_result(30, 20, somar)
exibir_result(30, 20, subtrair)

op = somar

print(op(1, 34))


salario = 2000

def salario_bonus(bonus):
    global salario
    salario += bonus
    return salario

print(salario_bonus(30))