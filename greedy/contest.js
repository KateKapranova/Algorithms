export class Contest {
    
    constructor(minAge, maxAge){
        this.minAge = minAge
        this.maxAge = maxAge
        this.bestTeam = []
        this.isComlete = false
    }

    addContestant(contestant){
        if (!this.isComlete){
            this.bestTeam.push(contestant)
            if (this.bestTeam.length==3){
                this.isComlete=true
            }
        }
        
    }

    yieldTeam(){
        if (this.bestTeam.length < 3){
            return -1
        }
        return [this.bestTeam[0].id, this.bestTeam[1].id, this.bestTeam[2].id]
    }

    output(){
        console.log(this.minAge, this.maxAge)
    }
}

// module.exports = Contest