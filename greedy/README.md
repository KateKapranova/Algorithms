# Team Problem

## Input: 
First line: n number of contestants, c number of contests followed by n lines of contestants with a and s where a is age and s is skill. Afterwards come c lines of contests with minAge and maxAge of participants allowed.

## Output:
The optimal team of three for each contest. If no such a team exists, return -1.

## Optimise:
By skill and if skills are the same then by id. Id count begins from 1.

### Sample input:
3 2<br/>
20 3000<br/>
35 1800<br/>
68 2500<br/>
18 70<br/>
70 90<br/>

### Sample output:
1 3 2<br/>
-1 
