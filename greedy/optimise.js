export function optimise(contests, contestants,numberOfContests,numberOfContestants){
    for (let i=0; i<numberOfContests; i++){
        let currentContest = contests[i]
        for (let j=0; j<numberOfContestants; j++){
            let currentContestant = contestants[j]
            if (currentContestant.age <= currentContest.maxAge && currentContestant.age >= currentContest.minAge){
                currentContest.addContestant(currentContestant)
                if (currentContest.isComlete){
                    let [team1,team2,team3] = currentContest.yieldTeam()
                    console.log(team1,team2,team3)
                    break
                }
            }
        }
        if (!currentContest.isComlete){
            console.log(-1)
        }
    }
}