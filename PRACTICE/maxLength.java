package helloworld;

import java.util.Scanner;

public class HelloWorld {
	public static void main(String[] args) {
		String s;
		Scanner scanner = new Scanner(System.in);
		StringBuilder result = new StringBuilder();
		System.out.print("Nhap vao chuoi: ");
		s = scanner.nextLine();
		
		for(int i=0; i < s.length() / 2; ++i){
			
			if(s.charAt(i) == s.charAt(s.length() - i - 1)){
				result.append(s.charAt(i));
			}else {
				break;
			}
		}
		
		System.out.print(result.toString());
	}
}
