def exibir_poema(data_extenso, *lista, **dicionario):
    texto = "\n".join(lista)
    meta_dados = "\n".join([f"{chave.title()}: {valor}" for chave, valor in dicionario.items()])
    mensagem = f"{data_extenso}\n\n{texto}\n\n{meta_dados}"
    print(mensagem)

exibir_poema("sexta 26 de agosto 22",
              "Zen of Python",
             "Beautiful is better than ugly", 
             Author="Tim Peters", ano="1999",)