import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;

public class SortNames {
    public static void main(String[] args) {
        String[] nameArray = {"Alice", "Charlie", "Bob", "David"};
        System.out.println("Original String array: " + Arrays.toString(nameArray));
        Arrays.sort(nameArray);
        System.out.println("Sorted String array (alphabetical): " + Arrays.toString(nameArray));

        ArrayList<String> nameList = new ArrayList<>();
        nameList.add("Zoe");
        nameList.add("Yara");
        nameList.add("Xavier");
        nameList.add("Walter");
        System.out.println("\nOriginal Name List: " + nameList);
        Collections.sort(nameList);
        System.out.println("Sorted Name List (alphabetical): " + nameList);
    }
}

