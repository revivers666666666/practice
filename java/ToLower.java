import java.util.Scanner;
public class ToLower {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        char inputChar = scanner.next().charAt(0);
        inputChar = (char)(inputChar + 32);
        System.out.println(inputChar);
    }
}
