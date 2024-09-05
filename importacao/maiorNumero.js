const {gets, print} = require('./funcoes03');

let maiorValorEncontrado = 0;
const quantida = gets();
const menor = 0;

for (let i = 0; i <= quantida; i++) {
    const numeroSorteado = gets();
    if (numeroSorteado > maiorValorEncontrado) {
        maiorValorEncontrado = numeroSorteado;
    }else if((numeroSorteado < menor) && (numeroSorteado !== 0)){
      menor = numeroSorteado;
    }
  }
    

print(maiorValorEncontrado)
print(menor)
/*
for (let i = 0; i < numeros; i++) {
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
*/