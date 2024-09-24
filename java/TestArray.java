
import java.util.Scanner;

public class TestArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] sim = new int[10];
        for(int i = 0; i <= 9 ; i++){
            sim[i] = scanner.nextInt();
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(sim[j] > sim[j+1]){
                    int temp = sim[j];
                    sim[j] = sim[j+1];
                    sim[j+1] = temp;
                }
            }
        }
        for(int num: sim){
            System.out.print(num + " ");
        }
    }
}
