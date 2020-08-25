// const fs = require('fs');
import fs from 'fs'


export function readInput(path){
    const text = fs.readFileSync(path, {encoding:'utf8', flag:'r'});
    const textByLine = text.split("\n")
    // console.log(textByLine)
    const firstLine = textByLine[0].split(" ")
    const numberOfContestants = parseInt(firstLine[0])
    const numberOfContests = parseInt(firstLine[1])
    // console.log(numberOfContestants,numberOfContests, textByLine)
    return [numberOfContestants,numberOfContests, textByLine]
}
