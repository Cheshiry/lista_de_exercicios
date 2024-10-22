let estudante = {
    nome: "Miguel",
    idade: 21,
    curso: "Artes"
}

estudante.idade = 30;
estudante.semestre = "terceiro"

console.log(estudante)

let frutas = ["Açai", "Uva", "Mamão", "Abacate"]

frutas.push("Caqui")

frutas.shift()

// console.log(frutas.forEach(fruta => {
//     console.log(fruta).join(",")
// }))

frutas.join(", ")
console.log(frutas)

let novas = frutas.slice(1,3)
console.log(novas)

let num = [1,2,3,4]

let quadrado = num.map(quad =>
     quad * quad
)

console.log(quadrado)