import java.util.*;
import java.io.*; 

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		int h, f, d;
		int day;
		double currentHeight = 0;
		double u;
		double fatigue = 0;

		h = scanner.nextInt(); // height of the well
		while(h != 0) {
			u = scanner.nextDouble(); // distance climbed during the day
			d = scanner.nextInt(); // distance slipped during the night
			f = scanner.nextInt(); // fatigue factor
			fatigue = (u * f) / 100;
			day = 0;
			currentHeight = 0;
			
			while(true) {
				++day;
				if(u > 0) currentHeight += u; // climb during the day
				u -= fatigue; // reduce climbing ability due to fatigue
				
				if(currentHeight > h) {
					System.out.println("success on day " + day);
					break;
				}
				
				currentHeight -= d; // slip during the night
				if(currentHeight < 0) {
					System.out.println("failure on day " + day);
					break;
				}
			}

			h = scanner.nextInt();
		}

		scanner.close();
	}
}
