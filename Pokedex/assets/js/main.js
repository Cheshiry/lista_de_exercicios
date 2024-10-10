// const btnTeste = document.getElementById("btn")
// console.log("Testei!!");

// btnTeste.addEventListener("click",function(){
//     console.log("Clicou no botâo!");
// })

const offset = 0
const limit = 10
const url = `https://pokeapi.co/api/v2/pokemon?offset=${offset}&limit=${limit}`

function convertPokemonToHtml(pokemon){
    return `<ol class="pokemons">
                <li class="pokemon">
                    <span class="number">#001</span>
                    <span class="name">${pokemon.name}</span>
                    <div class="detail">
                        <ol class="types">
                            <li class="type">Grass</li>
                            <li class="type">Poison</li>
                        </ol>
                        <img src="./images/bulbasaur.jpg" alt="${pokemon.name}">
                    </div>
                </li>
            </ol>`
}

const pokemonList = document.getElementById('pokemonList')

fetch(url)
.then((response) => response.json())
.then((jsonBody) => jsonBody.results)
.then ((pokemons) => {
    for (let i = 0; i < pokemonList.length; i++) {
        const pokemon = pokemons[i];
        console.log
        pokemonList.innerHTML += (convertPokemonToHtml(pokemon))
            
        }
    })
    
    .catch((error) => console.error(error))
