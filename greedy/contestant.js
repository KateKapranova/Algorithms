export class Contestant {
    constructor(id, age, skill){
        this.id = id
        this.age = age
        this.skill = skill
    }
    output(){
        console.log(this.id, this.age, this.skill)
    }
    
}

// module.exports = Contestant