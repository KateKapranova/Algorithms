import java.util.Arrays;
import java.util.Random;

//implementation of comb sort which is an optimised version of bubble sort
//bubble sort compares two elements which are adjacent, which means that a gap bw two elements is 1
//comb sort looks at bigger gaps and iteratively changes the gap by shrink factor k
//in such a way turtles are eliminated early on (smaller elements which are positioned at the end of the list)

public class combSort {
	public static void main(String [] args) {
		int listSize = 10;
		int ar[]=new int[listSize];
		Random rand = new Random();
		
		for(int i=0;i<ar.length;i++) {
			ar[i]=rand.nextInt(100);
		}
		
		System.out.println(Arrays.toString(ar));
		
		boolean changed=true;
		int gap=ar.length;
		double shrink = 1.3;
		int dummy;
		
		while(changed) {
			gap=(int) Math.floor(gap/shrink);
			if (gap <= 1) {
				gap=1;
				changed=false;
			}
			int k=0;
			while(gap+k<ar.length) {
				if(ar[k]>ar[gap+k]) {
					dummy=ar[k];
					ar[k]=ar[gap+k];
					ar[gap+k]=dummy;
				}
				k+=1;				
			}
		}
		
		System.out.println(Arrays.toString(ar));
		
	}		
}
