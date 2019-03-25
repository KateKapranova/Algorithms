//Java implementation of non-optimised bubbleSort
//average case and worst case: quadratic
//best case: n, better than most efficient sorting algorithms


import java.util.Arrays;
import java.util.Random;

public class bubbleSort{
	public static void main(String args[]) {
		int size = 10;
		int ar[]=new int[size];
		Random rand = new Random();
		
		
		for(int i=0;i<size;i++) {
			ar[i]=rand.nextInt(100);
		}
		
		System.out.println(Arrays.toString(ar));
		
		int dummy;
		boolean changed = true;
		int iteration=0;
				
		while (changed) {
			changed=false;
			iteration+=1;
			for (int i=0;i<(ar.length-1); i++) {
				if (ar[i+1]<ar[i]) {
					dummy=ar[i];
					ar[i]=ar[i+1];
					ar[i+1]=dummy;
					changed=true;
					
				}
				else {
					continue;
				}
			}
		}
		
		System.out.println("needed iterations: " + iteration);
		System.out.println(Arrays.toString(ar));
	}
	
}
