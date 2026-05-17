const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

function isUpperCase(char) {
    return char === char.toUpperCase() && char !== char.toLowerCase();
}

function isLowerCase(char) {
    return char === char.toLowerCase() && char !== char.toUpperCase();
}

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    const result = [...str]
        .map(c => {
            const lower = c.toLowerCase();
            return c === lower ? c.toUpperCase() : lower;
        })
        .join('');
    console.log(result);
});