package helloworld;

import java.util.Scanner;

public class HelloWorld {
	public static void main(String[] args) {
		String s;
		Scanner scanner = new Scanner(System.in);
		s = scanner.nextLine();
		
		StringBuilder result = new StringBuilder(s);
		StringBuilder resultReverse = new StringBuilder(s);
		resultReverse.reverse();
		
		if(resultReverse.toString().equals(result.toString())) {
			System.out.print("PalindMore");
		}else {
			System.out.print("Not a PalindMore");
		}
	}
}
