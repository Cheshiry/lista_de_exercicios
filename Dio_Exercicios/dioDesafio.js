let nome = "Gabriel";
let idade = 32;
let categoria = "Ninja";
let tipo = categoria.toLowerCase();

 class Heroi {
    constructor(nomeHeroi, idadeHeroi, tipo){
        this.nomeHeroi = nome;
        this.idadeHeroi = idade;
        this.tipo = tipo;
    }
} 

function ataque(tipo){
    
    let golpe = "";

    if (tipo =="guerreiro"){
        golpe = ("o guerreiro atacou usando espada!");
        return golpe;
    }
    else if (tipo == "mago"){
        golpe = ("o mago atacou usando magia!");
        return golpe;
    }
    else if (tipo == "monge"){
        golpe = ("o monge atacou usando artes marciais!");
        return golpe;
    }
    else if (tipo == "ninja"){
        golpe = ("ninja atacou usando shuriken!");
        return golpe;
    }else{
        golpe = ("Escolha uma categoria de Herói!!");
        return golpe;
    }

}

let heroi = new Heroi(nome, idade, tipo);

console.log(ataque(tipo))