import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int T = 0;
        T = scanner.nextInt();

        int[] x1,y1,r1,x2,y2,r2,count;
        x1 = new int[T];
        y1 = new int[T];
        r1 = new int[T];
        x2 = new int[T];
        y2 = new int[T];
        r2 = new int[T];
        count = new int[T];

        for(int i = 0; i < T; i++){
            x1[i] = scanner.nextInt();
            y1[i] = scanner.nextInt();
            r1[i] = scanner.nextInt();
            x2[i] = scanner.nextInt();
            y2[i] = scanner.nextInt();
            r2[i] = scanner.nextInt();
        }

        int p = 0;
        int q = 0;
        long temp = 0;
        for(int i = 0; i < T; i++){

            if((x1[i] == x2[i]) && (y1[i] == y2[i])){
                if(r2[i] == r1[i]){
                    count[i] = -1;
                }else{
                    count[i] = 0;
                }
            }else if(x1[i] == x2[i] && (y1[i] != y2[i])){
                q = ((y1[i] + y2[i])*(y1[i] - y2[i]) + (r2[i] + r1[i])*(r2[i]-r1[i])) / ( 2*(y1[i]-y2[i]));
                temp = (-2*x1[i]) * (-2*x1[i]) - 4*(x1[i]*x1[i] + q*q - 2*q*y1[i] + y1[i]*y1[i] - r1[i]*r1[i]);
                if(temp > 0){
                    count[i] = 2;
                }else if(temp == 0){
                    count[i] = 1;
                }else{
                    count[i] = 0;
                }
            }else if(x1[i] != x2[i] && (y1[i] == y2[i])){
                p = ((x1[i] + x2[i])*(x1[i] - x2[i]) + (r2[i] + r1[i])*(r2[i] - r1[i])) / (2*(x1[i]-x2[i]));
                temp = (-2*y1[i]) * (-2*y1[i]) -4*(y1[i]*y1[i] + p*p -2*x1[i]*p + x1[i]*x1[i] - r1[i]*r1[i]);
                if(temp > 0){
                    count[i] = 2;
                }else if(temp == 0){
                    count[i] = 1;
                }else{
                    count[i] = 0;
                }
            }else{
                count[i] = 2;
            }
        }

        for(int i= 0; i < T; i++){
            System.out.println(count[i]);
        }
    }
}
