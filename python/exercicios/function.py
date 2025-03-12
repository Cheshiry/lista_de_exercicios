def soma(n1, n2):
    soma = n1 + n2
    return soma

def retorna_antecesor_e_sucessor(num):
    antecessor = num - 1
    sucessor = num + 1

    return antecessor, sucessor


def exibir_mensagem():
    print("Hi")
 
def exibir_mensagem2(nome):
    print(f"Seja bem vindo {nome}")

def exibir_mensagem3(nome="Anônimo"):
    print(f"Seja bem vindo {nome}")

print(soma(8, 5))
exibir_mensagem()
exibir_mensagem2(nome="Ana")
exibir_mensagem3()

print(retorna_antecesor_e_sucessor(19))


def salvar_carr0(marca, modelo, ano, placa):
    print(f"Carro inserido com sucesso! {marca}/{modelo}/{ano}/{placa}")

salvar_carr0("Fiat","Palio", 1999, "ABC-1234")    
salvar_carr0(marca="Fiat", modelo="Palio", ano=1999, placa="ABC-1234")    
salvar_carr0(**{"marca":"Fiat", "modelo":"Palio", "ano":1999, "placa":"ABC-1234"})