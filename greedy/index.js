import {readInput} from './inputReader.js';
import {parseContestants, parseContests} from './parser.js'
import { optimise } from './optimise.js';
const path = './input2.txt'

function main(){

    const [numberOfContestants, numberOfContests, rawData] = readInput(path)
    const contestants = parseContestants(numberOfContestants,rawData)
    const contests = parseContests(numberOfContests,rawData,numberOfContestants)

    //sort contestants first by skill and then by id
    contestants.sort(function(a,b){
        return b.skill - a.skill || a.id - b.id
    })

    // console.log(contestants)
    
    //go through contests and look for team members
    //output the result immediately
    optimise(contests, contestants,numberOfContests,numberOfContestants)
}

main()