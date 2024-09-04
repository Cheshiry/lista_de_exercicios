const {gets, print} = require('./funcoes03);

let entrada = 0;
const numeros = gets();
const maior = 0;
const menor =0;

for (let i = 0; i < entrada; i++) {
    const numeroInserido = gets();
    if (numeroInserido > maior) {
        maior = numeroInserido;
    }
    else if(numeroInserido < menor){
      menor = numeroInserido;
    }
}

print(menor)
print(maior)
