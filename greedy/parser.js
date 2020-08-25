
import {Contest} from './contest.js'
import {Contestant} from './contestant.js'

export function parseContestants(numberOfContestants, rawData){
    const contestants = []
    for (let i=0; i<numberOfContestants; i++){
        let contestantDataRaw = rawData[i+1].split(" ")
        contestants.push(new Contestant(i+1, parseInt(contestantDataRaw[0]),parseInt(contestantDataRaw[1])))
    }
    // contestants.forEach(element => {
    //     element.output()
    // });
    return contestants
}

export function parseContests(numberOfContests, rawData, numberOfContestants){
    const contests = []
    for (let i=0; i<numberOfContests; i++){
        let contestDataRaw = rawData[i+1+numberOfContestants].split(" ")
        contests.push(new Contest(parseInt(contestDataRaw[0]),parseInt(contestDataRaw[1])))
    }
    // contests.forEach(element => {
    //     element.output()
    // });
    return contests
}

