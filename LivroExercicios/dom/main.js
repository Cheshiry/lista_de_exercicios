const first = document.getElementById("primeiro-paragrafo")
const second = document.getElementById("segundo-paragrafo")
const third = document.getElementById("terceiro-paragrafo")
const fourth = document.getElementById("quarto-paragrafo")
const last = document.getElementById("ultimo-paragrafo")
const btn = document.getElementById("btn")

first.innerHTML = ('test');
first.style.background = ('teal')

third.style.color = ('darkred')

last.onmouseover = function(){
    last.style.background = ('teal')
    last.style.color = ('aqua')
} 
last.onmouseleave = function(){
    last.style.background = ('white')
} 

second.textContent = ('oi');

btn.addEventListener('click', function(){
    alert('blue')
})
