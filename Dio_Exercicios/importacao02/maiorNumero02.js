//nao esta completo

const { gets, print } = require('./funcoes03');

const array = gets();
let menorNumero = array[0]; // Inicializa com o primeiro elemento do array

for (let i = 1; i < array.length; i++) { // Começa do segundo elemento
    if (array[i] < menorNumero) {
        menorNumero = array[i];
    }
}

print(menorNumero);

