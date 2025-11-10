import java.util.*;
public class FindMinMax {
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int n = s1.nextInt();
        int[] arr = new int[n];

        for(int i =0 ; i< n ;i++){
            arr[i] = s1.nextInt();
        }

        Arrays.sort(arr);
        System.out.println("The Smallest element in the array is "+ arr[0]);
        System.out.println("The largest element in the array is "+ arr[n-1]);
    }
}

