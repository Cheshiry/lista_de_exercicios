// let carro = {
//     marca: 'Ford',
//     modelo: 'KA',
//     ano: 2000,
//     ligar: function () {
//         console.log('Carro ligado!')
//     }
// }

// delete carro.cor;
// carro.ano = 2005;

// console.log(carro.cor)
// console.log(carro)

let frutas = ["Maçã","kiwi"];
let frutas2 = [ "Banana", "Uva"];

/* frutas.push("Abacate")

console.log(frutas)

frutas.pop()
console.log(frutas)

frutas.shift()
console.log(frutas)

frutas.unshift("Manga")
console.log(frutas)

frutas.splice(1,0,"Açai")
console.log(frutas)

let frutasTropicais = frutas.slice(0,2);
console.log(frutasTropicais)

let frutasString = frutas.join(", ")
console.log(frutasString)
 */

let todas = frutas.concat(frutas2);
/*
console.log(todas)
let string = todas.join(" - ")
console.log(string)

 let metade = todas.slice(0, 3)
console.log(metade) */

todas.forEach(fruta => {
    console.log(fruta);
});

let n = [1,2,3,4,5,6]
let quadrado = n.map(function (n){
    return n*n
})

console.log(quadrado)

let numeroPar = n.filter(function (num){
    return (num % 2 ===0);
})

console.log(numeroPar)