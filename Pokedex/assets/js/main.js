// const btnTeste = document.getElementById("btn")
// console.log("Testei!!");

// btnTeste.addEventListener("click",function(){
//     console.log("Clicou no botâo!");
// })

const offset = 0
const limit = 10
const url = `https://pokeapi.co/api/v2/pokemon?offset=${offset}&limit=${limit}`


fetch(url)
    .then((response) => response.json())
    .then (() => )
    .then((jsonBody) => console.log(jsonBody))
    debugger
    .catch((error) => console.error(error))
