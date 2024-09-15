const { gets, print } = require('./funcoesPar');

let maiorNumeroPar = null;
let menorNumeroImpar = null;
const n = gets();

for (let i = 0; i < n; i++) {
    const numero = gets();
    if (numero % 2 === 0) { //if encadeado um if dentro do outro
        if(maiorNumeroPar === null || numero > maiorNumeroPar){
            maiorNumeroPar = numero;
        
        }
    } else {
            if (menorNumeroImpar === null || numero < menorNumeroImpar) {
                menorNumeroImpar = numero;
            }
        }
}
print("é o maior numero par " + maiorNumeroPar);
print("é o menor numero impar " + menorNumeroImpar);